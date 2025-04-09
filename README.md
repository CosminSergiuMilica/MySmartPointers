# Smart Pointers - C++ Implementation

This is a simple implementation of custom smart pointers in C++ to better understand the concepts of move semantics and memory management.

## Overview

This project includes a custom implementation of two smart pointers: MyUniquePointer and MySharedPointer.

`MyUniquePointer`: This smart pointer mimics the behavior of `std::unique_ptr`. It is designed to manage the lifetime of dynamically allocated objects and automatically delete them when they go out of scope. MyUniquePointer ensures exclusive ownership, meaning that only one instance can own a resource at a time. It also implements move semantics, disallowing copies of the pointer and transferring ownership when necessary.

`MySharedPointer`: This smart pointer mimics the behavior of `std::shared_ptr`. It manages the lifetime of a dynamically allocated object while allowing multiple instances to share ownership of the same object. It uses reference counting to keep track of how many pointers are sharing the resource, and the memory is automatically freed when the last MySharedPointer is destroyed.

### Features For MyUniquePointer
- Move Semantics: Ownership of resources can be transferred (moved) instead of copied.
- Disallows Copying: The `copy constructor` and `copy assignment operator` are deleted to ensure that objects are not accidentally copied.
- Automatic Memory Management: The allocated memory is automatically freed when the `MyUniquePointer` goes out of scope.

### Features For MySharedPointer
- Reference Counting: MySharedPointer uses a reference count to keep track of the number of instances that hold the same object. When no more instances are holding the object, the allocated memory is automatically freed.
- Shared Ownership: It allows multiple smart pointers to hold the same object simultaneously. Resources are only released when the last shared pointer is destroyed.
- Move Semantics: Just like MyUniquePointer, MySharedPointer supports moving ownership of resources. This allows transferring ownership between instances without making unnecessary copies of the data.
- Disallows Copying: MySharedPointer can be copied, but it ensures the reference count is updated correctly. The copy constructor and assignment operator ensure proper handling of the reference count.
