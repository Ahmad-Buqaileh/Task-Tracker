#include <Json.h>

json JsonUtils::toJson(const Task &task)
{
    return json{
        {"taskId", task.getTaskId()},
        {"taskName", task.getTaskName()},
        {"dueDate", task.getDueDate()},
        {"updatedDate", task.getUpdatedDate()},
        {"isDone", task.getIsDone()},
    };
};

Task JsonUtils::fromJson(const json &j)
{
    return Task(
        j.at("taskId"),
        j.at("taskName"),
        j.at("dueDate"),
        j.at("updatedDate"),
        j.at("isDone"));
}
