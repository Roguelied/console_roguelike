#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


vector <PlayerItem*> AllExistingItems = {
        new Armor("Chest", 30),
};


int main() {
    InitializeSettings();
    Player Player("Knight");
    Enemy Enemy(0);
    FightInitialize(Player, Enemy);

    wait(); return 0;
    //--------------------------------------------------------------------------------------
    InitializeSettings();

    GameLevel HomeLevel(0);
    GameLevel FirstLevel(1);
    GameLevel SecondLevel(2);

    PlayerController PlayerController;
    UserInterface UserInterface;


    UserInterface.StartMenu();
    //Player Player(UserInterface.ClassMenu());

    PlayerController.MovementInit(Player, FirstLevel);


    wait();
}
