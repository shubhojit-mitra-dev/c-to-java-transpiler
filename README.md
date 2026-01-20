# C to Java Transpiler (Mini Compiler)

## 📌 Project Overview

This project is a **source-to-source compiler (transpiler)** that reads a restricted subset of **C language** and generates an **equivalent Java program**.

The goal of this project is **not** to fully support C or Java, but to demonstrate a **clear understanding of compiler design principles**, including:

* Lexical Analysis
* Parsing
* Abstract Syntax Tree (AST) construction
* Semantic mapping between two programming languages
* Code generation

This project is developed as part of a **Compiler Design course** assignment.

---

## 🎯 Objective

* Parse a `.c` file written in a **restricted C syntax**
* Translate its semantics into **valid Java source code**
* Preserve program behavior (control flow, logic, output)

---

## 🏗️ Compiler Architecture

The transpiler follows a classic compiler pipeline:

```
C Source Code (.c)
        ↓
Lexical Analysis (Tokenizer)
        ↓
Parsing (AST Construction)
        ↓
Semantic Mapping (C → Java)
        ↓
Java Code Generation (.java)
```

Each stage is implemented explicitly to reflect real compiler design.

---

## ✅ Supported C Features (MVP Scope)

The transpiler supports the following **subset of C**:

### Data Types

* `int`
* `float`
* `double`
* `char`

### Statements

* Variable declaration and initialization
* Assignment statements
* `if / else / else if`
* `while` loop
* `for` loop
* `return`

### Expressions

* Arithmetic: `+ - * / %`
* Relational: `< > <= >= == !=`
* Parenthesized expressions

### I/O

* `printf`
  → mapped to `System.out.print` / `System.out.println` in Java

### Program Structure

* A single `main` function
* No user-defined functions

---

## ❌ Unsupported Features (Explicitly Out of Scope)

The following C features are **not supported**:

* Input (`scanf`)
* Pointers
* Arrays
* Structs / unions
* Header files (`#include`)
* Macros / preprocessor directives
* Dynamic memory (`malloc`, `free`)
* Function definitions (other than `main`)
* Function pointers

These limitations are **intentional** to keep the compiler focused and manageable.

---

## 🧪 Test Program (FizzBuzz)

The following C program is used as the primary test case:

```c
int main() {
    int n = 20;
    int i;

    for (i = 1; i <= n; i = i + 1) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("Number\n");
        }
    }

    return 0;
}
```

The generated Java code preserves:

* Control flow
* Arithmetic logic
* Output behavior

---

## 🛠️ Implementation Language

* **C++**
* No external parser generators (e.g., Lex/Yacc)
* All compiler stages implemented manually for learning purposes

---

## 📂 Project Structure (Planned)

```
c-to-java-transpiler/
│
├── lexer/          # Token definitions and tokenizer
├── parser/         # Grammar parsing and AST construction
├── ast/            # AST node definitions
├── semantic/       # C → Java semantic mapping
├── codegen/        # Java code generation
├── tests/          # Sample C input programs
├── output/         # Generated Java files
└── README.md
```

---

## 🎓 Learning Outcomes

By completing this project, you will gain hands-on experience with:

* Writing a lexer and parser from scratch
* Designing and traversing an AST
* Understanding semantic differences between C and Java
* Building a real compiler pipeline
* Applying theoretical compiler design concepts practically

---

## 🚀 Future Extensions (Optional)

* Support for arrays
* Basic function support
* Symbol table with type checking
* Error reporting and recovery
* LLVM IR or bytecode backend

---

## 📜 Disclaimer

This project is **educational** and intentionally limited in scope.
It is not intended to replace real-world compilers or transpilers.
