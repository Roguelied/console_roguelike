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
    GameLevel HomeLevel(0);


    UserInterface.StartMenu();
    Player Player(UserInterface.ClassMenu());
    Enemy DefaultEnemy(0);
    //FightInitialize(Player.GetName(), DefaultEnemy.GetName());

    PlayerController PlayerController;
    PlayerController.TakeItem(Armor("Chestplace", 20));
    PlayerController.TakeItem(Weapon("Sword", 20));
    PlayerController.TakeItem(Armor("Shield", 30));
    PlayerController.MovementInit(HomeLevel);

    wait();

}
