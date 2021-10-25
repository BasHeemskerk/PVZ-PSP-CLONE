#include "load.hpp"

namespace gameLoader{

    float grassBallPos;
    float grassLinePos;
    float time = 4;
    float time2 = 4;

    float ballPos = 135;
    float grassLength = 20;

    void renderGrassBall(){
        drawSpriteAlpha(0, 0, 53, 51, spriteControl::grassBall, ballPos, 155, 0);

        if (time <= 4){
            ballPos += 1;
            time = 8;
        }
        else{
            time -= 1;
        }

        if (ballPos >= 300){
            ballPos = 300;
        }
    }

    void renderGrassLine(){
        drawSpriteAlpha(0, 0, grassLength, 19, spriteControl::grassLine, 155, 190, 0);

        if (time2 <= 4){
            grassLength += 1;
            time2 = 8;
        }
        else{
            time2 -= 1;
        }


        if (grassLength >= 180){
            grassLength = 180;
        }
    }
}