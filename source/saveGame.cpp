#include "saveGame.hpp"

namespace save{

    std::fstream progress;
    std::fstream plants;
    std::fstream zombies;
    std::fstream configuration;
    
    void makeFile(){
        std::ofstream progress("saves/progress.pvz", ios::binary);
        std::ofstream plants("saves/plants.pvz", ios::binary);
        std::ofstream zombies("saves/zombies.pvz", ios::binary);
        std::ofstream configuration("saves/configuration.pvz", ios::binary);
    }

    void openFile(){
        progress.open("saves/progress.pvz", ios::binary);
        plants.open("saves/plants.pvz", ios::binary);
        zombies.open("saves/zombies.pvz", ios::binary);
        configuration.open("saves/configuration.pvz", ios::binary);
    }


    void deleteOldConfig(){
        sceIoRemove("saves/configuration.pvz");
    }


    void saveProgress(){
        progress << level::wichWorld << std::endl;
        progress << level::wichLevel << std::endl;
    }

    void savePlants(){

    }

    void saveZombies(){

    }

    void saveConfig(){
        configuration << settingsMenu::musicVolume << std::endl;
        configuration << settingsMenu::sfxVolume << std::endl;
    }


    void readProgress(){

    }

    void readPlants(){

    }

    void readZombies(){

    }

    void readConfig(){

    }
}