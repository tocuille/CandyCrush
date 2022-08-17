#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <array>

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>


class Constants {
    const static std::array< int, 6 > candies;
public:

    /* Model Constants */
    enum directions{VERTICAL, HORIZONTAL, NO_DIRECTION} directions;
    static enum {LEFT, CENTER, RIGHT} below;
    static enum actions{DISPLACEMENT, SWAP, SUPPRESSION} actions;

    /* View Constants */
    static enum menuButtons{NOTHING, PLAY, BACK, GAME_OVER, GAME_ONGOING, LEVEL1, LEVEL2, LEVEL3} menuButtons;

    static const std::string badSwap;
    static const std::string gameWon;
    static const std::string gameLost;
    static const std::string shuffling;
    
    static const double FPS;
    static const double WINDOW_HEIGHT;
    static const double WINDOW_WIDTH;
    static const double GAME_WINDOW_Yi;
    static const double GAME_WINDOW_Xi;
    static const double GAME_WINDOW_Yf;
    static const double GAME_WINDOW_Xf;
    
    static const double CELL_SIZE;
    static const double HALVE_CELL_SIZE;
    static const double STEP_SIZE;
    static const double GAP_SIZE;
    static const double GRIDSIZE;
    static const double HALVE_GRIDSIZE;
    static const int COLS;
    static const int ROWS;

    static const double CANDY_RADIUS;

    static enum animTypes{IGNORE, CANT_IGNORE} animTypes;

    static enum blastTypes{NO_BLAST, SIMPLE, STRIPED, WRAPPED, SPECIAL} blastTypes;

    static enum objectiveTypes{POPS, INGREDIENT, FROSTINGS} objectives;

    static enum componentState{POPPED, NOT_POPPED} compStates;

    static enum components{RED, BLUE, GREEN, YELLOW, PURPLE, ORANGE, BLACK, NONE, ANY, EMPTY, WALL, FROSTING1, FROSTING2,

                            RED_STRIPED_BOMB_V, BLUE_STRIPED_BOMB_V, GREEN_STRIPED_BOMB_V, YELLOW_STRIPED_BOMB_V,
                            PURPLE_STRIPED_BOMB_V, ORANGE_STRIPED_BOMB_V,
                            RED_STRIPED_BOMB_H, BLUE_STRIPED_BOMB_H, GREEN_STRIPED_BOMB_H, YELLOW_STRIPED_BOMB_H,
                            PURPLE_STRIPED_BOMB_H, ORANGE_STRIPED_BOMB_H,

                            RED_WRAPPED_BOMB, BLUE_WRAPPED_BOMB, GREEN_WRAPPED_BOMB, YELLOW_WRAPPED_BOMB,
                            PURPLE_WRAPPED_BOMB, ORANGE_WRAPPED_BOMB,

                            CHERRY, HAZELNUT,

                            SPECIAL_BOMB} components;

    /** @brief Returns a random candy */
    static int randomCandy() {return candies[rand() % 6];}

    /** @brief Returns a random direction (horizontal / verical) */
    static int randomDirection() {return rand() % 2;}

    /** @brief Returns a random direction (horizontal / verical) */
    static bool isImmobile(int component) {return component == WALL || component == FROSTING1 || component == FROSTING2;}

    static int associatedColour(int component);
    static Fl_Color associatedFLColour(int colour);
    static int associatedBlast(int component);
    static int colourToSt(int colour, int direction);
    static int colourToWr(int colour);
    
};



#endif