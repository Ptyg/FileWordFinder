#ifndef LOGGER
#define LOGGER

#include <string_view>
#include <iostream>

struct Log {
    static void console_log(std::string_view msg, 
                            std::string_view tag = "[INFO]") {
        std::cout << tag << ' ' << msg << '\n';
    }
};

#endif //LOGGER
