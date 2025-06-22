# C++ Module 08: Templated containers, iterators, algorithms

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This project is part of the C++ modules at 42 School. This module is a deep dive into the C++ Standard Template Library (STL), focusing on templates, containers, iterators, and algorithms. The exercises are designed to build a strong understanding of how to use and even extend standard library components to solve various problems efficiently.

## Core Concepts Covered

*   **Templates:** Writing generic functions and classes that can work with any data type.
*   **STL Containers:** In-depth use of various containers like `std::vector`, `std::list`, `std::deque`, and `std::array`. Understanding their specific strengths, weaknesses, and use cases.
*   **Iterators:** Mastering the use of iterators to traverse and manipulate elements within containers. Understanding iterator categories and concepts like `begin()`, `end()`, `cbegin()`, `cend()`, `rbegin()`, `rend()`.
*   **STL Algorithms:** Applying standard algorithms like `std::find`, `std::sort`, `std::for_each`, `std::min_element`, and `std::max_element` to operate on container elements.
*   **Container Adaptors:** Understanding how adaptors like `std::stack` provide a specific interface over an underlying container.
*   **Inheritance with STL:** Extending the functionality of standard library classes through inheritance.
*   **Exception Handling:** Using exceptions to signal errors, such as when an operation cannot be performed.

## Learning Resources
- [**Dynamic arrays: std::vector**](https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/) (go through the whole chapter)
- [Iterators and their usage](https://www.studyplan.dev/pro-cpp/iterators)
- [Introduction to standard library algorithms](https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/)
- [std::stack](https://cplusplus.com/reference/stack/stack/)

## Project Structure

The project is divided into three exercises:

*   `ex00/`: A simple function template to find an element in a container.
*   `ex01/`: A `Span` class that stores numbers and can calculate the shortest and longest spans between them.
*   `ex02/`: A `MutantStack` class that extends `std::stack` to be iterable.

Each directory contains:
*   `Makefile`: To compile the exercise.
*   `main.cpp`: The main program to test the exercise's features.
*   Headers (`.h`) and implementation files (`.cpp`) for the required classes/functions.

## Implementation Details

### Exercise 00: Easy Find

*   **Task:** Create a function template `easyfind` that takes a container of integers and an integer value. It should find the first occurrence of the value in the container.
*   **Implementation:**
    *   The `easyfind` function is a template that accepts any container type `T`.
    *   It uses the `std::find` algorithm, which is the standard way to search for a value in a range defined by iterators.
    *   It operates on `const_iterator`s (`cbegin()`, `cend()`) to ensure it can work with `const` containers and does not modify the container's contents.
    *   It returns an iterator to the first element found, or the container's `cend()` iterator if the value is not present.
*   **Key Concepts:** Function templates, STL containers, `const` correctness, iterators (`const_iterator`, `cbegin`, `cend`), `std::find` algorithm.

### Exercise 01: Span

*   **Task:** Develop a `Span` class that can store a maximum of `N` integers. It must support adding single numbers, adding a range of numbers, and calculating the shortest and longest spans between its stored numbers.
*   **Implementation:**
    *   The `Span` class uses a `std::vector<int>` internally to store the numbers. The capacity is set at construction time using `reserve()`.
    *   `addNumber()`: Adds a single integer. It throws a custom exception if the `Span` is already at full capacity.
    *   `addRange()`: A member function template that accepts two iterators. It calculates the distance between them to check if there is enough remaining capacity before adding the elements. This allows adding elements from any container type (e.g., `std::vector`, `std::array`).
    *   `longestSpan()`: Calculates the difference between the maximum and minimum elements in the `Span`. This is efficiently implemented using `std::max_element` and `std::min_element`.
    *   `shortestSpan()`: Finds the smallest difference between any two numbers. The implementation creates a sorted copy of the internal vector and then iterates through it once, comparing adjacent elements. This is an efficient way to find the minimum difference.
    *   Both span functions throw an exception if the `Span` contains fewer than two numbers, as a span cannot be determined.
*   **Key Concepts:** Custom class design, `std::vector` capacity management (`reserve`), exception handling, template member functions, iterator-based range operations, STL algorithms (`std::sort`, `std::min_element`, `std::max_element`).

### Exercise 02: Mutated Abomination (MutantStack)

*   **Task:** Create a `MutantStack` class template that inherits from `std::stack` and provides iterator access to its elements.
*   **Implementation:**
    *   `std::stack` is a container adaptor, not a full container. It provides a specific LIFO (Last-In, First-Out) interface but doesn't expose iterators by default. It uses an underlying container (like `std::deque` by default) to store elements.
    *   The `MutantStack` class template inherits publicly from `std::stack<T, Container>`.
    *   The key to this exercise is that `std::stack`'s underlying container is stored in a `protected` member variable named `c`.
    *   By inheriting from `std::stack`, `MutantStack` can access `this->c`.
    *   `MutantStack` then exposes the iterators of the underlying container `c` by implementing its own `begin()`, `end()`, `rbegin()`, `rend()` (and their `const` and `c` versions). These functions simply call and return the result of the corresponding function on `this->c`.
    *   This "mutation" allows a `MutantStack` object to be used with features that require iterators, such as range-based `for` loops and most STL algorithms, while still retaining all the functionality of a `std::stack`.
*   **Key Concepts:** Container adaptors (`std::stack`), inheritance from STL classes, accessing `protected` base class members, implementing iterators for a non-iterable class, class templates.

## How to Compile and Run

Each exercise can be compiled and run independently using the provided `Makefile`.

1.  Navigate to the specific exercise directory (e.g., `ex00`, `ex01`, etc.).
    ```bash
    cd exXX
    ```
2.  Use `make` to compile the project.
    ```bash
    make
    ```
3.  This will create an executable file named after the module (e.g., `ex00`).
4.  Run the executable:
    ```bash
    ./exXX
    ```

**Other Make Commands:**

*   `make clean`: Removes the object files (`*.o`).
*   `make fclean`: Removes object files and the executable.
*   `make re`: Performs `fclean` followed by `make`.

**Example (Compiling and running Exercise 01):**

```bash
cd ex01
make
./ex01
```