/**
 * File : 
 *  cell.hpp
 *
 * Decription :
 *  Class which represents a possible 'slot' in which a GameComponent can be in
 * 
 * Authors:
 *  Thomas O'Cuilleanain,
 *  Marcus Chretien
 */

#ifndef CELL_HPP
#define CELL_HPP

#include "gameComponent.hpp"

#include <memory>

class Cell {
    std::shared_ptr<GameComponent> occupied;
    std::vector< Cell * > vertNbs;
    std::vector< Cell * > horizNbs;
    std::vector< Cell * > belowNbs{nullptr, nullptr, nullptr};
    bool toPop = false;
public:
    /* Setters */
    void setOccupied(const std::shared_ptr<GameComponent> &gc) {occupied = gc;}
    void unOccupy() {setOccupied(nullptr);}
    void setVertNbs(const std::vector< Cell * > &nbs) {vertNbs = nbs;}
    void setHorizNbs(const std::vector< Cell * > &nbs) {horizNbs = nbs;}
    void setBelow(Cell * cell) {belowNbs[Constants::BELOW] = cell;}
    void setBelowLeft(Cell * cell) {belowNbs[Constants::BELOW_LEFT] = cell;}
    void setBelowRight(Cell * cell) {belowNbs[Constants::BELOW_RIGHT] = cell;}
    void willPop() {toPop = true;}
    void popped() {toPop = false;}
    
    /* Getters */
    std::shared_ptr<GameComponent> getOccupied() const {return occupied;}
    std::vector< Cell * > getVertNbs() const {return vertNbs;}
    std::vector< Cell * > getHorizNbs() const {return horizNbs;}
    Cell * getBelow(int direction) const {return belowNbs[direction];}
    //Cell * getBelowLeft() const {return belowNbs[Constants::BELOW_LEFT];}
    //Cell * getBelowRight() const {return belowNbs[Constants::BELOW_RIGHT];}
    bool getPop() const {return toPop;}
    
    std::string package() const;
};


#endif 
