#include "imageLoader.hpp"

namespace imageControl{

    Image *loadingScreen;
    Image *titleScreen;
    Image *cursor[5];
    Image *almanacCursor[2];

    Image *almanac[3];

    Image *settingsBg;

    Image *aboutPage;
    Image *moreGamesPage;

    Image *screenEdgeUi;

    void loadLoadingScreen(){
        loadingScreen = loadPng("romfs/images/menu/loadingScreen.png");
    }

    void unloadLoadingScreen(){
        freeImage(loadingScreen);
    }


    void loadMenuScreen(){
        titleScreen = loadPng("romfs/images/menu/main.png");
    }

    void unloadMenuScreen(){
        freeImage(titleScreen);
    }

    
    void loadAlmanac(){
        almanac[0] = loadPng("romfs/images/menu/misc/selectorAlmanac.png");
        almanac[1] = loadPng("romfs/images/menu/misc/plantAlmanac.png");
        almanac[2] = loadPng("romfs/images/menu/misc/zombieAlmanac.png");
    }

    void unloadAlmanac(){
        freeImage(almanac[0]);
        freeImage(almanac[1]);
        freeImage(almanac[2]);
    }


    void loadCursor(){
        cursor[0] = loadPng("romfs/images/menu/ui/cursor1.png");
        cursor[1] = loadPng("romfs/images/menu/ui/cursor2.png");
        cursor[2] = loadPng("romfs/images/menu/ui/cursor3.png");
        cursor[3] = loadPng("romfs/images/menu/ui/cursor4.png");
        cursor[4] = loadPng("romfs/images/menu/ui/cursor5.png");
    }

    void unloadCursor(){
        freeImage(cursor[0]);
        freeImage(cursor[1]);
        freeImage(cursor[2]);
        freeImage(cursor[3]);
        freeImage(cursor[4]);
    }


    void loadAlmanacCursor(){
        almanacCursor[0] = loadPng("romfs/images/menu/misc/cursorPlants.png");
        almanacCursor[1] = loadPng("romfs/images/menu/misc/cursorZombie.png");
    }

    void unloadAlmanacCursor(){
        freeImage(almanacCursor[0]);
        freeImage(almanacCursor[1]);
    }


    void loadSettingsBg(){
        settingsBg = loadPng("romfs/images/menu/settings/background.png");
    }

    void unloadSettingsBg(){
        freeImage(settingsBg);
    }


    void loadAboutPage(){
        aboutPage = loadPng("romfs/images/menu/misc/about.png");
    }

    void unloadAboutPage(){
        freeImage(aboutPage);
    }


    void loadMoreGames(){
        moreGamesPage = loadPng("romfs/images/menu/misc/moreGames.png");
    }

    void unloadMoreGames(){
        freeImage(moreGamesPage);
    }


    void loadScreenEdheUi(){
        screenEdgeUi = loadPng("romfs/images/game/ui/screenEdge.png");
    }

    void unloadScreenEdgeUi(){
        freeImage(screenEdgeUi);
    }

}

namespace spriteControl{

    Image *grassBall;
    Image *grassLine;

    Image *sunflowerSprites[27];
    Image *zombieSpritesStill[20];

    Image *slider;
    Image *knob;

    Image *numbersBig[10];
    Image *numbersSmall[10];

    void loadGrassBall(){
        grassBall = loadPng("romfs/sprites/menu/load/grassball.png");
    }

    void unloadGrassBall(){
        freeImage(grassBall);
    }


    void loadGrassLine(){
        grassLine = loadPng("romfs/sprites/menu/load/grassline.png");
    }

    void unloadGrassLine(){
        freeImage(grassLine);
    }

    void loadSunflowerSprites(){
        sunflowerSprites[0] = loadPng("romfs/sprites/game/plants/sunflower/sunflower1.png");
        sunflowerSprites[1] = loadPng("romfs/sprites/game/plants/sunflower/sunflower2.png");
        sunflowerSprites[2] = loadPng("romfs/sprites/game/plants/sunflower/sunflower3.png");
        sunflowerSprites[3] = loadPng("romfs/sprites/game/plants/sunflower/sunflower4.png");
        sunflowerSprites[4] = loadPng("romfs/sprites/game/plants/sunflower/sunflower5.png");
        sunflowerSprites[5] = loadPng("romfs/sprites/game/plants/sunflower/sunflower6.png");
        sunflowerSprites[6] = loadPng("romfs/sprites/game/plants/sunflower/sunflower7.png");
        sunflowerSprites[7] = loadPng("romfs/sprites/game/plants/sunflower/sunflower8.png");
        sunflowerSprites[8] = loadPng("romfs/sprites/game/plants/sunflower/sunflower9.png");
        sunflowerSprites[9] = loadPng("romfs/sprites/game/plants/sunflower/sunflower10.png");
        sunflowerSprites[10] = loadPng("romfs/sprites/game/plants/sunflower/sunflower11.png");
        sunflowerSprites[11] = loadPng("romfs/sprites/game/plants/sunflower/sunflower12.png");
        sunflowerSprites[12] = loadPng("romfs/sprites/game/plants/sunflower/sunflower13.png");
        sunflowerSprites[13] = loadPng("romfs/sprites/game/plants/sunflower/sunflower14.png");
        sunflowerSprites[14] = loadPng("romfs/sprites/game/plants/sunflower/sunflower15.png");
        sunflowerSprites[15] = loadPng("romfs/sprites/game/plants/sunflower/sunflower16.png");
        sunflowerSprites[16] = loadPng("romfs/sprites/game/plants/sunflower/sunflower17.png");
        sunflowerSprites[17] = loadPng("romfs/sprites/game/plants/sunflower/sunflower18.png");
        sunflowerSprites[18] = loadPng("romfs/sprites/game/plants/sunflower/sunflower19.png");
        sunflowerSprites[19] = loadPng("romfs/sprites/game/plants/sunflower/sunflower20.png");
        sunflowerSprites[20] = loadPng("romfs/sprites/game/plants/sunflower/sunflower21.png");
        sunflowerSprites[21] = loadPng("romfs/sprites/game/plants/sunflower/sunflower22.png");
        sunflowerSprites[22] = loadPng("romfs/sprites/game/plants/sunflower/sunflower23.png");
        sunflowerSprites[23] = loadPng("romfs/sprites/game/plants/sunflower/sunflower24.png");
        sunflowerSprites[24] = loadPng("romfs/sprites/game/plants/sunflower/sunflower25.png");
        sunflowerSprites[25] = loadPng("romfs/sprites/game/plants/sunflower/sunflower26.png");
        sunflowerSprites[26] = loadPng("romfs/sprites/game/plants/sunflower/sunflower27.png");
        //sunflowerSprites[27] = loadPng("romfs/sprites/game/plants/sunflower/sunflower28.png");
    }

    void unloadSunFlowerSprites(){
        freeImage(sunflowerSprites[0]);
        freeImage(sunflowerSprites[1]);
        freeImage(sunflowerSprites[2]);
        freeImage(sunflowerSprites[3]);
        freeImage(sunflowerSprites[4]);
        freeImage(sunflowerSprites[5]);
        freeImage(sunflowerSprites[6]);
        freeImage(sunflowerSprites[7]);
        freeImage(sunflowerSprites[8]);
        freeImage(sunflowerSprites[9]);
        freeImage(sunflowerSprites[10]);
        freeImage(sunflowerSprites[11]);
        freeImage(sunflowerSprites[12]);
        freeImage(sunflowerSprites[13]);
        freeImage(sunflowerSprites[14]);
        freeImage(sunflowerSprites[15]);
        freeImage(sunflowerSprites[16]);
        freeImage(sunflowerSprites[17]);
        freeImage(sunflowerSprites[18]);
        freeImage(sunflowerSprites[19]);
        freeImage(sunflowerSprites[20]);
        freeImage(sunflowerSprites[21]);
        freeImage(sunflowerSprites[22]);
        freeImage(sunflowerSprites[23]);
        freeImage(sunflowerSprites[24]);
        freeImage(sunflowerSprites[25]);
        freeImage(sunflowerSprites[26]);
        //freeImage(sunflowerSprites[27]);
    }


    void loadZombieStillSprites(){
        zombieSpritesStill[0] = loadPng("romfs/sprites/game/zombies/still/zombie1.png");
        zombieSpritesStill[1] = loadPng("romfs/sprites/game/zombies/still/zombie2.png");
        zombieSpritesStill[2] = loadPng("romfs/sprites/game/zombies/still/zombie3.png");
        zombieSpritesStill[3] = loadPng("romfs/sprites/game/zombies/still/zombie4.png");
        zombieSpritesStill[4] = loadPng("romfs/sprites/game/zombies/still/zombie5.png");
        zombieSpritesStill[5] = loadPng("romfs/sprites/game/zombies/still/zombie6.png");
        zombieSpritesStill[6] = loadPng("romfs/sprites/game/zombies/still/zombie7.png");
        zombieSpritesStill[7] = loadPng("romfs/sprites/game/zombies/still/zombie8.png");
        zombieSpritesStill[8] = loadPng("romfs/sprites/game/zombies/still/zombie9.png");
        zombieSpritesStill[9] = loadPng("romfs/sprites/game/zombies/still/zombie10.png");
        zombieSpritesStill[10] = loadPng("romfs/sprites/game/zombies/still/zombie11.png");
        zombieSpritesStill[11] = loadPng("romfs/sprites/game/zombies/still/zombie12.png");
        zombieSpritesStill[12] = loadPng("romfs/sprites/game/zombies/still/zombie13.png");
        zombieSpritesStill[13] = loadPng("romfs/sprites/game/zombies/still/zombie14.png");
        zombieSpritesStill[14] = loadPng("romfs/sprites/game/zombies/still/zombie15.png");
        zombieSpritesStill[15] = loadPng("romfs/sprites/game/zombies/still/zombie16.png");
        zombieSpritesStill[16] = loadPng("romfs/sprites/game/zombies/still/zombie17.png");
        zombieSpritesStill[17] = loadPng("romfs/sprites/game/zombies/still/zombie18.png");
        zombieSpritesStill[18] = loadPng("romfs/sprites/game/zombies/still/zombie19.png");
        zombieSpritesStill[19] = loadPng("romfs/sprites/game/zombies/still/zombie20.png");
    }

    void unloadZombieStillSprites(){
        freeImage(zombieSpritesStill[0]);
        freeImage(zombieSpritesStill[1]);
        freeImage(zombieSpritesStill[2]);
        freeImage(zombieSpritesStill[3]);
        freeImage(zombieSpritesStill[4]);
        freeImage(zombieSpritesStill[5]);
        freeImage(zombieSpritesStill[6]);
        freeImage(zombieSpritesStill[7]);
        freeImage(zombieSpritesStill[8]);
        freeImage(zombieSpritesStill[9]);
        freeImage(zombieSpritesStill[10]);
        freeImage(zombieSpritesStill[11]);
        freeImage(zombieSpritesStill[12]);
        freeImage(zombieSpritesStill[13]);
        freeImage(zombieSpritesStill[14]);
        freeImage(zombieSpritesStill[15]);
        freeImage(zombieSpritesStill[16]);
        freeImage(zombieSpritesStill[17]);
        freeImage(zombieSpritesStill[18]);
        freeImage(zombieSpritesStill[19]);
    }


    void loadOptionSlider(){
        slider = loadPng("romfs/sprites/menu/options/Slider.png");
    }

    void unloadOptionSlider(){
        freeImage(slider);
    }


    void loadOptionKnob(){
        knob = loadPng("romfs/sprites/menu/options/Knob.png");
    }

    void unloadOptionKnob(){
        freeImage(knob);
    }


    void loadNumbers(){
        numbersBig[0] = loadPng("romfs/font/numbers/big/1.png");
        numbersBig[1] = loadPng("romfs/font/numbers/big/2.png");
        numbersBig[2] = loadPng("romfs/font/numbers/big/3.png");
        numbersBig[3] = loadPng("romfs/font/numbers/big/4.png");
        numbersBig[4] = loadPng("romfs/font/numbers/big/5.png");
        numbersBig[5] = loadPng("romfs/font/numbers/big/6.png");
        numbersBig[6] = loadPng("romfs/font/numbers/big/7.png");
        numbersBig[7] = loadPng("romfs/font/numbers/big/8.png");
        numbersBig[8] = loadPng("romfs/font/numbers/big/9.png");
        numbersBig[9] = loadPng("romfs/font/numbers/big/-.png");
        
        numbersSmall[0] = loadPng("romfs/font/numbers/small/1.png");
        numbersSmall[1] = loadPng("romfs/font/numbers/small/2.png");
        numbersSmall[2] = loadPng("romfs/font/numbers/small/3.png");
        numbersSmall[3] = loadPng("romfs/font/numbers/small/4.png");
        numbersSmall[4] = loadPng("romfs/font/numbers/small/5.png");
        numbersSmall[5] = loadPng("romfs/font/numbers/small/6.png");
        numbersSmall[6] = loadPng("romfs/font/numbers/small/7.png");
        numbersSmall[7] = loadPng("romfs/font/numbers/small/8.png");
        numbersSmall[8] = loadPng("romfs/font/numbers/small/9.png");
        numbersSmall[9] = loadPng("romfs/font/numbers/small/-.png");

    }

    void unloadNumbers(){
        freeImage(numbersBig[0]);
        freeImage(numbersBig[1]);
        freeImage(numbersBig[2]);
        freeImage(numbersBig[3]);
        freeImage(numbersBig[4]);
        freeImage(numbersBig[5]);
        freeImage(numbersBig[6]);
        freeImage(numbersBig[7]);
        freeImage(numbersBig[8]);
        freeImage(numbersBig[9]);

        freeImage(numbersSmall[0]);
        freeImage(numbersSmall[1]);
        freeImage(numbersSmall[2]);
        freeImage(numbersSmall[3]);
        freeImage(numbersSmall[4]);
        freeImage(numbersSmall[5]);
        freeImage(numbersSmall[6]);
        freeImage(numbersSmall[7]);
        freeImage(numbersSmall[8]);
        freeImage(numbersSmall[9]);
    }
}

namespace gardenLoader{

    Image *day;
    Image *night;
    Image *pool;
    Image *fog;
    Image *roof;
    Image *boss;

    Image *sollRoll1;
    Image *sollRoll2;


    void loadDayImage(){
        day = loadPng("romfs/images/game/day.png");
    }

    void loadDayEmptyImage(){
        day = loadPng("romfs/images/game/dayEmpty.png");
    }

    void loadNightImage(){
        night = loadPng("romfs/images/game/night.png");
    }

    void loadPoolImage(){
        pool = loadPng("romfs/images/game/pool.png");
    }

    void loadFogImage(){
        fog = loadPng("romfs/images/game/fog.png");
    }

    void loadRoofImage(){
        roof = loadPng("romfs/images/game/roof.png");
    }

    void loadBossImage(){
        boss = loadPng("romfs/images/game/boss.png");
    }


    void unloadDayImage(){
        freeImage(day);
    }

    void unloadNightImage(){
        freeImage(night);
    }

    void unloadPoolImage(){
        freeImage(pool);
    }

    void unloadFogImage(){
        freeImage(fog);
    }

    void unloadRoofImage(){
        freeImage(roof);
    }

    void unloadBossImage(){
        freeImage(boss);
    }


    void loadSoll1(){
        sollRoll1 = loadPng("romfs/sprites/game/sods/1sod.png");
    }

    void unloadSoll1(){
        freeImage(sollRoll1);
    }


    void loadSoll2(){
        sollRoll2 = loadPng("romfs/sprites/game/sods/3sod.png");
    }

    void unloadSoll2(){
        freeImage(sollRoll2);
    }
}