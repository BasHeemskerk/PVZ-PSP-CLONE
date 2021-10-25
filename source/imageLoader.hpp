#include "global.hpp"

namespace imageControl{
    extern Image *loadingScreen;
    extern Image *titleScreen;
    extern Image *cursor[5];
    extern Image *almanacCursor[2];

    extern Image *almanac[3];

    extern Image *settingsBg;

    extern Image *aboutPage;
    extern Image *moreGamesPage;

    extern Image *screenEdgeUi;

    void loadLoadingScreen();
    void unloadLoadingScreen();

    void loadMenuScreen();
    void unloadMenuScreen();

    void loadAlmanac();
    void unloadAlmanac();

    void loadCursor();
    void unloadCursor();

    void loadAlmanacCursor();
    void unloadAlmanacCursor();

    void loadSettingsBg();
    void unloadSettingsBg();

    void loadAboutPage();
    void unloadAboutPage();

    void loadMoreGames();
    void unloadMoreGames();

    void loadScreenEdheUi();
    void unloadScreenEdgeUi();

}

namespace spriteControl{

    extern Image *grassBall;
    extern Image *grassLine;

    extern Image *sunflowerSprites[27];
    extern Image *zombieSpritesStill[20];

    extern Image *slider;
    extern Image *knob;

    extern Image *numbersBig[10];
    extern Image *numbersSmall[10];

    void loadGrassBall();
    void unloadGrassBall();

    void loadGrassLine();
    void unloadGrassLine();


    void loadSunflowerSprites();
    void unloadSunFlowerSprites();

    void loadZombieStillSprites();
    void unloadZombieStillSprites();


    void loadOptionSlider();
    void unloadOptionSlider();

    void loadOptionKnob();
    void unloadOptionKnob();

    void loadNumbers();
    void unloadNumbers();
}

namespace gardenLoader{
    extern Image *day;
    extern Image *night;
    extern Image *pool;
    extern Image *fog;
    extern Image *roof;
    extern Image *boss;

    extern Image *sollRoll1;
    extern Image *sollRoll2;

    void loadDayImage();
    void loadDayEmptyImage();
    void loadNightImage();
    void loadPoolImage();
    void loadFogImage();
    void loadRoofImage();
    void loadBossImage();

    void unloadDayImage();
    void unloadDayEmptyImage();
    void unloadNightImage();
    void unloadPoolImage();
    void unloadFogImage();
    void unloadRoofImage();
    void unloadBossImage();

    void loadSoll1();
    void unloadSoll1();

    void loadSoll2();
    void unloadSoll2();
}