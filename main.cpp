#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"




int main() {


    InitializeSettings();

    GameLevel HomeLevel(1);
    HomeLevel.DrawGameLevel();
    PlayerController PlayerController;
    PlayerController.MovementInit(HomeLevel);


    int a;
    cin >> a;

}
