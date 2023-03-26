#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


// интерфейс боевки плавает
// главное меню
// окно выбора класса
// предметы
// расстановка предметов по карте



int main() {

    InitializeSettings();
    UserInterface UserInterface;
   // UserInterface.StartMenu();
    UserInterface.ClassCoiceMenu();
    Player Player("Knight");
    Enemy DefaultEnemy(0);
    //FightInitialize(Player.GetName(), DefaultEnemy.GetName());

    GameLevel HomeLevel(0);
    PlayerController PlayerController;
    PlayerController.TakeItem(Armor("Chestplace", 20));
    PlayerController.TakeItem(Weapon("Sword", 20));
    PlayerController.TakeItem(Armor("Shield", 30));
    PlayerController.MovementInit(HomeLevel);

    wait();

}
