#include "global.hpp"
#include "settings.hpp"
#include "level.hpp"

namespace save{

    extern std::fstream progress;
    extern std::fstream plants;
    extern std::fstream zombies;
    extern std::fstream configuration;

    void makeFile();
    void openFile();

    void deleteOldConfig();

    void saveProgress();
    void savePlants();
    void saveZombies();
    void saveConfig();

    void readProgress();
    void readPlants();
    void readZombies();
    void readConfig();
}