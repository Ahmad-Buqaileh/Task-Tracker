#include <iostream>

#include "TaskManager.h"

int main(int argc, char *argv[])
{
    TaskManager manager;

    if (argc < 2)
    {
        std::cerr << "Usage : ./main [command] [arguments]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "help")
    {
        std::cout << "list -> to show all tasks; Usage: ./main list\n";
        std::cout << "list_finished -> to show only finished tasks; Usage: ./main list_finished\n";
        std::cout << "add -> to add a task; Usage: ./main add [taskName] [dueDate]\n";
        std::cout << "done -> to mark a task as done; Usage: ./main done [taskId]\n";
        std::cout << "delete -> to remove a task; Usage: ./main delete [taskId]\n";
        std::cout << "update -> to update a task; Usage: ./main update [taskId] [taskName]\n";
    }

    else if (command == "list")
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