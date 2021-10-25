#include "global.hpp"
#include "imageLoader.hpp"

namespace infoAlmanac{

    extern int almanacPage;
    extern int cursorPos;
    extern int wichSunFlowerFrame;
    extern int wichZombieFrame;

    extern float sunflowerSpriteFps;
    extern float zombieSpriteFps;

    //day
    extern std::ifstream Peashooter_info;
    extern std::ifstream Sunflower_info;
    extern std::ifstream Cherrybomb_info;
    extern std::ifstream Wallnut_info;
    extern std::ifstream Potatomine_info;
    extern std::ifstream Snowpea_info;
    extern std::ifstream Chomper_info;
    extern std::ifstream Repeater_info;


    extern std::ifstream Puffshroom_info;
    extern std::ifstream Sunshroom_info;
    extern std::ifstream Fumeshroom_info;
    extern std::ifstream Gravebuster_info;
    extern std::ifstream Hypnoshroom_info;
    extern std::ifstream Scaredyshroom_info;
    extern std::ifstream Iceshroom_info;
    extern std::ifstream Doomshroom_info;


    extern std::ifstream Lilypad_info;
    extern std::ifstream Squash_info;
    extern std::ifstream Threepeater_info;
    extern std::ifstream Tanglekelp_info;
    extern std::ifstream Jalapeno_info;
    extern std::ifstream Spikeweed_info;
    extern std::ifstream Torchwood_info;
    extern std::ifstream Tallnut_info;


    extern std::ifstream Seashroom_info;
    extern std::ifstream Plantern_info;
    extern std::ifstream Cactus_info;
    extern std::ifstream Blover_info;
    extern std::ifstream Splitpea_info;
    extern std::ifstream Starfruit_info;
    extern std::ifstream Pumpkin_info;
    extern std::ifstream Magnetshroom_info;


    extern std::ifstream Cabbagepult_info;
    extern std::ifstream Flowerpot_info;
    extern std::ifstream Kernelpult_info;
    extern std::ifstream Coffeebean_info;
    extern std::ifstream Garlic_info;
    extern std::ifstream Umbrellaleaf_info;
    extern std::ifstream Marigold_info;
    extern std::ifstream Melonpult_info;


    void loadPlantInfoFiles();
    void unloadPlantInfoFiles();

    void loadZombieInfoFiles();

    void renderMainAlmanac();
    void renderCursor();

    void renderSunflower();
    void renderZombie();

    //void fpsCounter();

}