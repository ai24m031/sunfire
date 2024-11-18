# What is a precompiled header? Name pros and cons:
A precompiled header (PCH) is a file that contains compiled information from commonly used header files to speed up the compilation process by reusing this precompiled data across multiple source files.
- pros
  - reduces compilation time by avoiding repetitive parsing of common headers.
  - useful in large projects with numerous headers.
  - ensures uniformity across multiple source files by using the same precompiled data.
- cons
  - the precompiled header file can be large, consuming significant memory.
  - managing and configuring precompiled headers can add complexity to the build system.
# Describe the layer of abstraction with your own words:
A layer of abstraction is a way to simplify complex systems by hiding unnecessary details and exposing only the relevant functionality. It allows users or developers to interact with a system at a higher level without needing to understand its inner workings, promoting clarity and modularity.
# Name the SOLID principles and describe them briefly:
- S - Single Responsibility Principle (SRP):
A class should have only one reason to change, meaning it should have a single, well-defined responsibility.
- O - Open/Closed Principle (OCP):
Software entities should be open for extension but closed for modification, allowing new features to be added without altering existing code.
- L - Liskov Substitution Principle (LSP):
Subtypes must be substitutable for their base types without altering the correctness of the program.
- I - Interface Segregation Principle (ISP):
Interfaces should be small and specific, ensuring classes only implement methods they actually use.
- D - Dependency Inversion Principle (DIP):
High-level modules should not depend on low-level modules; both should depend on abstractions. Abstractions should not depend on details; details should depend on abstractions.