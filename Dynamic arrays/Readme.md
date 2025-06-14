# Dynamic Vector Implementation in C++

A custom implementation of a dynamic array (vector) class in C++ using templates for type flexibility and manual memory management.

## Overview

This project provides a templated `Vector` class that mimics the behavior of `std::vector` with dynamic resizing capabilities. The implementation focuses on fundamental concepts of dynamic memory allocation, template programming, and container design patterns.

## Features

- **Template-based**: Works with any data type (int, float, string, custom objects, etc.)
- **Dynamic resizing**: Automatically grows when capacity is exceeded
- **Memory management**: Handles allocation and deallocation internally
- **Standard operations**: Push, pop, insert, delete, and search functionality
- **Bounds checking**: Includes error handling for out-of-bounds access

## Class Interface

### Constructor & Destructor
```cpp
Vector<T>()        // Default constructor - creates empty vector with capacity 1
~Vector()          // Destructor - cleans up allocated memory
```

### Capacity Operations
```cpp
int Size()         // Returns current number of elements
int Capacity()     // Returns current capacity
bool is_empty()    // Returns true if vector is empty
```

### Element Access
```cpp
T at(int index)    // Returns element at given index (with bounds checking)
```

### Modifiers
```cpp
void push(T item)              // Adds element to the end
void insert(int index, T item) // Inserts element at specified position
void prepend(T item)           // Adds element to the beginning
T pop()                        // Removes and returns last element
void delete_element(int index) // Removes element at specified index
void remove(T item)            // Removes all occurrences of specified item
```

### Search
```cpp
T find(T item)     // Returns index of first occurrence, -1 if not found
```

## Usage Examples

```cpp
#include "Vector.h"

int main() {
    // Create a vector of integers
    Vector<int> numbers;
    
    // Add elements
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    
    // Access elements
    cout << "First element: " << numbers.at(0) << endl;
    
    // Insert at specific position
    numbers.insert(1, 15);  // Insert 15 at index 1
    
    // Search for element
    int index = numbers.find(20);
    if (index != -1) {
        cout << "Found 20 at index: " << index << endl;
    }
    
    // Remove element
    numbers.pop();  // Remove last element
    
    return 0;
}
```

## Implementation Details

### Memory Management
- Initial capacity is set to 1
- Capacity doubles when current capacity is exceeded
- Uses `new[]` and `delete[]` for dynamic allocation
- Automatic cleanup in destructor

### Growth Strategy
- When `size >= capacity`, the vector automatically resizes to `capacity * 2`
- The `resize()` function handles memory reallocation and data copying

### Error Handling
- Bounds checking in `at()` method throws `std::out_of_range` exception
- Pop operation on empty vector throws exception
- Insert/delete operations validate indices

## Technical Notes

### Potential Issues
1. **Copy Constructor/Assignment**: Not implemented - could lead to shallow copy issues
2. **Move Semantics**: Not implemented - missing modern C++ optimizations
3. **Iterator Support**: No iterator interface provided
4. **Exception Safety**: Limited exception safety guarantees

### Performance Characteristics
- **Access**: O(1) random access
- **Push/Pop**: O(1) amortized time
- **Insert/Delete**: O(n) due to element shifting
- **Search**: O(n) linear search

## Compilation

```bash
g++ -std=c++11 main.cpp -o vector_program
```

## File Structure
```
├── Vector.h          # Header file with Vector class implementation
├── main.cpp          # Example usage (if provided)
└── README.md         # This documentation
```

## Future Enhancements

- Implement copy constructor and assignment operator
- Add move semantics (C++11)
- Provide iterator interface
- Add more STL-compatible methods
- Implement exception safety guarantees
- Add capacity shrinking for memory efficiency

## License

This is an educational implementation for learning purposes. Feel free to use and modify as needed.

---

*Note: This is a learning project and should not be used in production environments. For production code, use `std::vector` from the C++ Standard Library.*
