#include <SFML/Graphics.hpp>
#include "turtle.h"

const sf::Vector2f canvas_size{1024.f, 768.f};
const sf::Vector2f canvas_center = canvas_size * .5f;

class dragon {
public:
    dragon(sf::Vector2f const& pos, unsigned const n): t{pos} { X(n); }
    void draw(sf::RenderWindow& canvas) const { t.draw(canvas); }
private:
    void X(unsigned const n) { if (n > 0) L("X+YF+", n); }
    void Y(unsigned const n) { if (n > 0) L("-FX-Y", n); }
    void L(std::string const& s, unsigned const n) {
        for (auto const ch: s) {
            if      (ch == '-') t.left(90);
            else if (ch == '+') t.right(90);
            else if (ch == 'X') X(n - 1);
            else if (ch == 'Y') Y(n - 1);
            else if (ch == 'F') t.forward(side);
        }
    }
    turtle t;
    unsigned side = 12;
};

int main() {
    dragon d{canvas_center, 10};
    sf::RenderWindow w{sf::VideoMode(canvas_size.x, canvas_size.y), "Dragon"};
    while (w.isOpen()) {
        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) w.close();
        }
        w.clear();
        d.draw(w);
        w.display();
    }
}
