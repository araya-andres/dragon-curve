#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include <vector>

class turtle
{
public:
    turtle(const sf::Vector2f& position);
    void forward(unsigned distance);
    void backward(unsigned distance);
    void right(unsigned angle);
    void left(unsigned angle);
    void pendown();
    void penup();
    void draw(sf::RenderWindow& canvas);
private:
    sf::Vector2f position_;
    std::vector<sf::Vertex> lines_;
    int alpha_ = 90;
    bool pendown_ = true;
};

#endif
