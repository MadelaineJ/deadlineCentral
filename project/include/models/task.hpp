#ifndef TASK_H
#define TASK_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>




using namespace std;

enum type {
    assignment,
    personal,
    quiz,
    test
};

class Task 
{
    public:
        Task(string name, enum type, int owner, string description, time_t dueDate, bool isCompleted, float weight);
        ~Task();
        
        string getTaskName();
        void setTaskName(string name);
        
        string getTaskType();
        void setTaskType(enum type);

        int getTaskOwner();
        void setTaskOwner(int owner);

        string getTaskDescription();
        void setTaskDescription(string description);

        time_t getDueDate();
        void setDueDate(time_t dueDate);

        bool getCompletionStatus();
        void setCompletionStatus(bool isCompleted);

        float getWeight();
        void setWeight(float weight);


    private:
        string name;
        string type;
        int owner;
        string description;
        time_t dueDate;
        bool isCompleted;
        float weight;

};

#endif 