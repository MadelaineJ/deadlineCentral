#include "userDb.hpp"

#include <sstream>

UserDB* UserDB::instance = nullptr;

UserDB* UserDB::getInstance(){
   if(instance == nullptr) {
      instance = new UserDB();
   }
   return instance;
}

UserDB::UserDB(){}
UserDB::~UserDB(){}

int UserDB::createUser(Student user) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "INSERT INTO Students (name, email, password) "
                 << "VALUES (:1, :2, :3) "
                 << "RETURNING studentId INTO :4 ";

    string query = queryBuilder.str();
    Statement* stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setString(1, user.getName());
    stmt->setString(2, user.getEmail());
    stmt->setString(3, user.getPassword());
    stmt->registerOutParam(4, OCCIINT);  // Register the return generated ID

   stmt->executeUpdate();
   
   int gen_courseID = -1; //initialize to centinal value

   // Retrieve the auto-generated ID
   gen_courseID = stmt->getInt(4);

   // Commit the transaction or changes will revert after connection is closed
   controllerDB->getConnection()->commit();

   controllerDB->disconnect();

   return gen_courseID;
}


int UserDB::createUser(Instructor user) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "INSERT INTO Instructors (name, email, password) "
                 << "VALUES (:1, :2, :3) "
                 << "RETURNING instructorID INTO :4 ";

    string query = queryBuilder.str();
    Statement* stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setString(1, user.getName());
    stmt->setString(2, user.getEmail());
    stmt->setString(3, user.getPassword());
    stmt->registerOutParam(4, OCCIINT);  // Register the return generated ID

   stmt->executeUpdate();
   
   int gen_courseID = -1; //initialize to centinal value

   // Retrieve the auto-generated ID
   gen_courseID = stmt->getInt(4);

   // Commit the transaction or changes will revert after connection is closed
   controllerDB->getConnection()->commit();

   controllerDB->disconnect();

   return gen_courseID;
}


bool UserDB::updateUser(User U, int userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "UPDATE Students SET name = '" + U.getName() + "', "
         + "email = '" + U.getEmail() + "', "
         + "password = '" + U.getPassword() + "' "
         + "WHERE studentID = " + to_string(userID);
   } 
   else{
      query = "UPDATE Instructors SET name = '" + U.getName() + "', "
         + "email = '" + U.getEmail() + "', "
         + "password = '" + U.getPassword() + "' "
         + "WHERE instructorID = " + to_string(userID);
   }
   
   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::deleteUser(int userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "DELETE FROM Students WHERE studentID = " + to_string(userID);
   }
   else{
      query = "DELETE FROM Instructors WHERE instructorID = " + to_string(userID);
   }

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::isStudent(int userID){
   return userID < 1000;
}

list<int> UserDB::getTaskList(int userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   list<int> taskList;
   string query = "";
   if(isStudent(userID)){
      query = "SELECT taskID FROM Tasks WHERE studentID = " + to_string(userID);
   }
   else{
      query = "SELECT taskID FROM Tasks WHERE instructorID = " + to_string(userID);
   }
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   while(rs->next()){
      taskList.push_back(rs->getInt(1));
   }
   controllerDB->disconnect();
   return taskList;
}

User UserDB::getUserInfoById(int userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "SELECT studentID, name, email, password FROM Students WHERE studentID = " + to_string(userID);
   }
   else{
      query = "SELECT instructorID, name, email, password FROM Instructors WHERE instructorID = " + to_string(userID);
   }
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   list<int> taskList;
   User user(userID, "", "", "", taskList);
   if(rs->next()){
      user.setUserId(rs->getInt(1));
      user.setName(rs->getString(2));
      user.setEmail(rs->getString(3));
      user.setPassword(rs->getString(4));
   }
   controllerDB->disconnect();
   user.setTaskList(this->getTaskList(userID));
   return user;
}
// getting user info was written by chatGPT 3.5 using the following prompt:
/*
I'm trying to write a sql query that gets user information based on the email address. 
I have 2 user types, student and instructor. I have no way of knowing in the code if the 
email I got belongs ot instructor or student, but it will be unique between the two. 
Could you write a sql query that returns the right user information?
<getUserInfoByID implementation>
*/
User UserDB::getUserInfoByEmail(string email){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "SELECT userId, name, email, password "
               "FROM ( "
               "SELECT studentID AS userId, name, email, password "
               "FROM Students "
               "WHERE email = '" + email + "' "

               "UNION ALL "

               "SELECT instructorID AS userId, name, email, password "
               "FROM Instructors "
               "WHERE email = '" + email + "' "
               ") user_info "
               "WHERE ROWNUM <= 1";
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   list<int> taskList;
   User user(-1, "", "", "", taskList);
   if(rs->next()){
      user.setUserId(rs->getInt(1));
      user.setName(rs->getString(2));
      user.setEmail(rs->getString(3));
      user.setPassword(rs->getString(4));
   }
   controllerDB->disconnect();
   return user;
}

