//Included custom header files
#include "courseDb.hpp"
#include "course.hpp"
#include "instructor.hpp"
#include "controllerDb.hpp"


CourseDB* CourseDB::instance = nullptr; // initialize pointer

// returns a pointer to the single instance of CourseDB, if there is no instance it creates a new one
CourseDB* CourseDB::getInstance()   {
   if(instance == nullptr) {
      instance = new CourseDB();
   }
   return instance;
}

CourseDB::CourseDB() {}
CourseDB::~CourseDB() {}

int CourseDB::createCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   stringstream queryBuilder;
   queryBuilder << "INSERT INTO Courses (courseCode, courseName, calendarDescription, instructorID) "
                << "VALUES (:1, :2, :3, :4) "
                << "RETURNING courseID INTO :5 ";

   string query = queryBuilder.str();
   Statement *stmt = controllerDB->getConnection()->createStatement(query);

   stmt->setString(1, C.getCourseCode());
   stmt->setString(2, C.getCourseName());
   stmt->setString(3, C.getCalendarDescription());
   stmt->setInt(4, C.getInstructorId());
   stmt->registerOutParam(5, OCCIINT);  // Register the return generated ID

   stmt->executeUpdate();
   
   int gen_courseID = -1; //initialize to centinal value

   // Retrieve the auto-generated ID
   gen_courseID = stmt->getInt(5);

   // Commit the transaction or changes will revert after connection is closed
   controllerDB->getConnection()->commit();

   controllerDB->disconnect();

   return gen_courseID;
}

bool CourseDB::updateCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   stringstream queryBuilder;
   queryBuilder << "UPDATE Courses "
                << "SET "
                << "courseCode = :1, "
                << "courseName = :2, "
                << "calendarDescription = :3, "
                << "instructorID = :4 "
                << "WHERE courseID = :5";

   string query = queryBuilder.str();
   Statement *stmt = controllerDB->getConnection()->createStatement(query);

   stmt->setString(1, C.getCourseCode());
   stmt->setString(2, C.getCourseName());
   stmt->setString(3, C.getCalendarDescription());
   stmt->setInt(4, C.getInstructorId());
   stmt->setInt(5, C.getCourseId());

   int rowCount = stmt->executeUpdate();

   // Commit the transaction or changes will revert after connection is closed
   controllerDB->getConnection()->commit();
   
   controllerDB->disconnect();
   
   if(rowCount == 1){
      return true;
   }
   return false;
}

bool CourseDB::deleteCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();  

   stringstream queryBuilder;
   queryBuilder << "DELETE FROM Courses "
                << "WHERE courseID = :1 ";
   
   string query = queryBuilder.str();
   Statement *stmt = controllerDB->getConnection()->createStatement(query);

   stmt->setInt(1, C.getCourseId());

   int rowCount = stmt->executeUpdate();

   // Commit the transaction or changes will revert after connection is closed
   controllerDB->getConnection()->commit();

   controllerDB->disconnect();

   if(rowCount == 1){
      return true;
   }
   return false;
}

// TODO what is this used for? do we need student ids?
list<Student> CourseDB::getEnrollmentList(int courseID){
   // query DB table StudentCourses using courseID to get all students subscribed to courseID
   ControllerDb *controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   stringstream queryBuilder;
   queryBuilder << "SELECT name "
                << "FROM Students s "
                << "JOIN StudentCourses sc ON s.studentID = sc.studentID "
                << "WHERE sc.courseID = :1 ";

   string query = queryBuilder.str();
   Statement *stmt = controllerDB->getConnection()->createStatement(query);

   stmt->setInt(1, courseID);

   ResultSet *rs = stmt->executeQuery();

   list<Student> enrolledStudents = {};
   while(rs->next()){
      Student stu(-1, "", "", "", {});
      stu.setName(rs->getString(1));

      enrolledStudents.push_back(stu);
   }
   return enrolledStudents;
}

Course CourseDB::getCourseInfo(int courseID){
   ControllerDb *controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   stringstream queryBuilder;
   queryBuilder << "SELECT courseID, instructorID, courseName, courseCode, calendarDescription "
                << "FROM Courses "
                << "WHERE courseID = :1 ";

   string query = queryBuilder.str();
   Statement *stmt = controllerDB->getConnection()->createStatement(query);

   stmt->setInt(1, courseID);

   ResultSet *rs = stmt->executeQuery();

   Course course(0,0,"0", "0", "0");
   if(rs->next()){
      course.setCourseId(rs->getInt(1));
      course.setInstructorId(rs->getInt(2));
      course.setCourseName(rs->getString(3));
      course.setCourseCode(rs->getString(4));
      course.setCalendarDescription(rs->getString(5));
   }

   return course;
}

// gets a list of all conflicting course deadlines for students that are in COURSEID for the given DATE (returns all conflicts if no date or invalid date provided)
list<AggregateDeadline> CourseDB::aggregateDeadlines(int courseID, string date){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   bool validDate = false;
   // ensure that only a valid date format is passed into query MM/DD/YYYY
   std::regex dateRegex("^(0[1-9]|1[0-2])/([0-2][0-9]|3[0-1])/\\d{4}$");
   if(regex_match(date, dateRegex)) {
      validDate = true;
   }

   stringstream queryBuilder;
   queryBuilder << "SELECT t.type, t.dueDate, c.courseName, COUNT(DISTINCT sc.studentID) "
                << "FROM Tasks t "
                << "JOIN StudentCourses sc ON t.courseID = sc.courseID "
                << "JOIN Courses c ON t.courseID = c.courseID "
                << "WHERE t.dueDate IN ( "
                << "SELECT t2.dueDate "
                << "FROM Tasks t2 "
                << "JOIN StudentCourses sc2 ON t2.courseID = sc2.courseID "
                << "WHERE t2.courseID = :thisCourse "
                << "AND sc2.studentID = sc.studentID "
                << ") "
                << "AND t.courseID != :thisCourse "
                << "AND sc.studentID IN ( "
                << "SELECT sc3.studentID "
                << "FROM StudentCourses sc3 "
                << "WHERE sc3.courseID = :thisCourse "
                << ") ";

   // only bind if we have a valid date
   if(validDate) {
      queryBuilder << "AND t.dueDate = TO_DATE(:4, 'MM/DD/YYYY') ";
   }
   
   queryBuilder << "GROUP BY t.type, t.dueDate, c.courseName ";
   
   string query = queryBuilder.str();

   // prepare statement
   Statement *stmt = controllerDB->getConnection()->createStatement(query);
   stmt->setInt(1, courseID);
   stmt->setInt(2, courseID);
   stmt->setInt(3, courseID);

   // only bind if we have a valid date
   if(validDate){
      stmt->setString(4, date);
   }

   list<AggregateDeadline> aggregateDeadlineResults = {};

   // get results
   ResultSet *rs = stmt->executeQuery();

   if(rs->next()) {
   int type = rs->getInt(1); // task type
   string date = rs->getString(2); // due date
   string course = rs->getString(3); // course name
   int num = rs->getInt(4); // affected students

   AggregateDeadline ag; // create a new struct for each result row
      ag.type = type;
      ag.courseName = course;
      ag.dueDate = date;
      ag.affectedStudents = num;

      aggregateDeadlineResults.push_back(ag);
   }
   controllerDB->disconnect();
   return aggregateDeadlineResults; // can be empty if result set was false
}

// helper functions
int CourseDB::getCourseID(std::string courseCode, std::string instructorName) {
    // query DB table Courses using courseCode & instructor name to find courseID
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "SELECT c.courseID "
                 << "FROM Courses c "
                 << "JOIN Instructors i ON i.instructorID = c.instructorID "
                 << "WHERE c.courseCode = :1 "
                 << "AND i.name = :2";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setString(1, courseCode);
    stmt->setString(2, instructorName);

    ResultSet *rs = stmt->executeQuery();
    int courseID = -1;
    if(rs->next()){
        courseID = rs->getInt(1);
    }
    controllerDB->disconnect();
    return courseID; // -1 if no matches in DB
}
