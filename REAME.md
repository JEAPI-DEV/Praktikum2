# Number Conversion Library

A C library for handling various number format conversions, including decimal, hexadecimal, octal, and floating-point numbers.

## Overview

This program provides functions to convert between different number representations and string formats. It supports:
- Decimal numbers (base 10)
- Hexadecimal numbers (base 16, prefixed with "0x" or "0X")
- Octal numbers (base 8, prefixed with "0")
- Binary string representation
- Floating-point numbers (with "." or "," decimal separator) (in second argument)

## Configuration

```c
#define DIGITS 8        /* Maximum number of digits (bytes) */
#define MAXZAHL (1<<DIGITS)  /* Maximum allowed value (256) */
```

## Functions

#### `void clear(char c, char str[])`
Initializes/clears a string with a specified character.
```c
char buffer[DIGITS+1];
clear('0', buffer);  // Result: "00000000"
```

#### `int str2int(char str[])`
Converts a string to an integer, supporting decimal, hexadecimal, and octal formats.
```c
str2int("123")   // Returns: 123 (decimal)
str2int("0x1F")  // Returns: 31 (hexadecimal)
str2int("077")   // Returns: 63 (octal)
```

#### `void int2Binaer(int i, char str[])`
Converts an integer to its binary string representation.
```c
char buffer[DIGITS+1];
int2Binaer(5, buffer);  // Result: "00000101"
```

#### `float str2float(char str[])`
Converts a string to a floating-point number. As an extra.
```c
str2float("123.45")  // Returns: 123.45
str2float("123,45")  // Returns: 123.45 (supports comma separator)
```

## Error Handling

All conversion functions return -1 for invalid inputs:
- Numbers exceeding MAXZAHL
- Invalid characters for the respective number system
- Malformed number strings

## Limitations

- Maximum value is limited by MAXZAHL (256 by default)
- Binary strings are fixed at DIGITS length (8 by default)