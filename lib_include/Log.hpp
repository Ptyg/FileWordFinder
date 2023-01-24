#ifndef LOGGER
#define LOGGER

#include <string_view>
#include <iostream>

namespace log {
    void console_log(std::string_view msg, std::string_view tag);
}

#endif //LOGGER
