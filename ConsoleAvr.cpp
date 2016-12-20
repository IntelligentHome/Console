
#include "ConsoleAvr.h"

namespace console_avr {

ConsoleAvr::ConsoleAvr(transport::ITransport& transport)
    :
        transport_(transport)
{
}

iconsole::IConsole& ConsoleAvr::print(const int8_t val) {

    uint8_t send_data[3];
    send_data[0] = val / 100;
    send_data[1] = val / 10 - send_data[0] * 10;
    send_data[2] = val - (send_data[0] * 10 + send_data[1]) * 10;

    for (uint8_t i = 0; i < sizeof(send_data); i++)
        send_data[i] += '0';

    transport_.Send(send_data, sizeof(send_data));

    return *this;
}

iconsole::IConsole& ConsoleAvr::print(const char* str) {

    for(uint16_t i = 0; str[i] != 0; i++) {
        uint8_t data = static_cast<uint8_t>(str[i]);
        transport_.Send(&data, 1);
    }

    return *this;
}

iconsole::IConsole& ConsoleAvr::newline(void) {

    uint8_t new_line[] = { 13, 10 };

    transport_.Send(new_line, sizeof(new_line));

    return *this;
}

} /* namespace console */
