🎯 Arbitrary Precision Calculator (ACP) in C

This project is a terminal-based Arbitrary Precision Calculator (ACP) developed in the C programming language. It performs arithmetic operations on very large numbers that cannot be handled by standard C data types. The system demonstrates the use of doubly linked lists, modular programming, and dynamic memory management, making it a strong foundation for advanced applications in compiler design, cryptography, and scientific computing.

📌 Project Overview

Standard data types (int, long, float) have limited range and lose accuracy when numbers exceed their limits. The ACP project overcomes this limitation by representing each number as a doubly linked list of digits, enabling operations on numbers of arbitrary size.

The calculator supports Addition, Subtraction, Multiplication, Division, Modulo, and Power, ensuring accurate results for high-precision calculations. It is useful for educational purposes, understanding data structures, and exploring big number arithmetic in real-world systems.

⚙️ Components / Tools Used

C Programming Language

GCC Compiler

Command-line Interface (CLI)

Doubly Linked List (for storing big numbers)

Modular Programming Techniques

📁 File Modules

main.c – Program entry point, handles user input and controls execution

add.c / add.h – Logic for big integer addition

sub.c / sub.h – Logic for big integer subtraction

mul.c / mul.h – Logic for big integer multiplication

div.c / div.h – Logic for big integer division

mod.c / mod.h – Logic for modulo operation

power.c / power.h – Logic for exponentiation

apc.h – Global structures, macros, and function declarations

utils.c / utils.h – Helper functions (list handling, validation, conversions)

input.txt – Optional input file for testing large numbers

output.txt – Optional file storing results

🧠 Working Principle

The system reads input numbers (from CLI or file), converts them into doubly linked lists, and applies arithmetic algorithms digit by digit.

It processes operations as follows:

Addition & Subtraction: Performed digit-wise with carry/borrow propagation

Multiplication: Implemented using repeated addition or digit-shift method

Division & Modulo: Performed via repeated subtraction and quotient tracking

Power: Calculated using iterative multiplication

This ensures correctness and precision regardless of the number size.

🔐 Input Validation & Error Handling

Verifies that inputs are valid integers (ignores leading zeros).

Handles division by zero with meaningful error messages.

Rejects invalid tokens (e.g., letters in numeric input).

Prevents memory leaks through proper allocation and deallocation.

💡 Features

✅ Handles very large numbers beyond built-in limits
✅ Supports addition, subtraction, multiplication, division, modulo, and power
✅ Uses doubly linked lists for digit-by-digit precision
✅ Modular codebase for maintainability and extension
✅ Provides error handling (division by zero, invalid input)
✅ Demonstrates dynamic memory management and data structures in C
✅ Can be extended for cryptography and scientific computing

📂 File Structure

arbitrary-precision-calculator/

├── main.c          # Program entry point

├── add.c/.h        # Big integer addition

├── sub.c/.h        # Big integer subtraction

├── mul.c/.h        # Big integer multiplication

├── div.c/.h        # Big integer division

├── mod.c/.h        # Modulo operation

├── power.c/.h      # Exponentiation logic

├── utils.c/.h      # Helper functions

├── apc.h           # Global declarations

├── input.txt       # Sample input numbers

├── output.txt      # Optional result storage

├── README.md       # Project documentation

📸 Project Media

🖼️ Sample Terminal Output:

$ ./a.out 123456789123456789 + 987654321987654321
Result: 1111111111111111110

$ ./a.out 987654321987654321 - 123456789123456789
Result: 864197532864197532

$ ./a.out 25 ^ 15
Result: 931322574615478515625
<img width="1920" height="1080" alt="2" src="https://github.com/user-attachments/assets/f20a6585-7199-4c34-b329-13aa7f2e85be" />


📽️ Demo Video: https://drive.google.com/file/d/1IiQa6Z0tU83Q1kh91zMPI3A1IrLye_K6/view?usp=sharing

📈 Future Improvements

Support for floating-point arbitrary precision

Implementation of factorial, logarithm, and trigonometric functions

Expression evaluation with operator precedence (like a scientific calculator)

GUI version using GTK/Qt for better visualization

Export results in CSV/JSON for further analysis

Optimized algorithms (Karatsuba multiplication, divide-and-conquer division)

Library version for integration with other applications

👨‍💻 Developed By
Vamsi T
vamsithummaluri@gmail.com

Vamsi Thummaluri
Embedded Systems & Compiler Design Enthusiast
📧 vamithummaluri@gmail.com
