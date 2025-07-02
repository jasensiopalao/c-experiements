
#include <iostream>
#include <memory>

struct Shape {
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

struct Square : Shape {
    void draw() const override {
        std::cout << "Drawing Square\n";
    }
};

void render(const Shape& shape) {
    shape.draw();
}

int main() {

    Circle c;
    Square s;

    render(c);
    render(s);

    return 0;
}
