#include "candyDisplay.hpp"

void CandyDisplay::draw() const {
    fl_color(fl_colour);
    fl_begin_polygon();
    fl_circle(getCenter().x, 
                getCenter().y, 
                Constants::CANDY_RADIUS);
    fl_end_polygon();
}