# Smart Campus Utility Billing System (C)

C programming assignment (CO1): utility billing for campus facilities.

## Files
| File | Description |
|------|-------------|
| `01_heading.c` | Prints the billing-system heading |
| `02_subtotal.c` | Calculates subtotal = units x rate |
| `03_program_structure.c` | Sections of a C program |
| `04_directives_example.c` | `#define` constants in a billing calculation |
| `billing.h`, `billing.c` | User-defined header with include guard and functions |
| `05_conditional_compilation.c` | `#ifdef DEBUG` demo |
| `06_sizeof_demo.c` | `sizeof` for basic data types |
| `07_increment_trace.c` | Prefix vs postfix increment |
| `campus_billing.c` | Complete billing program with input validation |
| `campus_billing_v2.c` | Extended version: department concession and bill warning |

## Compile and run
```
gcc -std=c11 -Wall -Wextra -pedantic campus_billing.c -o campus_billing
./campus_billing
```
`billing.c` has no `main()`, so compile it only with `-c`:
`gcc -std=c11 -Wall -Wextra -pedantic -c billing.c`
