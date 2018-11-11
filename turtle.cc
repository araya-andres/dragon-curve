#include "turtle.h"
#include <cmath>

turtle::turtle(sf::Vector2f const& position, unsigned heading)
    : position0_{position}
    , position_{position0_}
    , heading0_{heading}
    , heading_{heading0_} {
}

void turtle::forward(unsigned const distance) {
    auto alpha = M_PI * heading_ / 180; // in radians
    auto delta = sf::Vector2f{cosf(alpha), -sinf(alpha)} * (float)distance;
    auto new_position = position_ + delta;
    if (pendown_) {
        lines_.push_back(position_);
        lines_.push_back(new_position);
    }
    position_ = new_position;
}

void turtle::backward(unsigned const distance) {
    left(180);
    forward(distance);
    left(180);
}

void turtle::go_to(sf::Vector2f const& new_position) {
    position_ = new_position;
}

void turtle::home() {
    position_ = position0_;
    heading_ = heading0_;
}

void turtle::right(unsigned const angle) {
    left(360 - angle % 360);
}

void turtle::left(unsigned const angle) {
    heading_ = (heading_ + angle) % 360;
}

void turtle::pendown() {
    pendown_ = true;
}

void turtle::penup() {
    pendown_ = false;
}

void turtle::draw(sf::RenderWindow& canvas) const {
    canvas.draw(lines_.data(), lines_.size(), sf::Lines);
}

sf::Vector2f turtle::position() const {
    return position_;
}
