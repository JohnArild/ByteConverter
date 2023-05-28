# ByteConverter

ByteConverter is a command-line tool written in C++. It takes an input number, either in decimal or hexadecimal format, and prints the hexadecimal, decimal, and binary representation of the input number. The binary representation is divided by nibbles (4 bits) for easier reading. It uses ANSI escape codes for color output on terminals that support it.

## Building ByteConverter

This project uses CMake for its build system. Here's how you can build ByteConverter:

```
mkdir build'
'cd build'
'cmake ..'
'make
```

This will create a `build` directory, generate the necessary build files with CMake, and then compile the code with `make`. The resulting executable will be named `byteconverter` and will be located in the `build` directory.

## Usage

Here's how you can use ByteConverter:

```
./byteconverter <number>
```

Replace `<number>` with the number you want to convert. You can specify the number in either decimal or hexadecimal format. For hexadecimal numbers, use the `0x` prefix.

Here are some examples:

```
./byteconverter 3735928559
```

This will output:
```
3735928559
0x0D EA DB EF
1101 1110 1010 1101 1011 1110 1110 1111
```

And:

```
./byteconverter 0xDEADBEEF
```

Will output:

```
3735928559
0xDE AD BE EF
1101 1110 1010 1101 1011 1110 1110 1111
```

Please note that in the hexadecimal output, each byte is separated by a space and colored differently for easier distinction. In the binary output, each nibble is separated by a space, and the color scheme follows the same as the hexadecimal output.
