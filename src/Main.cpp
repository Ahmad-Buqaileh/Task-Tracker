#include <iostream>

#include "TaskManager.h"

int main(int argc, char *argv[])
{
    TaskManager manager;

    if (argc < 2)
    {
        std::cerr << "Usage : ./main [command] [arguments]\n";
    }

    std::string command = argv[1];

    if (command == "list")
    {
        manager.displayTasks();
    }

    else if (command == "list_finished")
    {
        manager.displayFinishedTasks();
    }

    else if (command == "add")
    {
        if (argc < 4)
        {
            std::cerr << "Usage: ./main add \"Task Name\" \"Due Date\"\n";
            return 1;
        }
        std::string taskName = argv[2];
        std::string dueDate = argv[3];
        manager.addTask(taskName, dueDate);
    }

    else if (command == "update")
    {
        if (argc < 4)
        {
            std::cerr << "Usage: ./main update [taskId] [newTaskName]\n";
            return 1;
        }
        int taskId = std::stoi(argv[2]);
        std::string newTaskName = argv[3];
        manager.updateTask(taskId, newTaskName);
    }
    else if (command == "done")
    {
        if (argc < 3)
        {
            std::cerr << "Usage: ./main done [taskId]\n";
            return 1;
        }
        int taskId = std::stoi(argv[2]);
        manager.markAsDone(taskId);
    }

    else if (command == "delete")
    {
        if (argc < 3)
        {
            std::cerr << "Usage: ./main delete [taskId]\n";
            return 1;
        }
        int taskId = std::stoi(argv[2]);
        manager.deleteTask(taskId);
    }

    return 0;
}