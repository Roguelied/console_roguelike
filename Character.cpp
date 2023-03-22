#include "Character.h"
#include "LevelDesign.h"
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


void PlayerController::MovementInit(GameLevel Level) {
    TurnLightRed;
    string PlayerSymbol = GetPlayerSymbol();
    gotoxy(x, y); cout << PlayerSymbol; gotoxy(x, y);

    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();

            if ((Key == 'w' or Key == 'W') and WallCheck(Level, x, y-1) == 0) {
                gotoxy(x, y-1); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); y--;
            }
            if ((Key == 'a' or Key == 'A') and WallCheck(Level, x-1, y) == 0) {
                gotoxy(x-1, y); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); x--;
            }
            if ((Key == 's' or Key == 'S') and WallCheck(Level, x, y+1) == 0) {
                gotoxy(x, y+1); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); y++;
            }
            if ((Key == 'd' or Key == 'D') and WallCheck(Level, x+1, y) == 0) {
                gotoxy(x+1, y); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); x++;
            }
            if (Key == 'w' or Key == 'a' or Key == 's' or Key == 'd' or Key == 'W' or Key == 'A' or Key == 'S' or Key == 'D') {
                Level.SetToCoordinates(" ", x, y); PlayerSymbol;
                gotoxy(x, y);
                continue;
            }
        }
    }
}

string PlayerController::GetPlayerSymbol() {
    return PlayerSymbol;
}


int PlayerController::WallCheck(GameLevel Level, int x, int y) {
    string MapElement = Level.GetFromCoordinates(x, y);
    if (MapElement == "█") {
       return 1;
    } else if (MapElement == "░") {
       return 2;
    } else return 0;

    return 0;
}
