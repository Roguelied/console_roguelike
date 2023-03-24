#include "Character.h"
#include "LevelDesign.h"
#include "Utility.h"
#include <cstdlib>

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


int KeyCheck(int Key) {
    if (Key == 'w' or Key == 'W' or Key == 230 or Key == 150) {
        return 1;
    } else if (Key == 'a' or Key == 'A' or Key == 228 or Key == 148)  {
        return 2;
    } else if (Key == 's' or Key == 'S' or Key == 235 or Key == 155) {
        return 3;
    } else if (Key == 'd' or Key == 'D' or Key == 162 or Key == 130) {
        return 4;
    }
}



void PlayerController::MovementInit(GameLevel Level) {
    Level.DrawVisibleField(x, y);
    TurnLightRed;
    string PlayerSymbol = GetPlayerSymbol();
    gotoxy(x, y); cout << PlayerSymbol; gotoxy(x, y);


//    for(;;){
        GameLevel HomeLevel(1);
        if (_kbhit()) {
            auto Key = _getch();
            if (KeyCheck(Key) == 1 and WallCheck(Level, x, y - 1) == 0) {
                gotoxy(x, y - 1);
                cout << PlayerSymbol;
                gotoxy(x, y);
                cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y--;
            }
            if (KeyCheck(Key) == 2 and WallCheck(Level, x - 1, y) == 0) {
                gotoxy(x - 1, y);
                cout << PlayerSymbol;
                gotoxy(x, y);
                cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x--;
            }
            if (KeyCheck(Key) == 3 and WallCheck(Level, x, y + 1) == 0) {
                gotoxy(x, y + 1);
                cout << PlayerSymbol;
                gotoxy(x, y);
                cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y++;
            }
            if (KeyCheck(Key) == 4 and WallCheck(Level, x + 1, y) == 0) {
                gotoxy(x + 1, y);
                cout << PlayerSymbol;
                gotoxy(x, y);
                cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x++;
            }
            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                Level.DrawVisibleField(x, y);
                Level.SetToCoordinates(" ", x, y);
                gotoxy(x, y);
                //continue;

            }
//        }
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
}

void EnemyAI::AutoMovement(GameLevel Level) {
    TurnGreen;
    string EnemySymbol = GetEnemySymbol();
    gotovd(v, d);
    cout << EnemySymbol;
    gotovd(v, d);
    for (;;) {
        GameLevel HomeLevel(1);
        sleep_for(1s);
        int move = 1 + rand() % 4;
        if (move == 1 and WallCheck(Level, v, d - 1) == 0) {
            gotovd(v, d - 1);
            cout << EnemySymbol;
            gotovd(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            d--;
        }
        if (move == 2 and WallCheck(Level, v - 1, d) == 0) {
            gotovd(v - 1, d);
            cout << EnemySymbol;
            gotovd(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            v--;
        }
        if (move == 3 and WallCheck(Level, v, d + 1) == 0) {
            gotovd(v, d + 1);
            cout << EnemySymbol;
            gotovd(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            d++;
        }
        if (move == 4 and WallCheck(Level, v + 1, d) == 0) {
            gotovd(v + 1, d);
            cout << EnemySymbol;
            gotovd(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            v++;
        }
    }
}

string EnemyAI::GetEnemySymbol() {
    return EnemySymbol;
}

int EnemyAI::WallCheck(GameLevel Level, int v, int d) {
    string MapElement = Level.GetFromCoordinates(v, d);
    if (MapElement == "█") {
        return 1;
    } else if (MapElement == "░") {
        return 2;
    } else return 0;
}