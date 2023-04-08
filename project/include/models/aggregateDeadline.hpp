#ifndef AGGREGATEDEADLINE_H
#define AGGREGATEDEADLINE_H

// required libraries
#include <string>

struct AggregateDeadline {
    int type;
    string dueDate;
    string courseName;
    int affectedStudents;
};

#endif