#include "ByteConverter.h"

std::vector<uint8_t> ByteConverter::hexToBytes(const std::string& hex) {
    std::vector<uint8_t> bytes;

    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        uint8_t byte = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }

    return bytes;
}

std::vector<uint8_t> ByteConverter::decimalToBytes(uint64_t decimal) {
    std::vector<uint8_t> bytes;

    do {
        bytes.push_back(decimal & 0xFF);
        decimal >>= 8;
    } while (decimal > 0);

    // Reverse the bytes to get big-endian byte order.
    std::reverse(bytes.begin(), bytes.end());

    return bytes;
}

void ByteConverter::printHex(const std::vector<uint8_t>& bytes) {
    std::cout << "0x";
    for (auto byte : bytes) {
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)byte;
    }
    std::cout << std::dec << '\n';
}

void ByteConverter::printDecimal(const std::vector<uint8_t>& bytes) {
    uint64_t value = 0;
    for (auto byte : bytes) {
        value = (value << 8) | byte;
    }
    std::cout << value << '\n';
}

void ByteConverter::printSpacedHex(const std::vector<uint8_t>& bytes) {
    int color = 0;
    for (auto byte : bytes) {
        if (color % 2 == 0) {
            // Set white text on black background
            std::cout << "\033[30;47m"; // ANSI escape code for black text on white background
        } else {
            // Set black text on white background
            std::cout << "\033[37;40m"; // ANSI escape code for white text on black background
        }
        std::cout << "      0x" << std::setfill('0') << std::setw(2) << std::hex << (int)byte;
        color++;
    }
    std::cout << "\033[0m" << std::dec << '\n'; // Reset the terminal color to defaults
}

void ByteConverter::printBits(const std::vector<uint8_t>& bytes) {
    int color = 0;
    for (auto byte : bytes) {
        std::bitset<8> byteBits(byte);
        std::string bitString = byteBits.to_string();
        if (color % 2 == 0) {
            // Set white text on black background
            std::cout << "\033[30;47m"; // ANSI escape code for black text on white background
        } else {
            // Set black text on white background
            std::cout << "\033[37;40m"; // ANSI escape code for white text on black background
        }
        for (int i = 0; i < 8; i += 4) {
            std::cout << ' ' << bitString.substr(i, 4);
        }
        color++;
    }
    std::cout << "\033[0m" << '\n'; // Reset the terminal color to defaults
}
