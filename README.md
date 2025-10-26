# Vector Calculator CLI

# A command-line interface (CLI) application for performing basic vector operations, including arithmetic, scalar multiplication, dot product, and cross product, with the ability to store and recall vectors.

## Table of Contents

1.  [Features](#features)
2.  [Vector Structure](#vector-structure)
3.  [Installation](#installation)
4.  [Usage](#usage)
      * [Commands](#commands)
      * [Declaring New Vectors](#declaring-new-vectors)
      * [Calculations (No Save)](#calculations-no-save)
      * [Calculations (With Save)](#calculations-with-save)
5.  [Building from Source](#building-from-source)

-----

## Features

  * **Vector Storage:** Stores vectors by a user-defined name.
  * **Vector Declaration:** Define new 2D or 3D vectors.
      * `name = x y` (sets $z = 0.0$)
      * `name = x y z`
  * **Arithmetic Operations:**
      * Vector Addition (`+`)
      * Vector Subtraction (`-`)
      * Scalar Multiplication (`*`)
      * Dot Product (`.`)
      * Cross Product (`x`)
  * **Utility Commands:** `help`, `list`, `clear`, and displaying individual vector information.

-----

## Vector Structure

The program uses a `vector` structure defined in `vector.h` to store vector data:

```c
typedef struct {
  char name[10]; // Stores the vector name (max 9 characters + null terminator)
  float x;      // X-component
  float y;      // Y-component
  float z;      // Z-component
} vector;
```

-----

## Installation

Since the project is written in C, you will need a C compiler (like GCC) to build and run the application.

### Prerequisites

  * A C compiler (e.g., `gcc`)

-----

## Usage

Once compiled and run, the program enters an interactive loop, prompting you with `vect_calc >>`.

### Commands

| Command | Description | Example |
| :--- | :--- | :--- |
| `help` | Displays the full menu of vector operations and commands. | `help` |
| `quit` | Exits the program. | `quit` |
| `list` | Lists all vectors currently stored in the system. | `list` |
| `clear` | Clears all stored vectors, resetting the list. | `clear` |
| `[name]` | Prints the $x, y, z$ coordinates of a specific vector. | `v1` |
| `save` | Saves vectors in list to a file named by user | `save test_data` |
| `load` | Reads file named by user and populates the vector list with the contents | `load test_data` |

### Declaring New Vectors

You can declare a new vector or update an existing one using the `=` assignment operator.

| Format | Description | Example |
| :--- | :--- | :--- |
| `name = x y` | Creates a 2D vector where $z$ is automatically set to $0.0$. | `a = 1.0 2.5` |
| `name = x y z` | Creates a 3D vector. | `b = 5 6 7` |

### Calculations (No Save)

Calculations that do not specify a result variable will be displayed under the default name **`ans`**.

| Operation | Format | Example | Output |
| :--- | :--- | :--- | :--- |
| Addition | `v1 + v2` | `a + b` | `ans = 6.000000, 8.500000, 7.000000` |
| Subtraction | `v1 - v2` | `a - b` | `ans = -4.000000, -3.500000, -7.000000` |
| Scalar Mult. | `scale * v1` or `v1 * scale` | `5 * a` | `ans = 5.000000, 12.500000, 0.000000` |
| Dot Product | `v1 . v2` | `a . b` | `ans = 30.500000` |
| Cross Product | `v1 x v2` | `a x b` | `ans = 17.500000, -7.000000, -4.000000` |

### Calculations (With Save)

You can save the result of an operation directly into a new or existing vector using the format: `result_name = v1 operator v2`.

| Format | Example | Effect |
| :--- | :--- | :--- |
| `r = v1 + v2` | `r = a + b` | Calculates $\mathbf{a} + \mathbf{b}$ and saves the result to vector `r`. |
| `r = scale * v1` | `r = 5 * a` | Calculates $5 \cdot \mathbf{a}$ and saves the result to vector `r`. |

-----

## Building from Source

Makefile attached to compile with a single command:

```bash
make
```

To run the compiled program:

```bash
./vect_calc
```