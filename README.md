# Libft library
A collection of useful functions for C programming.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Test](#test)

## Installation
To use the Libft library, follow these steps:

1. Clone the repository:
https://github.com/iwonawo/42-libft-updated.git

2. Compile the library to create libft.a library file:

```bash
cd libft
make
make re
```

3. Link the library to your project:

```bash
cc -o your_program your_program.c -I./libft/includes -L./libft -lft
```

## Usage
The Libft library provides a wide range of functions for common programming tasks.
To use functions in the project add #include "libft.h" at the top of the .c file.

```bash
#include "libft.h";
```

## Test
For the main test files in tests/ folder run:

```bash
cd libft
make
cc tests/test-file.c -I./includes -L. -lft -lbsd
./a.out
```