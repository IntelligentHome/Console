
#include "Console.h"

namespace console {

Console::Console(transport::ITransport& transport)
    :
        transport_(transport)
{
}

Console& Console::print(const char* str) {

    for(uint16_t i = 0; str[i] != 0; i++) {
        uint8_t data = static_cast<uint8_t>(str[i]);
        transport_.Send(&data, 1);
    }

    return *this;
}

Console& Console::newline(void) {

    uint8_t new_line[] = { 13, 10 };

    transport_.Send(new_line, sizeof(new_line));

    return *this;
}

} /* namespace console */
