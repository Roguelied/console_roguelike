#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"




int main() {


    InitializeSettings();
    Armor Chestplace("Boba", 12);
    Chestplace.SetArmorPoints(25);
    cout << Chestplace.GetName() << endl;
    cout << Chestplace.GetArmorPoints();
    UserInterface UserInterface;
    UserInterface.ShowStartScreen();
    GameLevel HomeLevel(1);
    HomeLevel.DrawGameLevel();
    PlayerController PlayerController;
    PlayerController.MovementInit(HomeLevel);


    int a;
    cin >> a;

}
