#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"

//POTION
Potion AntidotePotion("Antidote potion");
Potion BluePotion("Blue potion");
Potion HealingPotion("Healing potion");
Potion StrengthPotion("Strength potion");
Potion TeaPotion("Tea potion");

//ARMOR
Armor LightArmor("Light armor", 40);
Armor UnicornArmor("Unicorn armor", 20);
Armor BlackCoatArmor("Black coat armor", 40);
Armor HeavyArmor("Heavy Armor", 40);
Armor GodArmor("God armor", 40);

//WEAPON
//sword
Weapon ChaosEaterSword("Chaos eater sword", 15);
Weapon SwordIncinerator("Sword incinerator", 15);
Weapon SwordRebel("Sword rebel", 15);
Weapon BusterSword("Buster sword", 15);
Weapon HeavenlySword("Heavenly sword", 15);
Weapon EnergySword("Energy sword", 15);
Weapon Fuckel("FUCKel",100000);

//bow
Weapon RoyalBow("Royal bow", 15);
Weapon BowOathArrow("Bow oath arrow", 15);
Weapon HunterBow("Hunter bow", 15);
Weapon BowSlingshot("Bow slingshot", 15);
Weapon RustyBow("Rusty bow", 15);
Weapon BowPredator("Bow predator", 15);
Weapon TopolM("RT-2PM2 Topol-M",100000);

// использовать предметы в окне боевки
// саня сказать мне фиксированные x y для того чтобы спавнить в лвле и чтобы выходить из негео, сделать края для лвла меньше к концу консоли чтобы не было бед аллока
// мне переделать на бекграунд фонт менюшки

int main() {

/*    UserInterface UserInterface;
    OpenShop();
    wait();
    return 0;
}*/
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


/*    PlayerController.TakeItem(HealthPotion);
   PlayerController.TakeItem(StaminaPotion);
    PlayerController.TakeItem(HeavyArmor);
    PlayerController.TakeItem(ShinyGreatsword);*/


    PlayerController.MovementInit(Player,HomeLevel);
    PlayerController.MovementInit(Player, FirstLevel);
    PlayerController.MovementInit(Player, SecondLevel);


    wait();
}
