#include "almanac.hpp"

namespace infoAlmanac{

    int almanacPage = 0;  
    int cursorPos = 0;

    int wichSunFlowerFrame = 0;
    int wichZombieFrame = 0;
    float sunflowerSpriteFps = 4;
    float zombieSpriteFps = 4;

    std::ifstream Peashooter_info;
    std::ifstream Sunflower_info;
    std::ifstream Cherrybomb_info;
    std::ifstream Wallnut_info;
    std::ifstream Potatomine_info;
    std::ifstream Snowpea_info;
    std::ifstream Chomper_info;
    std::ifstream Repeater_info;


    std::ifstream Puffshroom_info;
    std::ifstream Sunshroom_info;
    std::ifstream Fumeshroom_info;
    std::ifstream Gravebuster_info;
    std::ifstream Hypnoshroom_info;
    std::ifstream Scaredyshroom_info;
    std::ifstream Iceshroom_info;
    std::ifstream Doomshroom_info;


    std::ifstream Lilypad_info;
    std::ifstream Squash_info;
    std::ifstream Threepeater_info;
    std::ifstream Tanglekelp_info;
    std::ifstream Jalapeno_info;
    std::ifstream Spikeweed_info;
    std::ifstream Torchwood_info;
    std::ifstream Tallnut_info;


    std::ifstream Seashroom_info;
    std::ifstream Plantern_info;
    std::ifstream Cactus_info;
    std::ifstream Blover_info;
    std::ifstream Splitpea_info;
    std::ifstream Starfruit_info;
    std::ifstream Pumpkin_info;
    std::ifstream Magnetshroom_info;


    std::ifstream Cabbagepult_info;
    std::ifstream Flowerpot_info;
    std::ifstream Kernelpult_info;
    std::ifstream Coffeebean_info;
    std::ifstream Garlic_info;
    std::ifstream Umbrellaleaf_info;
    std::ifstream Marigold_info;
    std::ifstream Melonpult_info;

    void loadPlantInfoFiles(){

        //day
        std::ifstream Peashooter_info("romfs/text/plants/day/peaShooter.txt");
        std::ifstream Sunflower_info("romfs/text/plants/day/Sunflower.txt");
        std::ifstream Cherrybomb_info("romfs/text/plants/day/CherryBomb.txt");
        std::ifstream Wallnut_info("romfs/text/plants/day/Wallnut.txt");
        std::ifstream Potatomine_info("romfs/text/plants/day/PotatoMine.txt");
        std::ifstream Snowpea_info("romfs/text/plants/day/SnowPea.txt");
        std::ifstream Chomper_info("romfs/text/plants/day/Chomper.txt");
        std::ifstream Repeater_info("romfs/text/plants/day/Repeater.txt");

        //night
        std::ifstream Puffshroom_info("romfs/text/plants/night/PuffShroom.txt");
        std::ifstream Sunshroom_info("romfs/text/plants/night/SunShroom.txt");
        std::ifstream Fumeshroom_info("romfs/text/plants/night/FumeShroom.txt");
        std::ifstream Gravebuster_info("romfs/text/plants/night/GraveBuster.txt");
        std::ifstream Hypnoshroom_info("romfs/text/plants/night/HypnoShroom.txt");
        std::ifstream Scaredyshroom_info("romfs/text/plants/night/ScaredyShroom.txt");
        std::ifstream Iceshroom_info("romfs/text/plants/night/IceShroom.txt");
        std::ifstream Doomshroom_info("romfs/text/plants/night/DoomShroom.txt");

        
        //pool
        std::ifstream Lilypad_info("romfs/text/plants/pool/LilyPad.txt");
        std::ifstream Squash_info("romfs/text/plants/pool/Squash.txt");
        std::ifstream Threepeater_info("romfs/text/plants/pool/ThreePeater.txt");
        std::ifstream Tanglekelp_info("romfs/text/plants/pool/TangleKelp.txt");
        std::ifstream Jalapeno_info("romfs/text/plants/pool/Jalapeno.txt");
        std::ifstream Spikeweed_info("romfs/text/plants/pool/SpikeWeed.txt");
        std::ifstream Torchwood_info("romfs/text/plants/pool/TorchWood.txt");
        std::ifstream Tallnut_info("romfs/text/plants/pool/TallNut.txt");

        //fog
        std::ifstream Seashroom_info("romfs/text/plants/fog/SeaShroom.txt");
        std::ifstream Plantern_info("romfs/text/plants/fog/Plantern.txt");
        std::ifstream Cactus_info("romfs/text/plants/fog/Cactus.txt");
        std::ifstream Blover_info("romfs/text/plants/fog/Blover.txt");
        std::ifstream Splitpea_info("romfs/text/plants/fog/Splitpea.txt");
        std::ifstream Starfruit_info("romfs/text/plants/fog/StarFruit.txt");
        std::ifstream Pumpkin_info("romfs/text/plants/fog/Pumpkin.txt");
        std::ifstream Magnetshroom_info("romfs/text/plants/fog/MagnetShroom.txt");

        
        //roof
        std::ifstream Cabbagepult_info("romfs/text/plants/roof/CabbagePult.txt");
        std::ifstream Flowerpot_info("romfs/text/plants/roof/FlowerPot.txt");
        std::ifstream Kernelpult_info("romfs/text/plants/roof/KernelPult.txt");
        std::ifstream Coffeebean_info("romfs/text/plants/roof/CoffeeBean.txt");
        std::ifstream Garlic_info("romfs/text/plants/roof/Garlic.txt");
        std::ifstream Umbrellaleaf_info("romfs/text/plants/roof/UmbrellaLeaf.txt");
        std::ifstream Marigold_info("romfs/text/plants/roof/MariGold.txt");
        std::ifstream Melonpult_info("romfs/text/plants/roof/MelonPult.txt");
        
    }

    void unloadPlantInfoFiles(){

        //day
        Peashooter_info.close();
        Sunflower_info.close();
        Cherrybomb_info.close();
        Wallnut_info.close();
        Potatomine_info.close();
        Snowpea_info.close();
        Chomper_info.close();
        Repeater_info.close();

        //night
        Puffshroom_info.close();
        Sunshroom_info.close();
        Fumeshroom_info.close();
        Gravebuster_info.close();
        Hypnoshroom_info.close();
        Scaredyshroom_info.close();
        Iceshroom_info.close();
        Doomshroom_info.close();

        //pool
        Lilypad_info.close();
        Squash_info.close();
        Threepeater_info.close();
        Tanglekelp_info.close();
        Jalapeno_info.close();
        Spikeweed_info.close();
        Torchwood_info.close();
        Tallnut_info.close();

        //fog
        Seashroom_info.close();
        Plantern_info.close();
        Cactus_info.close();
        Blover_info.close();
        Splitpea_info.close();
        Starfruit_info.close();
        Pumpkin_info.close();
        Magnetshroom_info.close();

        //roof
        Cabbagepult_info.close();
        Flowerpot_info.close();
        Kernelpult_info.close();
        Coffeebean_info.close();
        Garlic_info.close();
        Umbrellaleaf_info.close();
        Marigold_info.close();
        Melonpult_info.close();

    }


    void loadZombieInfoFiles(){

    }


    void renderMainAlmanac(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::almanac[almanacPage], 0, 0, 0);
    }

    void renderCursor(){
        drawSpriteAlpha(0, 0, 480, 272, imageControl::almanacCursor[cursorPos], 0, 0, 0);
    }

    void renderSunflower(){
        drawSpriteAlpha(0, 0, 120, 120, spriteControl::sunflowerSprites[wichSunFlowerFrame], 65, 65, 0);

        if (sunflowerSpriteFps <= 0){
            wichSunFlowerFrame += 1;
            sunflowerSpriteFps = 3;
        }
        else{
            sunflowerSpriteFps -= 1;
        }

        if (wichSunFlowerFrame > 26){
            wichSunFlowerFrame = 0;
        }
    }

    void renderZombie(){
        drawSpriteAlpha(0, 0, 60, 100, spriteControl::zombieSpritesStill[wichZombieFrame], 320, 83, 0);

        if (zombieSpriteFps <= 0){
            wichZombieFrame += 1;
            zombieSpriteFps = 3;
        }
        else{
            zombieSpriteFps -= 1;
        }

        if (wichZombieFrame > 18){
            wichZombieFrame = 0;
        }
    }
}