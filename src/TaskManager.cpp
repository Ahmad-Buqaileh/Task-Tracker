#include <string>
#include <iostream>

#include "TaskManager.h"
#include "Task.h"
#include "Time.h"
#include "Json.h"

Task::Task(int taskId, std::string taskName, std::string dueDate, std::string updatedDate, bool isDone)
    : taskId(taskId), taskName(taskName), dueDate(dueDate), updatedDate(updatedDate), isDone(isDone) {}

static int lastId = 0;

std::ostream &operator<<(std::ostream &COUT, Task &task)
{
    COUT << "Task ID : " << task.getTaskId() << std::endl;
    COUT << "Task Name : " << task.getTaskName() << std::endl;
    COUT << "Task Due Date : " << task.getDueDate() << std::endl;
    COUT << "Task is Done : " << (task.getIsDone() ? "[X]" : "[ ]") << std::endl;
    COUT << "Task last updated : " << task.getUpdatedDate() << std::endl;
    COUT << "---------------------------------------------------------------------------\n";
    return COUT;
}

TaskManager::TaskManager()
{
    size = 5;
    taskCount = 0;
    tasks = new Task *[size];

    for (int i = 0; i < size; i++)
    {
        tasks[i] = nullptr;
    }

    loadFromFile("Tasks.json");
}

TaskManager::~TaskManager()
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr)
        {
            delete tasks[i];
            tasks[i] = nullptr;
        }
    }

    delete[] tasks;
    tasks = nullptr;
    taskCount = 0;
    size = 0;
}

int TaskManager::generateId()
{
    return ++lastId;
}

void TaskManager::resize()
{
    int newSize = size + 5;
    Task **newTasks = new Task *[newSize];

    for (int i = 0; i < size; i++)
    {
        newTasks[i] = tasks[i];
    }

    for (int i = size; i < newSize; i++)
    {
        newTasks[i] = nullptr;
    }

    delete[] tasks;
    tasks = newTasks;
    size = newSize;
}

void TaskManager::addTask(const std::string &taskname, const std::string &dueDate)
{
    if (size != taskCount)
    {
        tasks[taskCount] = new Task(generateId(), taskname, dueDate, "", false);
        taskCount++;
        saveToFile("Tasks.json");
    }
    else
    {
        resize();
        addTask(taskname, dueDate);
    }
}

void TaskManager::deleteTask(int taskIdToFind)
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr && tasks[i]->getTaskId() == taskIdToFind)
        {
            delete tasks[i];
            for (int j = i; j < taskCount - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            tasks[taskCount - 1] = nullptr;
            taskCount--;
            saveToFile("Tasks.json");
            return;
        }
    }
}

void TaskManager::markAsDone(int taskIdToFind)
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr && tasks[i]->getTaskId() == taskIdToFind)
        {
            tasks[i]->setIsDone(true);
        }
    }
    saveToFile("Tasks.json");
}

void TaskManager::updateTask(int taskIdToFind, std::string &newTaskName)
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr && tasks[i]->getTaskId() == taskIdToFind)
        {
            tasks[i]->setTaskName(newTaskName);
            tasks[i]->setUpdatedDate(TimeUtil::getCurrentDateTime());
        }
    }
    saveToFile("Tasks.json");
}

void TaskManager::displayTasks() const
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr)
            std::cout << *tasks[i] << std::endl;
    }
}

void TaskManager::displayFinishedTasks() const
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i] != nullptr)

            if (tasks[i]->getIsDone())
            {
                std::cout << *tasks[i] << std::endl;
            }
    }
}

void TaskManager::saveToFile(const std::string &filename)
{
    json j;

    for (int i = 0; i < taskCount; i++)
    {
        j.emplace_back(JsonUtils::toJson(*tasks[i]));
    }

    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error while saving to file\n";
        return;
    }
    file << j.dump(4);
    file.close();
}

void TaskManager::loadFromFile(const std::string &filename)
{
    json j;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error while opening file\n";
        return;
    }

    file >> j;
    file.close();

    for (int i = 0; i < size; ++i)
    {
        if (tasks[i] != nullptr)
        {
            delete tasks[i];
            tasks[i] = nullptr;
        }
    }

    delete[] tasks;
    size = std::max(static_cast<int>(j.size()), 5);
    taskCount = 0;
    tasks = new Task *[size];

    for (int i = 0; i < size; i++)
    {
        tasks[i] = nullptr;
    }

    for (int i = 0; i < j.size(); i++)
    {
        tasks[i] = new Task(JsonUtils::fromJson(j[i]));
        taskCount++;
        lastId = std::max(lastId, tasks[i]->getTaskId());
    }
}
