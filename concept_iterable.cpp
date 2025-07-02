
#include <iostream>
#include <vector>
#include <list>
#include <concepts>

// Define the Iterable concept
template<typename T>
concept Iterable = requires(T a) {
    { std::begin(a) } -> std::input_iterator;
    { std::end(a) } -> std::sentinel_for<decltype(std::begin(a))>;
};

// A generic function that prints elements of any iterable
void printElements(const Iterable auto& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::list<std::string> lst = {"hello", "world"};

    printElements(vec);
    printElements(lst);

    return 0;
}
