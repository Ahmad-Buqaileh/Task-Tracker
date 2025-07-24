#include "Time.h"

std::string TimeUtil::getCurrentDateTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&timeNow), "%Y-%m-%d %H:%M:%S");

    return oss.str();
}