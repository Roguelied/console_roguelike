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
    TurnGreen;
    string PlayerSymbol = GetPlayerSymbol();
    gotoxy(x, y); cout << PlayerSymbol; gotoxy(x, y);

    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();
            if (KeyCheck(Key) == 1 and WallCheck(Level, x, y-1) == 0) {
                gotoxy(x, y-1); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); y--;
            }
            if (KeyCheck(Key) == 2 and WallCheck(Level, x-1, y) == 0) {
                gotoxy(x-1, y); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); x--;
            }
            if (KeyCheck(Key) == 3 and WallCheck(Level, x, y+1) == 0) {
                gotoxy(x, y+1); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); y++;
            }
            if (KeyCheck(Key) == 4 and WallCheck(Level, x+1, y) == 0) {
                gotoxy(x+1, y); cout << PlayerSymbol; gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y); x++;
            }
            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                Level.SetToCoordinates(" ", x, y);
                gotoxy(x, y);
                continue;
            }
            GameLevel HomeLevel(1);
            EnemyAI EnemyAI;
            //EnemyAI.AutoMovement(HomeLevel);
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
}

void EnemyAI::AutoMovement(GameLevel Level) {
    TurnGreen;
    string EnemySymbol = GetEnemySymbol();
    gotoxy(x, y); cout << EnemySymbol; gotoxy(x, y);

        int move = 1 + rand() % 4;
        if (move == 1 and WallCheck(Level, x, y-1) == 0) {
            gotoxy(x, y-1); cout << EnemySymbol; gotoxy(x, y); cout << " ";
            Level.SetToCoordinates(" ", x, y); y--;
        }
        if (move == 2 and WallCheck(Level, x-1, y) == 0) {
            gotoxy(x-1, y); cout << EnemySymbol; gotoxy(x, y); cout << " ";
            Level.SetToCoordinates(" ", x, y); x--;
        }
        if (move == 3 and WallCheck(Level, x, y+1) == 0) {
            gotoxy(x, y+1); cout << EnemySymbol; gotoxy(x, y); cout << " ";
            Level.SetToCoordinates(" ", x, y); y++;
        }
        if (move == 4 and WallCheck(Level, x+1, y) == 0) {
            gotoxy(x+1, y); cout << EnemySymbol; gotoxy(x, y); cout << " ";
            Level.SetToCoordinates(" ", x, y); x++;
        }
        if (move == 1 or move == 2 or move == 3 or move == 4) {
            Level.SetToCoordinates(" ", x, y); EnemySymbol;
            gotoxy(x, y);
        }
    }


string EnemyAI::GetEnemySymbol() {
    return EnemySymbol;
}

int EnemyAI::WallCheck(GameLevel Level, int x, int y) {
    string MapElement = Level.GetFromCoordinates(x, y);
    if (MapElement == "█") {
        return 1;
    } else if (MapElement == "░") {
        return 2;
    } else return 0;
}