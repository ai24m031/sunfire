# What is the difference between a dynamic linked library and a static library?
 * static
   * integrated into the program during compilation
   * Code is copied directly into the final executable
   * increasing its size, No external dependency is required at runtime
 * dynamic
   * linked at runtime, not during compilation
   * the program relies on the external library file, keeping the executable smaller
   * Allows updates or changes to the library without recompiling the program
# Describe a logging system with your own words:
Records events, errors, and messages during program execution to aid debugging and monitoring.
# What is a Design Pattern?
A Design Pattern is a reusable, general solution to a common problem in software design. It provides a template or guideline for solving recurring design challenges in a structured and efficient way, improving code readability, scalability, and maintainability.
# Name and describe 2 Design Patterns (except facade or adapter):
## Singleton Pattern
- Purpose: Ensures a class has only one instance and provides a global access point to it.
- Use Case: Managing shared resources, like a configuration manager or a logging service.
## Observer Pattern
- Purpose: Establishes a one-to-many dependency where changes in one object (subject) are notified to all dependent objects (observers).
- Use Case: Implementing event systems or pub-sub models, such as in GUIs or real-time data updates.