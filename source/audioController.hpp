#include "global.hpp"

namespace audioControll{

    extern OSL_SOUND* menuMusic;

    extern OSL_SOUND* gardenDay;
    extern OSL_SOUND* gardenNight;

    extern OSL_SOUND* yardDay;
    extern OSL_SOUND* yardNight;

    extern OSL_SOUND* roofDay;
    extern OSL_SOUND* boss;

    extern OSL_SOUND* minigame;
    extern OSL_SOUND* start;


    void loadMenuMusic();
    void playMenuMusic();
    void unloadMenuMusic();

    void loadDayMusic();
    void playDayMusic();
    void unloadDayMusic();

    void loadNightMusic();
    void playNightMusic();
    void unloadNightMusic();

    void loadYardDayMusic();
    void playYardDayMusic();
    void unloadYardDayMusic();

    void loadYardFogMusic();
    void playYardFogMusic();
    void unloadYardFogMusic();

    void loadRoofMusic();
    void playRoofMusic();
    void unloadRoofMusic();

    void loadBossMusic();
    void playBossMusic();
    void unloadBossMusic();



    void loadMinigameMusic();
    void playMinigameMusic();
    void unloadMinigameMusic();

    void loadStartMusic();
    void playStartMusic();
    void unloadStartMusic();
}

namespace sfxControl{

}