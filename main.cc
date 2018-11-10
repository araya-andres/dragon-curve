#include <SFML/Graphics.hpp>
#include <iostream>

#include "turtle.h"

int main() {
    auto canvas_size = sf::Vector2f{800, 600};
    turtle t{canvas_size * .5f};
    // draw a triangle
    t.left(30);
    t.forward(300);
    t.left(120);
    t.forward(300);
    t.left(120);
    t.forward(300);

    t.penup();
    t.forward(20);
    t.pendown();

    // draw a square
    t.left(90);
    t.forward(200);
    t.right(90);
    t.forward(200);
    t.right(90);
    t.forward(200);
    t.right(90);
    t.forward(200);

    sf::RenderWindow window{sf::VideoMode(canvas_size.x, canvas_size.y), "Turtle"};
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        t.draw(window);
        window.display();
    }
}
