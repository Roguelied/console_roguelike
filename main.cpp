#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"




int main() {

    InitializeSettings();
    //for (;;) {PlayArcherAttackAnimation();}
    GameLevel HomeLevel(1);
    //HomeLevel.DrawGameLevel();

    //cout << HomeLevel.GetFromCoordinates(10, 10);
    PlayerController PlayerController;
    PlayerController.MovementInit(HomeLevel);


    int a;
    cin >> a;

}
