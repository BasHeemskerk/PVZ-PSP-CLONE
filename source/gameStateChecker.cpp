#include "gameStateChecker.hpp"

namespace state{

    bool loading = true;
    bool menu = false;
    bool game = false;
    bool about = false;
    bool more = false;
    bool almanac = false;
    bool settings = false;

    void checkbool(){

        if (loading){
            loading = true;
            menu = false;
            game = false;
            about = false;
            more = false;
            almanac = false;
            settings = false;
        }

        if (menu == true && settings == false){
            loading = false;
            menu = true;
            game = false;
            about = false;
            more = false;
            almanac = false;
            settings = false;
        }
        else if (menu == true && settings == true){
            loading = false;
            menu = true;
            game = false;
            about = false;
            more = false;
            almanac = false;
            settings = true;
        }

        if (game){
            loading = false;
            menu = false;
            game = true;
            about = false;
            more = false;
            almanac = false;
            settings = false;
        }

        if (about){
            loading = false;
            menu = false;
            game = false;
            about = true;
            more = false;
            almanac = false;
            settings = false;
        }

        if (more){
            loading = false;
            menu = false;
            game = false;
            about = false;
            more = true;
            almanac = false;
            settings = false;
        }

        if (almanac){
            loading = false;
            menu = false;
            game = false;
            about = false;
            more = false;
            almanac = true;
            settings = false;
        }
    }
}