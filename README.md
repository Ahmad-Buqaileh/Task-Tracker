# 📝 Task-Tracker

A simple, command-line task tracking application written in C++ that stores your tasks persistently in a JSON file.

## Features

- Add tasks with name and due date
- List all tasks or only finished tasks
- Update task name
- Mark tasks as done
- Delete tasks
- Tasks are saved and loaded from a `Tasks.json` file
- Tracks last updated time using `std::chrono`
- Dynamic memory allocation with resizing logic

## Requirements

- C++17 or newer
- g++ compiler (or any C++ compiler)
- [nlohmann/json](https://github.com/nlohmann/json) header (`json.hpp`)
 