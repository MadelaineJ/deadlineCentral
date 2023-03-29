#ifndef TASK_H
#define TASK_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


using namespace std;


class Task 
{
    public:
        Task(int taskId, string name, int type, int owner, string description, string dueDate, bool isCompleted, float weight);
        ~Task();
        
        string getTaskName();
        void setTaskName(string name);
        
        int getTaskType();
        void setTaskType(int type);

        int getTaskOwner();
        void setTaskOwner(int owner);

        string getTaskDescription();
        void setTaskDescription(string description);

        string getDueDate();
        void setDueDate(string dueDate);

        bool getCompletionStatus();
        void setCompletionStatus(bool isCompleted);

        float getWeight();
        void setWeight(float weight);

        int getTaskId();
        void setTaskId(int taskId);

        void printTaskInfo();

        bool compare(Task otherTask);

        string getTypeName(); // returns the type as a string
        

        friend std::ostream& operator<< (std::ostream& out, const Task& t); // allows us to use std::cout << <TASK-OBJECT>

    private:
        int taskId;
        string name;
        int type;
        int owner;
        string description;
        string dueDate;
        bool isCompleted;
        float weight;

};

#endif 