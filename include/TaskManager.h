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

    void addTask(const std::string &taskname, bool isDone);
    void deleteTask(int taskId);
    void markAsDone(int taskId);
    void updateTask(int taskId, const std::string &newTaskName);
    void resize();

    void displayTasks() const;
    void displayFinishedTasks() const;

    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
};

#endif // TASK_MANAGER_H