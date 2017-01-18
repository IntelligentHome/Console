#include "ConsoleRpi.h"
#include <iostream>

namespace console_rpi {

iconsole::IConsole& ConsoleRpi::print(const char* str) {

    std::cout << str;
    return *this;
}

iconsole::IConsole& ConsoleRpi::print(const uint8_t value) {

    std::cout << (int)value;
    return *this;
}

iconsole::IConsole& ConsoleRpi::newline(void) {

    std::cout << std::endl;
    return *this;
}

} /*namespace console_rpi*/
