#include "gtest/gtest.h"
#include "Console.h"
#include "Mocks.h"

namespace test_Console {

TEST(Console, SendString) {

    uint8_t sent_data[200];

    const uint8_t sent_expected[] = {
        'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', 0, 0, 0, 0, 0
    };

    test_mocks::TransportMock mock_transport(sent_data, sizeof(sent_data));

    console::Console console(mock_transport);

    memset(sent_data, 0, sizeof(sent_data));
    mock_transport.sent_data_idx_ = 0;

    console.print("Hello World");

    for (int i = 0; i < sizeof(sent_expected); i++)
        EXPECT_TRUE(sent_expected[i] == sent_data[i]) << "Got " \
                << (int)sent_data[i] << " Expected " << (int)sent_expected[i] \
                << " at position: " << i << std::endl;
}

TEST(Console, SendStringAndNewLine) {

    uint8_t sent_data[200];

    const uint8_t sent_expected[] = {
        'H', 'e', 'l', 'l', 'o', ' ', 'm', 'y', ' ', 'f', 'r', 'i', 'e', 'n', 'd', 13, 10,
        'M', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's',
    };

    test_mocks::TransportMock mock_transport(sent_data, sizeof(sent_data));

    console::Console console(mock_transport);

    memset(sent_data, 0, sizeof(sent_data));
    mock_transport.sent_data_idx_ = 0;

    console
        .print("Hello my friend")
        .newline()
        .print("My name is");

    for (int i = 0; i < sizeof(sent_expected); i++)
        EXPECT_TRUE(sent_expected[i] == sent_data[i]) << "Got " \
                << (int)sent_data[i] << " Expected " << (int)sent_expected[i] \
                << " at position: " << i << std::endl;
}

} /* namespace test_Console */
