#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


//изночальная сноряга
Weapon Stick("Stick", 15);
Armor LeatherCoat("Leather Coat", 10);
Weapon Slingshot("Slingshot", 15);

//что может дать капибара
Weapon Fuckel("FUCKel", 100000);
Weapon TopolM("RT-2PM2 Topol-M", 100000);

//POTION
Potion BluePotion("Blue potion");
Potion HealingPotion("Healing potion");

//ARMOR
//лёгкая броня,тяжёлая броня,броня единорога,божественная броня
Armor LightArmor("Light armor", 40);
Armor HeavyArmor("Heavy Armor", 40);
Armor UnicornArmor("Unicorn armor", 40);
Armor GodArmor("God armor", 40);

//WEAPON
//sword
//нож,старая катана,небесный меч,меч пожерателя хаоса
Weapon Knife("Knife", 15);
Weapon OldKatana("Old Katana", 15);
Weapon HeavenlySword("Heavenly sword", 15);
Weapon ChaosEaterSword("Chaos eater sword", 15);

//bow
//арбалет,,кор.лук,лук повелителя времени,лук тёмного пламени
Weapon Crossbow("Crossbow", 15);
Weapon RoyalBow("Royal bow", 15);
Weapon TimeLordsBow("Time Lord's Bow", 15);
Weapon ShadowflameBow("Shadowflame Bow", 15);


// использовать предметы в окне боевки
// саня сказать мне фиксированные x y для того чтобы спавнить в лвле и чтобы выходить из негео, сделать края для лвла меньше к концу консоли чтобы не было бед аллока
// мне переделать на бекграунд фонт менюшки

int main() {
//
    InitializeSettings();
//    Player Player("Knight");
//    Enemy Enemy(0);
//    //FightInitialize(Player, Enemy);
//    PlayArcherAttackAnimation();
//    wait(); return 0;
    //for (;;) {PlayA();}
    wait(); return 0;

    //--------------------------------------------------------------------------------------

    InitializeSettings();
//    PlayerController PlayerController;
//    Player Player;
//    UserInterface UserInterface;
//    GameLevel HomeLevel(0);
//    PlayerController.MovementInit(Player,HomeLevel);
//    OpenShop();



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
