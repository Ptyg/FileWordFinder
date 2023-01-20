#include "Log.hpp"

void Log::console_log(std::string_view msg, 
                      std::string_view tag = "[INFO]") {
    std::cout << tag << ' ' << msg << '\n';
}