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
   controllerDB->getConnection()->commit();
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
   controllerDB->getConnection()->commit();
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
   bool result = rs->next();
   controllerDB->disconnect();
   return result;
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

//TODO add tasklist to returned object
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
      user.setName(rs->getString(1));
      user.setEmail(rs->getString(2));
      user.setPassword(rs->getString(3));
      user.setTaskList(this->getTaskList(userID));
   }
   controllerDB->disconnect();
   return user;
}
// getting user info was written by chat gpt using the following prompt:
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

