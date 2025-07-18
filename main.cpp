#include "BasicScene.h"
#include "Hero.h"
#include "Monster.h"
#include "MonsterScene.h"
#include "NewGameScene.h"
#include <iostream>

int main() {

    //
    Hero hero;

    //
    Monster bat {"Bat", 5, 5, 5, 2};

    //
    BasicScene about;
    MonsterScene room1 {{bat}};

    NewGameScene newGame {
        "new game desc",
        &room1
    };

    BasicScene home {
        "Stepping Stone Dungeon",
        {
            {"New Game", &newGame},
            {"About", &about}
        }
    };

    about.desc = "about blurb here";
    about.options = {{"Back", &home}};

    //
    Scene* next_scene = &home;

    //
    while(next_scene != nullptr) {
        next_scene = next_scene->render(&hero);
    }

    //
    return 0;
}

