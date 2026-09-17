*This project has been created as part of the 42 curriculum by yaandria*

## 📖 Description

**ft_printf** is a custom implementation of the standard C library function `printf`.

The goal of this project is to recreate the behavior of `printf` from scratch in order to deeply understand:

- Variadic functions (`stdarg.h`)
- Format string parsing
- Flags and precision handling
- Type conversions
- Low-level output using `write`

This project is part of the 42 curriculum and aims to reproduce the original `printf` behavior as closely as possible, including return values and formatting rules.

---

---

## 📂 Project Structure

```text
ft_printf/
│
├── ft_printf.c                 
├── Makefile                    
├── header/
│   └── ft_printf.h             
├── srcs/                       
│   ├── ft_putchar_ba.c
│   ├── ft_puthex_ba.c
│   ├── ft_putnbr_ba.c
│   ├── ft_putstr_ba.c
│   └── print_basics.c
├── _bonus/                     
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ft_puthex_bonus.c
│   ├── ft_put_n_nbr_bonus.c
│   ├── parse_all_bonus.c
│   ├── print_bonus.c
│   ├── print_char_bonus.c
│   ├── print_pointer_bonus.c
│   ├── print_hex_bonus.c
│   ├── print_nbr_bonus.c
│   └── print_str_bonus.c
├── libft/                      
│   ├── *.c                      
│   ├── libft.h                  
│   └── Makefile                 
└── README.md                   
```

## Supported Conversions

The function handles the following format specifiers:

- `%c` → Character  
- `%s` → String  
- `%p` → Pointer address  
- `%d` → Signed decimal integer  
- `%i` → Signed integer  
- `%u` → Unsigned decimal integer  
- `%x` → Hexadecimal (lowercase)  
- `%X` → Hexadecimal (uppercase)  

---

## Supported Flags

---

| Flag | Description                                | Applies To          |
|------|--------------------------------------------|-------------------|
| `-`  | Left-justify within the given field width | All conversions   |
| `0`  | Pad with zeros instead of spaces           | Numbers (%d, %i, %u, %x, %X, %p) |
| `.`  | Precision (number of digits / max string length) | Numbers & Strings |
| `#`  | Alternate form: adds `0x`/`0X` for hex    | `%x`, `%X`        |
| `+`  | Always show sign (+ or -)                  | Signed numbers (`%d`, `%i`) |
| (space) | Prefix a space for positive numbers      | Signed numbers (`%d`, `%i`) |

---

### Notes

- Flags can be combined (e.g., `%-05d`)  
- Precision overrides zero-padding for numbers  
- For `%s`, precision limits the number of characters printed  
- `#` has no effect on `%d` or `%i`  

## Project Objective

The purpose of this project is not only to make a working `printf`, but to:

- Replicate its behavior with high precision
- Handle edge cases correctly
- Match the original function’s return value
- Write clean, modular, and maintainable C code

This project strengthens core C programming skills and builds a solid foundation for understanding formatted output and low-level system functions.

---

## Compilation & Usage Guide

All compilation is done with:
```bash
cc -Wall -Wextra -Werror
```

A `Makefile` is provided to simplify the build process.

---

## Step-by-Step: Building & Testing

### Option 1: Mandatory Part Only

**1. Build the mandatory library:**
```bash
make
```

This will:
- Compile `libft/` using its own Makefile
- Compile mandatory sources (`ft_printf.c` and `srcs/*.c`)
- Generate the static library: `libftprintf.a`

**2. Create a test file (e.g., `main.c`):**
```c
#include "ft_printf.h"

int main(void)
{
    int a = 42;
    
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("Pointer: %p\n", &a);
    ft_printf("Decimal: %d\n", a);
    ft_printf("Integer: %i\n", a);
    ft_printf("Unsigned: %u\n", 1234);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

**3. Compile with the library:**
```bash
cc main.c -Wall -Wextra -Werror -L. -Iheader -Ilibft -lftprintf
```

**4. Run the program:**
```bash
./a.out
```

**Expected output:** Basic conversions without any flag handling.

---

### Option 2: Bonus Part (with Flags)

**1. Clean previous build (recommended):**
```bash
make fclean
```

**2. Build the bonus library:**
```bash
make bonus
```

This will:
- Compile `libft/`
- Compile mandatory helper functions from `srcs/`
- Compile bonus sources from `_bonus/`
- Generate `libftprintf.a` with **bonus flag support**
- The bonus version **replaces** the mandatory `ft_printf` in the library

**3. Create a test file with flags (e.g., `main.c`):**
```c
#include "ft_printf.h"

int main(void)
{
    int a = 42;
    int b = -7;
    
    // Basic conversions
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    
    // String precision
    ft_printf("String precision: %.5s\n", "Hello World");
    
    // Signed integers with flags
    ft_printf("Plus flag: %+d %+i\n", a, b);
    ft_printf("Space flag: % d % i\n", a, b);
    ft_printf("Zero padding: %05d %05i\n", a, b);
    ft_printf("Left align: %-5d %-5iend\n", a, b);
    
    // Unsigned with flags
    ft_printf("Zero padding: %010u\n", 1234);
    ft_printf("Left align: %-10uend\n", 1234);
    
    // Hexadecimal with flags
    ft_printf("Alternate form: %#x %#X\n", 255, 255);
    ft_printf("Zero padding: %08x\n", 255);
    ft_printf("Left align: %-8xend\n", 255);
    return (0);
}
```

**4. Compile with the bonus library:**
```bash
cc main.c -Wall -Wextra -Werror -L. -I_bonus -Ilibft -lftprintf
```

**Important:** Use `-I_bonus` (not `-Iheader`) to include the bonus header!

**5. Run the program:**
```bash
./a.out
```

**Expected output:** All flags (`-`, `0`, `.`, `#`, `+`, space) should be properly handled.

---

## Makefile Commands

| Command | Description |
|---------|-------------|
| `make` or `make all` | Build mandatory version |
| `make bonus` | Build bonus version with flag support |
| `make clean` | Remove object files (`.o` files) |
| `make fclean` | Remove object files and `libftprintf.a` |
| `make re` | Rebuild everything from scratch (mandatory) |

---

## Troubleshooting

**Problem:** Flags are not working (printing `%5d` literally instead of formatting)

**Solution:**  
- Make sure you ran `make bonus` (not just `make`)
- Make sure you're including the correct header: `-I_bonus` in your compile command
- Clean and rebuild: `make fclean && make bonus`

**Problem:** Compilation errors about missing header files

**Solution:**
- For mandatory: use `-Iheader -Ilibft`
- For bonus: use `-I_bonus -Ilibft`

---

## Key Notes

- The project generates a single static library: `libftprintf.a`
- `libft` is automatically compiled and included in the library
- **Mandatory and bonus use the same library name** but different implementations
- Always run `make fclean` before switching between mandatory and bonus builds
- The bonus version includes all mandatory conversions **plus** flag handling

---

## Resources

### Documentation & References

The following resources were used to understand and implement `ft_printf`:

- **The C Standard Library Manual**
  - `man 3 printf`
  - `man 3 write`
  - `man stdarg`

- **The C Programming Language** – Brian W. Kernighan & Dennis M. Ritchie  
  (For fundamental understanding of C syntax and variadic functions)

- 42 School materials and peer discussions

These resources helped clarify:
- The exact behavior of format specifiers
- Flag precedence rules
- Precision and width handling
- Return value behavior
- Edge cases (e.g., `0` with precision `0`, NULL strings, pointer formatting)

---

## Use of Artificial Intelligence

Artificial Intelligence tools (ChatGPT) were used as a **learning assistant** during the project.

AI was used for:

- Clarifying theoretical concepts (variadic functions, flag priority rules)
- Understanding edge cases of the original `printf`
- Debugging logic errors
- Reviewing formatting rules for flags (`-`, `0`, `.`, `#`, `+`, space)
- Generating test cases to compare `printf` and `ft_printf`

AI was **not used to generate full project solutions**.  
All parsing logic, flag handling, and formatting implementations were written and understood manually.

The use of AI was focused on:
- Learning support
- Concept clarification
- Documentation improvement

---

## Learning Outcome

Through these resources and guided research, this project strengthened understanding of:

- Variadic arguments in C
- String parsing strategies
- Flag precedence logic
- Low-level output functions
- Modular code architecture

---

## Algorithm Overview (Mandatory Part)

The `ft_printf` function follows a **linear parsing and dispatch algorithm**.

It reads the format string character by character.  
If a `%` is encountered, the function delegates the work to a dispatcher that selects the appropriate conversion handler.

---

### Visual Representation

```
print_basics(specifier, list)
│
├── 'c' → ft_putchar_ba()
│
├── 's' → handle_str()
│   │
│   ├── NULL → "(null)"
│   └── else → ft_putstr_ba(str)
│
├── 'p' → handle_pointer()
│   │
│   ├── NULL → "(nil)"
│   └── else
│       ├── print "0x"
│       └── ft_puthex_ba(address)
│
├── 'd' / 'i' / 'u' → handle_digits()
│   │
│   ├── get number (int or unsigned)
│   ├── ft_putnbr_ba(nbr)
│   └── count_digits(nbr)
│
├── 'x' / 'X' → ft_puthex_ba()
│
└── default → print '%'
```

### Explanation

1. `ft_printf` scans the format string once (**O(n)** complexity).
2. If the character is not `%`, it is printed directly.
3. If `%` is found:
   - The next character is treated as a **specifier**
   - `print_basics()` determines which handler to call
4. Each handler:
   - Retrieves the argument using `va_arg`
   - Calls the appropriate low-level printing function
   - Returns the number of printed characters
5. The total character count is accumulated and returned at the end.

---

### 🏗 Design Justification

This design was chosen because:

- It keeps the main function simple and readable
- It separates parsing logic from printing logic
- Each conversion is modular and independently testable
- It avoids unnecessary data structures in the mandatory part
- It prepares a clean foundation for adding flags and parsing logic in the bonus part

The algorithm is efficient, linear, and respects the behavior of the original `printf`.


---

#### 2️⃣ `process()`

The `process` function determines how to handle the `%` sequence.

- If `%%` is detected:
  - Print a single `%`
  - Increment the character count

- Otherwise:
  - Call `parse_all()`
  - Then call `print()`

---

#### 3️⃣ `parse_all()`

This function:

- Parses flags (`-`, `0`, `#`, `+`, space)
- Parses width
- Parses precision (`.`)
- Stores all parsed information inside a **structure**

Example of stored data:

- alignment flag
- zero padding flag
- precision value
- width value
- conversion specifier

Using a structure centralizes all formatting information and makes it accessible to the printing stage.

---

#### 4️⃣ `print()`

This function is similar to `print_basics()` from the mandatory part, but now:

- It receives the parsed structure
- It applies flag logic before printing
- It manages:
  - Padding (spaces or zeros)
  - Alignment (left/right)
  - Sign handling
  - Prefixes (`0x`, `0X`)
  - Precision rules

It then calls the appropriate low-level printing function and returns the total number of printed characters.

---

### 🏗 Design Justification

The bonus implementation introduces a structure-based design because:

- Multiple flags must be stored simultaneously
- Flag precedence rules require centralized information
- Printing behavior depends on combined formatting parameters

Separating the process into:

- `process()` → control logic  
- `parse_all()` → parsing stage  
- `print()` → formatted output stage  

ensures:

- Cleaner code organization
- Easier debugging
- Better scalability
- Logical separation between parsing and rendering

This structured approach mirrors how real formatting engines are implemented.