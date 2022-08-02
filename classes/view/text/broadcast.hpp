#ifndef BROADCAST_HPP
#define BROADCAST_HPP

#include "broadcastText.hpp"
#include "scoreDisplay.hpp"
#include "../shapes/rectangle.hpp"

class BroadcastBox {
    Rectangle box;
    BroadcastText text;
    ScoreDisplay score;
public:
    BroadcastBox(const std::string &s = "")
     : box{Point{static_cast<int>(Constants::WINDOW_WIDTH / 2), 125}, 
            Constants::WALL, Constants::GAME_WINDOW_Xf - Constants::GAME_WINDOW_Xi, 150, FL_BORDER_FRAME}, 
        text{box.getCenter(), 30, s}, score{box.getCenter(), 15} {}

    void clear() {text.clear();}
    void setMessage(const std::string &s) {text.setText(s);}
    void setMessage(std::string &&s) {text.setText(s);}

    void setScore(int newScore) {score.setText(std::to_string(newScore));}

    void draw() const;
};


#endif