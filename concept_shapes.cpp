
#include <iostream>
#include <concepts>

struct Circle {
    void draw() const {
        std::cout << "Drawing Circle\n";
    }
};

struct Square {
    void draw() const {
        std::cout << "Drawing Square\n";
    }
};

template<typename T>
concept Drawable = requires(T a) {
    { a.draw() } -> std::same_as<void>;
};

void render(const Drawable auto& shape) {
    shape.draw();
}

int main() {

    Circle c;
    Square s;

    render(c);
    render(s);

    return 0;
}
