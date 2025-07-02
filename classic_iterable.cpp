
#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <iterator>

// Trait to detect if T is iterable
template<typename T>
class is_iterable {
private:
    template<typename U>
    static auto test(int) -> decltype(
        std::begin(std::declval<U&>()) != std::end(std::declval<U&>()),
        ++std::declval<decltype(std::begin(std::declval<U&>()))&>(),
        *std::begin(std::declval<U&>()),
        std::true_type{});

    template<typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

// Enable if T is iterable
template<typename T>
typename std::enable_if<is_iterable<T>::value, void>::type
printElements(const T& container) {
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
