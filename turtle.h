#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include <vector>

class turtle
{
public:
    enum { EAST = 0, NORTH = 90, WEST = 180, SOUTH = 270 };

    turtle(sf::Vector2f const& position, unsigned heading = NORTH);
    void forward(unsigned distance);
    void backward(unsigned distance);
    void go_to(sf::Vector2f const& new_position);
    void home();
    void right(unsigned angle);
    void left(unsigned angle);
    void pendown();
    void penup();
    void draw(sf::RenderWindow& canvas) const;
    sf::Vector2f position() const;
private:
    sf::Vector2f const position0_;
    sf::Vector2f position_;
    unsigned const heading0_;
    unsigned heading_;
    bool pendown_ = true;
    std::vector<sf::Vertex> lines_;
};

#endif
