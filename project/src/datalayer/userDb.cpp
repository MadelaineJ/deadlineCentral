#include "userDb.hpp"

UserDB* UserDB::instance = nullptr;

UserDB* UserDB::getInstance(){
   if(instance == nullptr) {
      instance = new UserDB();
   }
   return instance;
}

UserDB::UserDB(){}
UserDB::~UserDB(){}

bool UserDB::createUser(Student user){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   string query = "INSERT INTO Students (studentID, name, email, password) VALUES ("
      + to_string(user.getStudentId()) + ", '"
      + user.getName() + "', '"
      + user.getEmail() + "', '"
      + user.getPassword() + "')";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::createUser(Instructor user){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   string query = "INSERT INTO Instructors (instructorID, name, email, password) VALUES ("
      + to_string(user.getInstructorId()) + ", '"
      + user.getName() + "', '"
      + user.getEmail() + "', '"
      + user.getPassword() + "')";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::updateUser(User U, string userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "UPDATE Students SET name = '" + U.getName() + "', "
         + "email = '" + U.getEmail() + "', "
         + "password = '" + U.getPassword() + "' "
         + "WHERE studentID = " + userID;
   } 
   else{
      query = "UPDATE Instructors SET name = '" + U.getName() + "', "
         + "email = '" + U.getEmail() + "', "
         + "password = '" + U.getPassword() + "' "
         + "WHERE instructorID = " + userID;
   }
   
   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::deleteUser(string userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "DELETE FROM Students WHERE studentID = " + userID;
   }
   else{
      query = "DELETE FROM Instructors WHERE instructorID = " + userID;
   }

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool UserDB::isStudent(string userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "SELECT studentID FROM Students WHERE studentID = " + userID;
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   return rs->next();
}

//TODO add tasklist to returned object
User UserDB::getUserInfo(string userID){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "";
   if(isStudent(userID)){
      query = "SELECT studentID, name, email, password FROM Students WHERE studentID = " + userID;
   }
   else{
      query = "SELECT instructorID, name, email, password FROM Instructors WHERE instructorID = " + userID;
   }
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   list<int> taskList;
   User user("", "", "", taskList);
   if(rs->next()){
      //user.setId(rs->getInt(1));
      user.setName(rs->getString(2));
      user.setEmail(rs->getString(3));
      user.setPassword(rs->getString(4));
   }
   controllerDB->disconnect();
   return user;
}

