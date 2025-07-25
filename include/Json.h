#ifndef JSON_H
#define JSON_H

#include "Task.h"
#include "json.hpp"

using json = nlohmann::json;

namespace JsonUtils
{
    // Convert to JSON
    json toJson(const Task &task);
    
    // Convert to Task
    Task fromJson(const json &j);
}

#endif // JSON_H
