#ifndef CONTROLLER_DB_TEST_H
#define CONTROLLER_DB_TEST_H

Task createFakeTask(int taskType, int ownerId);
void deleteFakeTasks(TaskDB* taskDb, std::list<Task>& fakeTasks);

#endif // CONTROLLER_DB_H