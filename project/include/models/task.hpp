#ifndef TASK_H
#define TASK_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


using namespace std;

// enum Type {
//     assignment = 1,
//     quiz = 2,
//     test = 3,
//     participation = 4,
//     personal = 10
// };

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