#include "turtle.h"
#include <cmath>

turtle::turtle(sf::Vector2f const& position)
    : initial_pos_{position}
    , position_(initial_pos_) {
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

void turtle::go_to(sf::Vector2f const& new_position) {
    position_ = new_position;
}

void turtle::home() {
    position_ = initial_pos_;
    alpha_ = 90;
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

void turtle::draw(sf::RenderWindow& canvas) const {
    canvas.draw(lines_.data(), lines_.size(), sf::Lines);
}

sf::Vector2f turtle::position() const {
    return position_;
}
