#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include <vector>

class turtle
{
public:
    turtle(sf::Vector2f const& position);
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
    sf::Vector2f const initial_pos_;
    sf::Vector2f position_;
    std::vector<sf::Vertex> lines_;
    int alpha_ = 90;
    bool pendown_ = true;
};

#endif
