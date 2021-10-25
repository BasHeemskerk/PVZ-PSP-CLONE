#include "global.hpp"
#include "imageLoader.hpp"
#include "audioController.hpp"

namespace level{

    extern int wichWorld;
    extern int wichLevel;

    extern int wichZombieSprite1;
    extern int wichZombieSprite2;
    extern int wichZombieSprite3;
    extern int wichZombieSprite4;

    extern bool ready;

    void loadSoll();
    void loadLevel();
    void loadStillZombies();

    void renderLevel();
    void setDifficulty();

    void renderSoll();
    void renderScreenEdge();
    void renderZombiesStill();
}