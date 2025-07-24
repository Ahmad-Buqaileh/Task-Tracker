#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"

class TaskManager
{
private:
    Task **tasks;
    int taskCount;
    int size;

public:
    TaskManager();
    ~TaskManager();

    void addTask(const std::string &taskname, const std::string &dueDate);
    void deleteTask(int taskIdToFind);
    void markAsDone(int taskIdToFind);
    void updateTask(int taskIdToFind, std::string &newTaskName);
    void resize();
    int generateId();

    void displayTasks() const;
    void displayFinishedTasks() const;

    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
};

#endif // TASK_MANAGER_H