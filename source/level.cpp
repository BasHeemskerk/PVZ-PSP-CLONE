#include "level.hpp"

namespace level{

    int wichWorld = 1;
    int wichLevel = 1;

    int wichZombieSprite1 = 0;
    int wichZombieSprite2 = 0;
    int wichZombieSprite3 = 0;
    int wichZombieSprite4 = 0;

    float timePerFrame1 = 4;
    float timePerFrame2 = 4.2f;
    float timePerFrame3 = 2.6f;
    float timePerFrame4 = 3.1f;

    bool ready = false;
    float position = 120;

    void loadSoll(){
        if (wichWorld == 1){
            if (wichLevel == 1){
                gardenLoader::loadSoll1();
            }
            else if (wichLevel == 2){
                gardenLoader::loadSoll2();
            }
        }
    }

    void loadLevel(){
        if (wichWorld == 1){
            if (wichLevel < 3){
                gardenLoader::loadDayEmptyImage();
            }
            else{
                gardenLoader::loadDayImage();
            }
        }
        else if (wichWorld == 2){
            gardenLoader::loadNightImage();
        }
        else if (wichWorld == 3){
            gardenLoader::loadPoolImage();
        }
        else if (wichWorld == 4){
            gardenLoader::loadFogImage();
        }
        else if (wichWorld == 5){
            gardenLoader::loadRoofImage();
        }
        else if (wichWorld == 6){
            gardenLoader::loadBossImage();
        }
    }

    void loadStillZombies(){
        spriteControl::loadZombieStillSprites();
    }

    void renderLevel(){
        if (wichWorld == 1){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::day, 0, 0, 0);
        }
        else if (wichWorld == 2){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::night, 0, 0, 0);
        }
        else if (wichWorld == 3){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::pool, 0, 0, 0);
        }
        else if (wichWorld == 4){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::fog, 0, 0, 0);
        }
        else if (wichWorld == 5){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::roof, 0, 0, 0);
        }
        else if (wichWorld == 6){
            drawSpriteAlpha(0, 0, 512, 272, gardenLoader::boss, 0, 0, 0);
        }
    }

    void renderSoll(){
        if (wichWorld == 1){
            if (wichLevel == 1){
                drawSpriteAlpha(0, 0, 275, 58, gardenLoader::sollRoll1, 90, 115, 0);
            }
            else if (wichLevel == 2){
                drawSpriteAlpha(0, 0, 280, 140, gardenLoader::sollRoll2, 85, 75, 0);
            }
        }
    }

    void renderScreenEdge(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::screenEdgeUi, position, 0, 0);

        if (ready){
            if (position > 0){
                position -= 1;
            }
        }
    }

    void renderZombiesStill(){
        if (wichWorld == 1 || wichWorld == 2){
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite1], 380, -20, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite2], 396, 41, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite3], 370, 91, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite4], 387, 146, 0);
        }

        if (wichWorld == 3 || wichWorld == 4){
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite1], 390, -20, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite2], 406, 41, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite3], 412, 91, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite4], 403, 156, 0);
        }

        if (wichWorld == 5 || wichWorld == 6){
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite1], 380, -20, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite2], 396, 41, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite3], 370, 91, 0);
            drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieSprite4], 387, 146, 0);
        }

        if (timePerFrame1 <= 0){
            wichZombieSprite1 += 1;
            timePerFrame1 = 4;
        }
        else{
            timePerFrame1 -= 1;
        }

        if (timePerFrame2 <= 0){
            wichZombieSprite2 += 1;
            timePerFrame2 = 4.2f;
        }
        else{
            timePerFrame2 -= 1;
        }

        if (timePerFrame3 <= 0){
            wichZombieSprite3 += 1;
            timePerFrame3 = 2.6f;
        }
        else{
            timePerFrame3 -= 1;
        }

        if (timePerFrame4 <= 0){
            wichZombieSprite4 += 1;
            timePerFrame4 = 3.1f;
        }
        else{
            timePerFrame4 -= 1;
        }


        if (wichZombieSprite1 > 19){
            wichZombieSprite1 = 0;
        }

        if (wichZombieSprite2 > 19){
            wichZombieSprite2 = 0;
        }

        if (wichZombieSprite3 > 19){
            wichZombieSprite3 = 0;
        }

        if (wichZombieSprite4 > 19){
            wichZombieSprite4 = 0;
        }
    }

    void setDifficulty(){

    }
}