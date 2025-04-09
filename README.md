# Smart Pointers - C++ Implementation

This is a simple implementation of custom smart pointers in C++ to better understand the concepts of move semantics and memory management.

## Overview

This project contains a custom implementation of the `MyUniquePointer` class, a smart pointer that mimics the behavior of `std::unique_ptr`. The `MyUniquePointer` is designed to manage the lifetime of dynamically allocated objects and automatically delete them when they go out of scope.

### Features For MyUniquePointer
- Move Semantics: Ownership of resources can be transferred (moved) instead of copied.
- Disallows Copying: The `copy constructor` and `copy assignment operator` are deleted to ensure that objects are not accidentally copied.
- Automatic Memory Management: The allocated memory is automatically freed when the `MyUniquePointer` goes out of scope.


