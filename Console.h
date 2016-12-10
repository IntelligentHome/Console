#pragma once

#include "ITransport.h"

namespace console {

class Console {

public:

    Console(transport::ITransport& transport);

    Console& print(const char* str);
    Console& newline(void);

private:

    transport::ITransport& transport_;

};

} /* namespace console */
