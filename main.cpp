#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


vector <PlayerItem*> AllExistingItems = {
        new Armor("Chest", 30),
};


// использовать предметы в окне боевки
// саня сказать мне фиксированные x y для того чтобы спавнить в лвле и чтобы выходить из негео, сделать края для лвла меньше к концу консоли чтобы не было бед аллока
// мне переделать на бекграунд фонт менюшки

int main() {

    //wait(); return 0;
    //--------------------------------------------------------------------------------------
    InitializeSettings();

    GameLevel FreeSpace(4);
    GameLevel HomeLevel(0);
    GameLevel FirstLevel(1);
    GameLevel SecondLevel(2);

    PlayerController PlayerController;
    UserInterface UserInterface;


    UserInterface.StartMenu();
    Player Player(UserInterface.ClassMenu());
    PlayerController.MovementInit(Player,HomeLevel);
    PlayerController.MovementInit(Player, FirstLevel);
    PlayerController.MovementInit(Player, SecondLevel);


    wait();
}
