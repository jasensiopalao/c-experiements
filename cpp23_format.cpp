#include <iostream>
#include <sstream>
#include <iomanip>
#include <format>  // New header in C++20
#include <print>  // New header in C++23
#include <chrono>

/*
C++23 offers several advantages over std::stringstream:
* Performance (IN THIS EXAMPLE, execution in godbolt would not confirm this clearly)
   * Compile-time format checking: std::format performs format string parsing at compile time, reducing runtime overhead.
   * Optimized for performance: std::format is designed to be more efficient than std::stringstream, especially for complex formatting.
* Readability:
   * Cleaner syntax: std::format uses a more concise and readable syntax, making the code easier to understand and maintain.
   * Positional arguments: You can use positional arguments in std::format, which can make the format string clearer.
* Type Safety: Compile-time type checking: std::format ensures that the types of the arguments match the format specifiers at compile time, reducing the risk of runtime errors.
* Memory Safety: Automatic buffer management: std::format handles buffer allocation and management automatically, reducing the risk of buffer overflows and other memory-related issues.
* Extensibility: Custom types: std::format supports formatting custom types by defining a formatter specialization, making it more flexible for complex applications.
*/

// Function using std::stringstream
std::string formatWithStringStream(int value, float pi) {
    std::stringstream ss;
    ss << "Integer: " << value << ", Float: " << std::fixed << std::setprecision(2) << pi;
    return ss.str();
}

// Function using std::format
std::string formatWithFormat(int value, float pi) {
    return std::format("Integer: {}, Float: {:.2f}", value, pi);
}

int main() {
    int value = 42;
    float pi = 3.14159f;

    // Measure execution time for std::stringstream
    auto start1 = std::chrono::high_resolution_clock::now();
    std::string formatted_ss = formatWithStringStream(value, pi);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_ss = end1 - start1;

    // Measure execution time for std::format
    auto start2 = std::chrono::high_resolution_clock::now();
    std::string formatted_fmt = formatWithFormat(value, pi);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_fmt = end2 - start2;

    // Print results
    std::cout << "std::stringstream result: " << formatted_ss << std::endl;
    std::cout << "Execution time: " << duration_ss.count() << " seconds" << std::endl;

    std::cout << "std::format result: " << formatted_fmt << std::endl;
    std::cout << "Execution time: " << duration_fmt.count() << " seconds" << std::endl;

    std::print("Integer: {}, Float: {:.2f}", value, pi);

    return 0;
}
