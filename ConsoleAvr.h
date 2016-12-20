#pragma once

#include "IConsole.h"
#include "ITransport.h"

namespace console_avr {

class ConsoleAvr : public iconsole::IConsole {

public:

    ConsoleAvr(transport::ITransport& transport);

    virtual iconsole::IConsole& print(const char* str);
    virtual iconsole::IConsole& print(const int8_t value);
    virtual iconsole::IConsole& newline(void);

private:

    transport::ITransport& transport_;

};

} /* namespace console */
