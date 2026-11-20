# 42-project-template

*This activity has been created as part of the 42 curriculum by sindiaye.*

# FT_PRINTF Library Project

## Description

**ft_printf** is a project developed as part of the 42 curriculum.

The goal of this project is to recreate the standard C `printf()` function by implementing a custom version called `ft_printf()`.

This project focuses on:
- Variadic functions and argument handling using `va_list`, `va_start`, `va_arg`, and `va_end`.
- Formatted output and conversion specifiers.
- String manipulation, number conversion, and pointer handling.
- Memory management and modular programming in C.
- Creating and managing a static library using GNU Make.

The implementation supports the following conversion specifiers:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Instructions

### Requirements

- GCC or Clang compiler
- GNU Make
- Standard C library

### Compilation

Clone the repository:

```bash
git clone <repository-url>
cd <repository-name>
```

Compile the library:

```bash
make
```

This generates the static library `libftprint.a`.

### Available Commands

| Command | Description |
|---|---|
| `make` | Compile the project and generate the static library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the static library |
| `make re` | Recompile everything |

### Usage

To use `ft_printf()` in your own C program, include the header and link the compiled library.

Include the header in your source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! You are %d years old.\n", "World", 42);
    return (0);
}
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprint -o program
```

Run the executable:

```bash
./program
```

`ft_printf()` returns the total number of characters printed, just like the original `printf()` function.

## Algorithm and Data Structure

### Chosen Algorithm

The implementation processes the format string character by character.

1. Iterate through the format string until the null terminator is reached.
2. Print regular characters directly.
3. When a `%` character is encountered, identify the following conversion specifier.
4. Retrieve the corresponding argument using `va_arg()`.
5. Dispatch the argument to the appropriate conversion function.
6. Accumulate and return the total number of characters printed.

Numeric conversions use recursive functions to extract and print individual digits.

For hexadecimal conversions, the number is repeatedly divided by 16, and the remainder is used to select the corresponding character from a hexadecimal base.

### Data Structures

The project primarily uses:
- **`va_list`**: Handles the variable number of arguments passed to `ft_printf()`.
- **Character arrays**: Store format strings and conversion bases.
- **Integer variables**: Track the current position in the format string and the number of characters printed.
- **`uintptr_t`**: Represents pointer addresses as unsigned integers for hexadecimal conversion.

The implementation relies on standard C data types and does not require complex data structures.

## Resources

### Documentation and References

- 42 ft_printf Subject
- C Programming Language Documentation
- Variadic Functions – C Reference
- printf() – C Reference
- GNU Make Documentation

### AI Usage

AI tools were used as supplementary learning and development resources during this project.

The following tasks involved AI assistance:

- **Concept explanation:** Understanding variadic functions, argument handling, format specifiers, hexadecimal conversions, and pointer representation.
- **Debugging:** Identifying potential bugs and understanding unexpected behavior during testing.
- **Code review:** Discussing implementation choices, edge cases, and compliance with the 42 Norm.
- **Documentation:** Assisting with README writing and technical explanations.

All AI-generated suggestions were reviewed, tested, and understood before being incorporated into the project.

## Project Structure

```text
.
├── ft_printf_conv1.c
├── ft_printf_conv2.c
├── ft_printf.c
├── ft_printf.h
├── Makefile
└── README.md
```

## Author

**sindiaye**

- GitHub: [Sidy3143](https://github.com/Sidy3143)