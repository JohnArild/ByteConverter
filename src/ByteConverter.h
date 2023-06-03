#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdint>

class ByteConverter {
public:
    static std::vector<uint8_t> hexToBytes(const std::string& hex);
    static std::vector<uint8_t> decimalToBytes(uint64_t decimal);
    static void printHex(const std::vector<uint8_t>& bytes);
    static void printDecimal(const std::vector<uint8_t>& bytes);
    static void printSpacedHex(const std::vector<uint8_t>& bytes);
    static void printBits(const std::vector<uint8_t>& bytes);
};
