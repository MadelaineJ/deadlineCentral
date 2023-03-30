#ifndef AGGREGATEDEADLINE_H
#define AGGREGATEDEADLINE_H

#include <string>

struct AggregateDeadline {
    int type;
    string dueDate;
    string courseName;
    int affectedStudents;
};

#endif