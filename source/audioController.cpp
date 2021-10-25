#include "audioController.hpp"

namespace audioControll{

    OSL_SOUND* menuMusic;

    OSL_SOUND* gardenDay;
    OSL_SOUND* gardenNight;

    OSL_SOUND* yardDay;
    OSL_SOUND* yardFog;

    OSL_SOUND* roofDay;
    OSL_SOUND* boss;

    OSL_SOUND* minigame;
    OSL_SOUND* start;

    void loadMenuMusic(){
        menuMusic = oslLoadSoundFileWAV("romfs/music/menu/music.wav", OSL_FMT_NONE);
    }

    void playMenuMusic(){
        oslPlaySound(menuMusic, 0);

        oslSetSoundLoop(menuMusic, 1);
        if(oslGetSoundChannel(menuMusic) == -1){
            oslPlaySound(menuMusic, 0);
        }
    }

    void unloadMenuMusic(){
        oslDeleteSound(menuMusic);
    }


    void loadDayMusic(){
        gardenDay = oslLoadSoundFileWAV("romfs/music/game/garden.wav", OSL_FMT_NONE);
    }

    void playDayMusic(){
        oslPlaySound(gardenDay, 0);

        oslSetSoundLoop(gardenDay, 1);
        if (oslGetSoundChannel(gardenDay) == -1){
            oslPlaySound(gardenDay, 0);
        }
    }

    void unloadDayMusic(){
        oslDeleteSound(gardenDay);
    }


    void loadNightMusic(){
        gardenNight = oslLoadSoundFileWAV("romfs/music/game/garden2.wav", OSL_FMT_NONE);
    }

    void playNightMusic(){
        oslPlaySound(gardenNight, 0);

        oslSetSoundLoop(gardenNight, 1);
        if (oslGetSoundChannel(gardenNight) == -1){
            oslPlaySound(gardenNight, 0);
        }
    }

    void unloadNightMusic(){
        oslDeleteSound(gardenNight);
    }


    void loadYardDayMusic(){
        yardDay = oslLoadSoundFileWAV("romfs/music/game/yard.wav", OSL_FMT_NONE);
    }

    void playYardDayMusic(){
        oslPlaySound(yardDay, 0);

        oslSetSoundLoop(yardDay, 1);
        if (oslGetSoundChannel(yardDay) == -1){
            oslPlaySound(yardDay, 0);
        }
    }

    void unloadYardDayMusic(){
        oslDeleteSound(yardDay);
    }


    void loadYardFogMusic(){
        yardFog = oslLoadSoundFileWAV("romfs/music/game/fog.wav", OSL_FMT_NONE);
    }


    void playYardFogMusic(){
        oslPlaySound(yardFog, 0);

        oslSetSoundLoop(yardFog, 1);
        if (oslGetSoundChannel(yardFog) == -1){
            oslPlaySound(yardFog, 0);
        }
    }

    void unloadYardFogMusic(){
        oslDeleteSound(yardFog);
    }


    void loadRoofMusic(){
        roofDay = oslLoadSoundFileWAV("romfs/music/game/roof.wav", OSL_FMT_NONE);
    }

    void playRoofMusic(){
        oslPlaySound(roofDay, 0);

        oslSetSoundLoop(roofDay, 1);
        if (oslGetSoundChannel(roofDay) == -1){
            oslPlaySound(roofDay, 0);
        }
    }

    void unloadRoofMusic(){
        oslDeleteSound(roofDay);
    }


    void loadBossMusic(){
        boss = oslLoadSoundFileWAV("romfs/music/game/boss.wav", OSL_FMT_NONE);
    }

    void playBossMusic(){
        oslPlaySound(boss, 0);

        oslSetSoundLoop(boss, 1);
        if (oslGetSoundChannel(boss) == -1){
            oslPlaySound(boss, 0);
        }
    }

    void unloadBossMusic(){
        oslDeleteSound(boss);
    }


    void loadMinigameMusic(){
        minigame = oslLoadSoundFileWAV("romfs/music/game/minigame.wav", OSL_FMT_NONE);
    }

    void playMinigameMusic(){
        oslPlaySound(minigame, 0);

        oslSetSoundLoop(minigame, 1);
        if (oslGetSoundChannel(minigame) == -1){
            oslPlaySound(minigame, 0);
        }
    }

    void unloadMinigameMusic(){
        oslDeleteSound(minigame);
    }


    void loadStartMusic(){
        start = oslLoadSoundFileWAV("romfs/music/game/beforeStart.wav", OSL_FMT_NONE);
    }

    void playStartMusic(){
        oslPlaySound(start, 0);

        oslSetSoundLoop(start, 1);
        if (oslGetSoundChannel(start) == -1){
            oslPlaySound(start, 0);
        }
    }

    void unloadStartMusic(){
        oslDeleteSound(start);
    }
}

namespace sfxControl{

}