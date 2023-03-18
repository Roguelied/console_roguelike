#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


int main() {
    InitializeSettings();


    GameLevel HomeLevel(0);
    //for (;;) {PlayCharacterAttackAnimation();}

    //PlayCharacterAttackAnimation();
    //SetConsoleCursorPosition(hConsole, {10, 10});
    PlayerController Ctrl;
    Ctrl.Movement(HomeLevel);



    int a;
    cin >> a;

}
