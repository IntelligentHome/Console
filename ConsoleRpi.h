#pragma once

#include "IConsole.h"

namespace console_rpi {

class ConsoleRpi : public iconsole::IConsole {

public:

    virtual iconsole::IConsole& print(const char* str);
    virtual iconsole::IConsole& print(const int8_t value);
    virtual iconsole::IConsole& newline(void);
};

} /*namespace console_rpi*/
