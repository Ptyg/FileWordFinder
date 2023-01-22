#include "Log.hpp"
#include <format>



void Log::console_log(std::string_view msg, 
                      std::string_view tag) {
    std::cout << std::format("{} {}\n", tag, msg); 
}