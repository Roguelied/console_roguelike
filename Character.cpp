#include "Character.h"
#include "Utility.h"


//Character
int Character::GetHealth() {
    return Health;
}
void Character::SetHealth(int Health) {
    this -> Health = Health;
}
int Character::GetDamage() {
    return Damage;
}
void Character::SetDamage(int Damage) {
    this -> Damage = Damage;
}
int Character::GetArmor() {
    return Armor;
}
void Character::SetArmor(int Armor) {
    this -> Armor = Armor;
}


//Player
int Player::GetStamina() {
    return Stamina;
}
void Player::SetStamina(int Stamina) {
    this -> Stamina = Stamina;
}
int Player::GetGold() {
    return Gold;
}
void Player::SetGold(int Gold) {
    this -> Gold = Gold;
}
string Player::GetName() {
    return Name;
}
void Player::SetName(string Name) {
    this -> Name = Name;
}


void PlayerController::MovementInit(GameLevel HomeLevel) {
    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();
            if (Key == 'w' and HomeLevel.GameLevelArray[x-1][y] != "█" and HomeLevel.GameLevelArray[x-1][y] != "#") {

                gotoxy(y, x-1); cout << "@"; gotoxy(y, x); cout << " ";
                HomeLevel.GameLevelArray[x][y] = " ";
                x--; gotoxy(y, x);
            }
            if (Key == 'a' and HomeLevel.GameLevelArray[x][y-1] != "█" and HomeLevel.GameLevelArray[x][y-1] != "#") {
                gotoxy(y-1, x); cout << "@"; gotoxy(y, x); cout << " ";
                HomeLevel.GameLevelArray[x][y] = " ";
                y--; gotoxy(y, x);
            }
            if (Key == 's' and HomeLevel.GameLevelArray[x+1][y] != "█" and HomeLevel.GameLevelArray[x+1][y] != "#") {
                gotoxy(y, x+1); cout << "@"; gotoxy(y, x); cout << " ";
                HomeLevel.GameLevelArray[x][y] = " ";
                x++; gotoxy(y, x);
            }
            if (Key == 'd' and HomeLevel.GameLevelArray[x][y+1] != "█" and HomeLevel.GameLevelArray[x][y+1] != "#") {
                gotoxy(y+1, x); cout << "@"; gotoxy(y, x); cout << " ";
                HomeLevel.GameLevelArray[x][y] = " ";
                y++; gotoxy(y, x);
            }
            if (Key == 'w' or Key == 'a' or Key == 's' or Key == 'd') {
                //HomeLevel.GameLevelArray[x][y] = "@";
                //system("cls");
                //HomeLevel.DrawGameLevel();
                continue;
            }
        }
    }
}
