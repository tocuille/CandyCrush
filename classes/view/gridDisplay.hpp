/**
 * File : 
 *  gridDisplay.hpp
 *
 * Decription :
 *  Class responsible of displaying a the entire grid.
 * 
 * Dependencies:
 *  componentDisplay.hpp
 *  candyDisplay.hpp
 *  stripedDisplay.hpp
 *  wrappedDisplay.hpp
 *  wallDisplay.hpp
 *  cellDisplay.hpp
 * 
 * Authors:
 *  Thomas O'Cuilleanain,
 *  Marcus Chretien
 * 
 */

#ifndef GRID_DISPLAY_HPP
#define GRID_DISPLAY_HPP

#include "animation/animationQueue.hpp"
#include "components/componentDisplay.hpp"
#include "components/candyDisplay.hpp"
#include "components/stripedDisplay.hpp"
#include "components/wrappedDisplay.hpp"
#include "components/specialDisplay.hpp"
#include "components/wallDisplay.hpp"
#include "components/cherryDisplay.hpp"
#include "components/hazelnutDisplay.hpp"
#include "components/frostingDisplay.hpp"
#include "cellDisplay.hpp"
#include "../shared/log.hpp"
#include "text/broadcast.hpp"

#include <memory>
#include <vector>
#include <queue>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

class GridDisplay {
    using CellMatrix = std::vector< std::vector<CellDisplay> >;
    CellMatrix visualGrid;
    
    using ComponentMatrix = std::vector< std::vector< std::shared_ptr<ComponentDisplay> > >;
    ComponentMatrix visualComponents;

    using CoordColour = std::pair< Point, int >;
    using CoordPair = std::pair< Point, Point >;
    enum animations{Pop, Fill, DropDown, DropLeft, DropRight, Swap};
    AnimationQueue animationQueue;

    CoordPair suggestion;
    
    int time = 0;
    const int suggestionTime = 90; 

    BroadcastBox broadcast;

    const int ROWS = Constants::ROWS;
    const int COLS = Constants::COLS;

public:
    GridDisplay();
    GridDisplay(const GridDisplay &) = default;
    GridDisplay(GridDisplay &&) = default;

    void draw();
    bool inAnimation() const;
    void notifyInit(const Point &coord, int type);

    /** Queues insert animation */
    void notifyInsert(const Point &coord, int type) {animationQueue.enqueueFill({{coord, type}});}
    void notifyInsert(const std::vector<CoordColour> &toInsert) {animationQueue.enqueueFill(toInsert);}

    /** Queues fill animation */
    void notifyFill(const std::vector<CoordColour> &toFill) {animationQueue.enqueueFill(toFill);}

    /** Queues insert animation */
    void notifyDrop(const std::vector<Point> &toDrop, int direction) {animationQueue.enqueueDrop(toDrop, direction);}

    /** Queues pop animation */
    void notifyPop(const std::vector<Point> &toPop) {animationQueue.enqueuePop(toPop);}

    void notifySuggestion(const Point &start, const Point &dest) {suggestion = {start, dest};}

    void notifySwap(const Point &start, const Point &dest);
    void notifyFailedSwap(const Point &start, const Point &dest);

    void notifySwapsLeft(int swaps) {broadcast.setSwaps(swaps);}
    void notifyNoSwaps();
    void notifyGameState(int state);
    void notifyObjective(int objType, int obj);
    void notifyObjective(int objType, int obj, int colour);
    

    /** Modifies score displayed */
    void notifyScore(int newScore) {broadcast.setScore(newScore);}

private:

    void won() {broadcast.setMessage("You won !");}
    void lost() {broadcast.setMessage("GameOver, you lost !");}

    /* Animations */
    void nextAnimation();
    void performFill();
    void performDrop(int direction);
    void performPop();
    void performSwap();
    void performSuggestion();

    /* Utility */
    Point calculateCenter(const Point &coord) const;
    std::shared_ptr<ComponentDisplay> factoryMethod(int row, int col, int component) const;

    // TEMP
    void package() const;
};

#endif