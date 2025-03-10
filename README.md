C++ Modules (CPP Modules) - 42 School
The C++ Modules are a series of progressive projects in 42’s curriculum designed to teach object-oriented programming (OOP), modern C++ features, and advanced software design. Starting with foundational syntax and escalating to template metaprogramming and concurrency, these modules challenge students to write efficient, maintainable, and idiomatic C++ code while adhering to strict standards (C++98/11/14/17/20).
Module Progression & Objectives

Each module builds on the previous one, focusing on specific C++ concepts and paradigms. Below is an overview of the typical structure (specifics may vary by campus):
Module 00–02: Fundamentals

Focus: Syntax, classes, streams, and basic OOP.
Key Requirements:

    Classes & Objects: Implement classes with member functions, attributes, and access specifiers (public, private).

    Initialization & Destruction: Use constructors, destructors, and the Rule of Three (copy constructor, assignment operator, destructor).

    Streams: Overload << and >> operators for custom I/O.

    Namespaces: Organize code into logical groups.
    Projects:

    Phonebook: A CLI contact manager using classes and file I/O.

    Fixed-Point Numbers: Implement a fixed-point arithmetic class.

Module 03–04: Inheritance & Polymorphism

Focus: Inheritance, abstract classes, interfaces, and exceptions.
Key Requirements:

    Inheritance: Derive classes using public, protected, and private inheritance.

    Polymorphism: Use virtual functions, abstract classes, and runtime polymorphism.

    Dynamic Casting: Safely cast between base and derived classes.

    Exceptions: Handle errors with try, catch, and custom exception classes.
    Projects:

    Animal Hierarchy: Model animals with inheritance (e.g., Dog → Animal).

    Interface Design: Create abstract classes for reusable components.

Module 05–07: STL, Templates, and Advanced Features

Focus: Standard Template Library (STL), templates, and modern C++.
Key Requirements:

    STL Containers: Master vector, list, map, stack, and algorithms.

    Templates: Write generic code with function/class templates.

    Move Semantics: Use rvalue references (&&), std::move, and avoid unnecessary copies.

    RAII: Manage resources (memory, files) with smart pointers (unique_ptr, shared_ptr).
    Projects:

    Bitcoin Exchange: Simulate currency conversion using STL containers and file parsing.

    Template Containers: Reimplement STL-like containers (e.g., vector, map).

Module 08: Template Metaprogramming

Focus: Compile-time computation and advanced templates.
Key Requirements:

    Template Specialization: Optimize code for specific types.

    Type Traits: Use std::enable_if, std::is_integral, etc., for conditional compilation.

    Variadic Templates: Handle variable argument lists (e.g., std::tuple).

    SFINAE: Substitution Failure Is Not An Error – control overload resolution.
    Projects:

    Compile-Time Utilities: Create type-safe containers or mathematical operations resolved at compile time.

Module 09 (Bonus): Multithreading & Concurrency

Focus: Parallel programming and thread safety.
Key Requirements:

    Thread Management: Use std::thread, std::async, and std::future.

    Mutexes & Locks: Synchronize data access with std::mutex, std::lock_guard.

    Condition Variables: Coordinate threads with std::condition_variable.

    Atomic Operations: Ensure thread-safe operations with std::atomic.
    Projects:

    Parallel Algorithms: Implement multithreaded sorting or matrix multiplication.

Technical Emphasis

    Memory Management: Avoid leaks with RAII and smart pointers (no new/delete in later modules).

    Code Quality: Follow C++ Core Guidelines, enforce const-correctness, and write DRY code.

    Performance: Optimize for speed and memory (e.g., move semantics, reserve STL capacity).

    Modern Standards: Use features from C++11/14/17 (e.g., auto, lambdas, range-based loops).

Learning Outcomes

    OOP Mastery: Design hierarchies with encapsulation, inheritance, and polymorphism.

    Generic Programming: Write reusable code with templates and STL.

    Resource Management: Leverage RAII and smart pointers for safety.

    Concurrency: Build thread-safe, parallelized applications.

    Metaprogramming: Solve problems at compile time with templates.

Why C++ Modules?

These projects transform students into proficient C++ engineers, capable of tackling systems programming, game engines, high-frequency trading, and embedded systems. By enforcing strict adherence to modern practices, 42 ensures graduates write code that is fast, safe, and scalable.