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

    UserInterface UserInterface;
    GameLevel HomeLevel(0);
    PlayKnightAttackAnimation();
    UserInterface.StartMenu();
    Player Player(UserInterface.ClassMenu());

    for (;;) {PlayKnightAttackAnimation();}


    wait();

}
