# Singly Linked List Implementation in C++

A custom implementation of a singly linked list data structure in C++ using templates for type flexibility and manual memory management.

## Overview

This project provides a templated `LinkedList` class that implements a dynamic data structure where elements are stored in nodes connected through pointers. The implementation supports operations at both ends of the list and provides various utility functions for list manipulation.

## Features

- **Template-based**: Works with any data type (int, float, string, custom objects, etc.)
- **Dynamic size**: Grows and shrinks as needed without pre-defined capacity
- **Memory efficient**: Only allocates memory for actual elements
- **Bidirectional operations**: Support for operations at both front and back
- **List manipulation**: Insert, delete, reverse, and search functionality
- **Bounds checking**: Includes error handling for invalid operations

## Class Interface

### Constructor
```cpp
LinkedList<T>()    // Default constructor - creates empty list
```

### Size Operations
```cpp
int size()         // Returns current number of elements
bool is_empty()    // Returns true if list is empty
```

### Element Access
```cpp
T value_at(int index)        // Returns element at given index
T front()                    // Returns first element
T back()                     // Returns last element
T value_n_from_end(int n)    // Returns nth element from end (1-indexed)
```

### Front Operations
```cpp
void push_front(T value)     // Adds element to the beginning
T pop_front()                // Removes and returns first element
```

### Back Operations
```cpp
void push_back(T value)      // Adds element to the end
T pop_back()                 // Removes and returns last element
```

### Insertion & Deletion
```cpp
void insert(int index, T value)  // Inserts element at specified position
void erase(int index)            // Removes element at specified index
void remove_value(T value)       // Removes first occurrence of specified value
```

### List Manipulation
```cpp
void reverse()               // Reverses the entire list
void print_all()             // Prints all elements (debugging utility)
```

## Usage Examples

```cpp
#include "LinkedList.h"
#include <iostream>

int main() {
    // Create a linked list of integers
    LinkedList<int> list;
    
    // Add elements to front and back
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    
    // Print list: 5 - 10 - 20 -
    list.print_all();
    
    // Access elements
    cout << "First element: " << list.front() << endl;        // 5
    cout << "Last element: " << list.back() << endl;          // 20
    cout << "Element at index 1: " << list.value_at(1) << endl; // 10
    
    // Insert at specific position
    list.insert(2, 15);  // Insert 15 at index 2
    list.print_all();    // 5 - 10 - 15 - 20 -
    
    // Access from end
    cout << "2nd from end: " << list.value_n_from_end(2) << endl; // 15
    
    // Remove elements
    list.pop_front();    // Remove first element
    list.erase(1);       // Remove element at index 1
    
    // Reverse the list
    list.reverse();
    list.print_all();
    
    return 0;
}
```

## Implementation Details

### Node Structure
```cpp
struct Node {
    T item;        // Data stored in the node
    Node* next;    // Pointer to next node
    Node(T value); // Constructor
};
```

### Memory Management
- Nodes are allocated dynamically using `new`
- Each node contains data and a pointer to the next node
- Head and tail pointers maintained for efficient operations
- Size counter maintained for O(1) size queries

### Performance Characteristics
- **Access by index**: O(n) - requires traversal from head
- **Front operations**: O(1) - direct access via head pointer
- **Back operations**: 
  - `push_back()`: O(1) - direct access via tail pointer
  - `pop_back()`: O(n) - requires traversal to find second-to-last node
- **Insert/Delete**: O(n) - requires traversal to position
- **Search**: O(n) - linear traversal required
- **Reverse**: O(n) - single pass through list

## Technical Notes

### Memory Considerations
- **No automatic cleanup**: Destructor not implemented - potential memory leaks
- **Manual memory management**: Uses `new` for node allocation
- **Tail pointer optimization**: Enables O(1) back insertion

### Potential Issues
1. **Memory leaks**: No destructor to clean up allocated nodes
2. **Dangling pointers**: Some operations may leave invalid pointer references
3. **Exception safety**: Limited exception handling in edge cases
4. **Copy semantics**: No copy constructor or assignment operator
5. **Iterator interface**: No standard iterator support

### Edge Cases Handled
- Operations on empty lists throw `std::out_of_range`
- Bounds checking for index-based operations
- Special handling for single-element lists

## Compilation

```bash
g++ -std=c++11 main.cpp -o linkedlist_program
```

## File Structure
```
├── LinkedList.h      # Header file with LinkedList class implementation
├── main.cpp          # Example usage (if provided)
└── README.md         # This documentation
```

## Comparison with std::list

| Feature | This Implementation | std::list |
|---------|-------------------|-----------|
| Type | Singly Linked | Doubly Linked |
| Back removal | O(n) | O(1) |
| Memory usage | Lower | Higher (prev pointers) |
| Bidirectional iteration | No | Yes |
| STL compatibility | No | Yes |

## Future Enhancements

- **Implement destructor** to prevent memory leaks
- **Add copy constructor and assignment operator**
- **Implement iterator interface** for STL compatibility
- **Add move semantics** (C++11)
- **Improve exception safety** with RAII principles
- **Consider doubly-linked implementation** for O(1) back operations
- **Add more utility functions** (find, contains, etc.)
- **Template specializations** for specific types

## Common Pitfalls

1. **Memory Management**: Remember to implement proper cleanup
2. **Index Bounds**: Always check if index is within valid range
3. **Empty List Operations**: Handle edge cases for empty lists
4. **Pointer Arithmetic**: Be careful with null pointer dereferencing

## Educational Value

This implementation demonstrates:
- Dynamic memory allocation and pointer manipulation
- Template programming in C++
- Linked data structure concepts
- Basic algorithm implementation (insertion, deletion, reversal)
- Exception handling patterns

## License

This is an educational implementation for learning purposes. Feel free to use and modify as needed.

---

*Note: This is a learning project and should not be used in production environments without proper memory management implementation. For production code, consider using `std::list` or `std::forward_list` from the C++ Standard Library.*
