# C Programming Assignment 4 (CO4) - Code Files

These files are organized from the code examples in the supplied PDF.

## Main integrated application
- `library.c` - integrated Library Inventory and Membership Management System from Task 10.

## Individual examples
The `examples/` folder contains the separate compilable programs for string input and functions, pointer traversal and processing, dynamic memory, command-line arguments, structures, structure pointers, unions, and storage classes.

## Compile
Use GCC with C11:

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 library.c -o library
```

For an individual example:

```bash
gcc -Wall -Wextra -std=c11 examples/01_string_input.c -o string_input
```

Run on Linux/macOS with `./library` or `./string_input`. On Windows, run the generated `.exe` file.

## Important note about the PDF's integrated prototype
The PDF labels Task 10 as a modular teaching prototype. Its command-line `borrow` branch is an extension-point message, not a completed CLI workflow, and the program keeps records only during one execution. It does not save records between runs. The examples are separate programs, so compile them one at a time.

## GitHub upload
Upload the complete `C_Programming_CO4_GitHub` folder contents into your repository, keeping `library.c`, `README.md`, and the `examples/` folder together.
