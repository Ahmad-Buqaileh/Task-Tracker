#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
private:
    int taskId;
    std::string taskName;
    std::string dueDate;
    std::string updatedDate;
    bool isDone;

public:
    Task(int taskId, std::string taskName, std::string dueDate, std::string updatedDate, bool isDone);

    // setters
    void setTaskId(int taskId)
    {
        this->taskId = taskId;
    }

    void setTaskName(std::string &taskName)
    {
        this->taskName = taskName;
    }

    void setDueDate(std::string &dueDate)
    {
        this->dueDate = dueDate;
    }

    void setIsDone(bool isDone)
    {
        this->isDone = isDone;
    }

    void setUpdatedDate(std::string updatedDate)
    {
        this->updatedDate = updatedDate;
    }
    // getters
    int getTaskId() const
    {
        return taskId;
    }

    std::string getTaskName() const
    {
        return taskName;
    }

    std::string getDueDate() const
    {
        return dueDate;
    }

    bool getIsDone() const
    {
        return isDone;
    }

    std::string getUpdatedDate() const
    {
        return updatedDate;
    }
};

#endif //TASK_H