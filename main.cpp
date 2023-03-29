#include "Utility.h" //DNT!!!
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


// интерфейс боевки плавает
// главное меню +-
// окно выбора класса +-
// предметы +-
// расстановка предметов по карте -



int main() {

    InitializeSettings();

    //UserInterface UserInterface;
    GameLevel HomeLevel(1);
    HomeLevel.DrawGameLevel();
    Player player;
    PlayerController PlayerController;
    PlayerController.MovementInit(player, HomeLevel);

    //PlayKnightAttackAnimation();
    //UserInterface.StartMenu();
    //Player Player(UserInterface.ClassMenu());

    //for (;;) {PlayKnightAttackAnimation();}


    wait();
}
