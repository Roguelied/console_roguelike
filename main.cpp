#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"

Potion HealthPotion("Potion of Health");
Potion StaminaPotion("Potion of Stamina");

Armor HeavyArmor("Heavy Armor", 40);
Armor LightArmor("Light Armor", 20);

Weapon OldSword("Old Sword", 15);
Weapon ShinyGreatsword("Shiny Greatsword", 66);

// использовать предметы в окне боевки
// саня сказать мне фиксированные x y для того чтобы спавнить в лвле и чтобы выходить из негео, сделать края для лвла меньше к концу консоли чтобы не было бед аллока
// мне переделать на бекграунд фонт менюшки

int main() {

    UserInterface UserInterface;
    OpenShop();
    wait();
    return 0;
}
    //--------------------------------------------------------------------------------------
//    InitializeSettings();
//
//    GameLevel FreeSpace(4);
//    GameLevel HomeLevel(0);
//    GameLevel FirstLevel(1);
//    GameLevel SecondLevel(2);
//
//    PlayerController PlayerController;
//    UserInterface UserInterface;
//
//
//    UserInterface.StartMenu();
//    Player Player(UserInterface.ClassMenu());
//
//
//    PlayerController.TakeItem(HealthPotion);
//    PlayerController.TakeItem(StaminaPotion);
//    PlayerController.TakeItem(HeavyArmor);
//    PlayerController.TakeItem(ShinyGreatsword);
//
//
//    PlayerController.MovementInit(Player,HomeLevel);
//    PlayerController.MovementInit(Player, FirstLevel);
//    PlayerController.MovementInit(Player, SecondLevel);
//
//
//    wait();
//}
