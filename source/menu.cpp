#include "menu.hpp"


namespace mainMenu{

    int cursorPos = 0;

    void renderLoading(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::loadingScreen, 0, 0, 0);
    }

    void renderTitle(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::titleScreen, 0, 0, 0);
    }

    void renderCursor(){
        drawSpriteAlpha(0, 0, 460, 260, imageControl::cursor[cursorPos], 0, 0, 0);
    }

    void renderNumbers(){
        drawSpriteAlpha(0, 0, 20, 20, spriteControl::numbersSmall[level::wichWorld - 1], 322, 30, 0);
        drawSpriteAlpha(0, 0, 20, 20, spriteControl::numbersSmall[9], 332, 30, 0);
        drawSpriteAlpha(0, 0, 20, 20, spriteControl::numbersSmall[level::wichLevel - 1], 342, 30, 0);
    }

}