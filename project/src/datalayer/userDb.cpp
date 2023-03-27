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
   this->controllerDb.connect();

   string query = "INSERT INTO Students (studentID, name, email, password)"
      + to_string(user.getStudentId()) + ", "
      + user.getName() + ", "
      + user.getEmail() + ", "
      + user.getPassword() + ", ";

   int rowCount = this->controllerDb.getStatement()->executeUpdate(query);
   this->controllerDb.disconnect();
   return rowCount;
}

bool UserDB::createUser(Instructor user){
   this->controllerDb.connect();

   string query = "INSERT INTO Instructors (instructorID, name, email, password)"
      + to_string(user.getInstructorId()) + ", "
      + user.getName() + ", "
      + user.getEmail() + ", "
      + user.getPassword() + ", ";

   int rowCount = this->controllerDb.getStatement()->executeUpdate(query);
   this->controllerDb.disconnect();
   return rowCount;
}

bool UserDB::updateUser(User U){
   return 0;
}

bool UserDB::deleteUser(User U){
   return 0;
}

bool UserDB::isStudent(string userID){
   this->controllerDb.connect();
   string query = "SELECT studentID FROM Student WHERE studentID = " + userID;
   ResultSet *rs = this->controllerDb.getStatement()->executeQuery(query);
   return rs->next();
}

//TODO add tasklist to returned object
User UserDB::getUserInfo(string userID){
   this->controllerDb.connect();
   string query = "";
   if(isStudent(userID)){
      string query = "SELECT studentID, name, email, password FROM Students WHERE studentID = " + userID;
   }
   else{
      string query = "SELECT instructorID, name, email, password FROM Instructors WHERE instructorID = " + userID;
   }
   ResultSet *rs = this->controllerDb.getStatement()->executeQuery(query);
   List<int> taskList;
   User user("", "", "", taskList);
   if(rs->next()){
      //task.setId(rs->getInt(1));
      task.setName(rs->getString(2));
      task.setEmail(rs->getString(3));
      task.setPassword(rs->getString(4));
   }
   this->controllerDb.disconnect();
   return user;
}

