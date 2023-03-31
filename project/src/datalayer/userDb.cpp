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

   string query = "INSERT INTO Students (name, email, password) VALUES ('"
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

   string query = "INSERT INTO Instructors (name, email, password) VALUES ('"
      + user.getName() + "', '"
      + user.getEmail() + "', '"
      + user.getPassword() + "')";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
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
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();
   string query = "SELECT studentID FROM Students WHERE studentID = " + to_string(userID);
   ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
   return rs->next();
}

//TODO add tasklist to returned object
User UserDB::getUserInfo(int userID){
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
      //user.setId(rs->getInt(1));
      user.setName(rs->getString(2));
      user.setEmail(rs->getString(3));
      user.setPassword(rs->getString(4));
   }
   controllerDB->disconnect();
   return user;
}

