# 💬 ft_printf: Custom C Printf Implementation (42 Project)

[![C Language Badge](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Variadic Functions Badge](https://img.shields.io/badge/Concept-Variadic_Functions-orange)](https://en.wikipedia.org/wiki/Variadic_function)

### 🌟 Project Overview

This repository contains **ft\_printf** , a deep dive project from the **42 Common Core curriculum**.

The goal of this project is to recreate the functionality of the standard C library function `printf()`. This requires an understanding of **variadic functions** (functions that take a variable number of arguments) and careful manipulation of standard output.

#### **Key Features Implemented:**
* Handles multiple data types and formats.
* Includes support for field width, precision, and alignment.
* The final function is a drop-in replacement for the standard `printf`.

---

### 🛠️ Installation and Usage

`ft_printf` is typically compiled into a static library (`libftprintf.a`) and linked with the program that needs to use it.

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/Nexus29/42-ft_printf.git](https://github.com/Nexus29/42-ft_printf.git)
    cd ft_printf
    ```

2.  **Compile the Library:**
    Run `make` to compile the source files and create the static library file, `libftprintf.a`.
    ```bash
    make
    ```

3.  **Use it in Your Project:**
    To compile your own C file (`main.c`) with `libftprintf.a`, you need to include the header and link the library.

    **In your C file (`main.c`):**
    ```c
    #include "ft_printf.h" 
    
    int main(void)
    {
        int count = ft_printf("My number is: %d and my name is %s\n", 42, "Giovanni");
        return (0);
    }
    ```

    **Compilation command:**
    ```bash
    cc -Wall -Wextra -Werror main.c -L. -lftprintf -I. -o test
    ```
    * **Note:** You may need to link your **Libft** as well if your `ft_printf` implementation relies on functions from it (e.g., `ft_strlen`, `ft_itoa`).

---

### 📜 Supported Conversions and Flags

This implementation supports the following conversions and format specifiers:

#### **Supported Conversions (Specifiers)**

| Conversion | Description |
| :--- | :--- |
| `c` | Prints a single character. |
| `s` | Prints a string (character array). |
| `p` | Prints the memory address/pointer value in hexadecimal format. |
| `d` / `i` | Prints a signed decimal integer. |
| `u` | Prints an unsigned decimal integer. |
| `x` | Prints a number in lowercase hexadecimal format (e.g., `1f`). |
| `X` | Prints a number in uppercase hexadecimal format (e.g., `1F`). |
| `%%` | Prints a literal percent sign. |

#### **Supported Flags, Width, and Precision (Bonus)**

| Type | Format | Description |
| :--- | :--- | :--- |
| **Field Width** | `%10d` | Specifies the minimum number of characters to be printed. |
| **Precision** | `%.5s`, `%.2f` | For strings: maximum number of characters to be printed. For integers: minimum number of digits to appear. |
| **Zero Padding** | `%010d` | Pads the output with leading zeros instead of spaces. |
| **Left Justify** | `%-10d` | Left-justifies the result within the field width. |

---

### 👤 Author

* **Giovanni Pio Lancellotta** - [Nexus29](https://github.com/Nexus29)
    * `42 Student ID:` **glancell**
    * `Personal Website:` *Coming Soon!*
