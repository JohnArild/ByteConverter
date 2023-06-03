#include "ByteConverter.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide a hex or decimal value.\n";
        return 1;
    }

    std::string input(argv[1]);
    std::vector<uint8_t> bytes;

    if (input.length() > 2 && input.substr(0, 2) == "0x") {
        // Input is a hexadecimal number.
        bytes = ByteConverter::hexToBytes(input.substr(2));
    } else {
        // Input is a decimal number.
        uint64_t decimal = strtoull(input.c_str(), nullptr, 10);
        bytes = ByteConverter::decimalToBytes(decimal);
    }

    ByteConverter::printDecimal(bytes);
    ByteConverter::printHex(bytes);
    ByteConverter::printSpacedHex(bytes);
    ByteConverter::printBits(bytes);

    return 0;
}