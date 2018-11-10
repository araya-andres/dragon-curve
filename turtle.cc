#include "turtle.h"
#include <cmath>

turtle::turtle(const sf::Vector2f& position): position_(position) {
}

void turtle::forward(unsigned distance) {
    auto alpha = M_PI * alpha_ / 180; // in radians
    auto delta = sf::Vector2f{cosf(alpha), -sinf(alpha)} * (float)distance;
    auto new_position = position_ + delta;
    if (pendown_) {
        lines_.push_back(position_);
        lines_.push_back(new_position);
    }
    position_ = new_position;
}

void turtle::backward(unsigned distance) {
    left(180);
    forward(distance);
    left(180);
}

void turtle::right(unsigned angle) {
    angle %= 360;
    left(360 - angle);
}

void turtle::left(unsigned angle) {
    alpha_ = (alpha_ + angle) % 360;
}

void turtle::pendown() {
    pendown_ = true;
}

void turtle::penup() {
    pendown_ = false;
}

void turtle::draw(sf::RenderWindow& canvas) {
    canvas.draw(lines_.data(), lines_.size(), sf::Lines);
}
