#pragma once

#include "ITransport.h"

namespace console {

class Console {

public:

    Console(transport::ITransport& transport);

    Console& print(const char* str);
    Console& print(const int8_t value);
    Console& newline(void);

private:

    transport::ITransport& transport_;

};

} /* namespace console */
