#include "settings.hpp"

namespace settingsMenu{

    int cursorPos = 0;
    float musicVolume = 100;
    float sfxVolume = 100;

    void renderSettingsMenu(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::settingsBg, 0, -5, 0);
    }


    void renderSlider(){
        drawSpriteAlpha(0, 0, 110, 10, spriteControl::slider, 192, 100, 0);
        drawSpriteAlpha(0, 0, 110, 10, spriteControl::slider, 192, 130, 0);
    }

    void renderKnob(){
        drawSpriteAlpha(0, 0, 18, 24, spriteControl::knob, musicVolume + 185, 92, 0);
        drawSpriteAlpha(0, 0, 18, 24, spriteControl::knob, sfxVolume + 185, 122, 0);
    }
}