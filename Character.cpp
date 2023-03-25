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
void EnemyAI::SetV(int v) {
    this -> v = v;
}
void EnemyAI::SetD(int d) {
    this -> d = d;
}
int EnemyAI::GetV() {
    return v;
}
int EnemyAI::GetD() {
    return d;
}
string Character::GetName() {
    return Name;
}
void Character::SetName(string Name) {
    this -> Name = Name;
}

//Player
Player::Player(string ClassName) {
    if (ClassName == "Knight") {
        SetName(ClassName);
        SetHealth(1);
        SetStamina(100);
        SetArmor(20);
        SetDamage(20);
    }
    if (ClassName == "Archer") {
        SetName(ClassName);
        SetHealth(1);
        SetStamina(100);
        SetArmor(20);
        SetDamage(20);
    }
}


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

void PlayerController::MovementInit(GameLevel Level) {
    Level.DrawVisibleField(x, y);
    TurnLightRed;
    string PlayerSymbol = GetPlayerSymbol();
    gotoxy(x, y); cout << PlayerSymbol; gotoxy(x, y);
    EnemyAI EnemyAI;

    for(;;){
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

                EnemyAI.AutoMovement(HomeLevel);
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
}

void EnemyAI::AutoMovement(GameLevel Level) {
    TurnGreen;
    string EnemySymbol = GetEnemySymbol();
    gotoxy(v, d);
    cout << EnemySymbol;
    gotoxy(v, d);
        int move = 1 + rand() % 4;
        if (move == 1 and WallCheck(Level, v, d - 1) == 0) {
            gotoxy(v, d - 1);
            cout << EnemySymbol;
            gotoxy(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            this -> d = d-1;
            SetD(d--);
        }
        if (move == 2 and WallCheck(Level, v - 1, d) == 0) {
            gotoxy(v - 1, d);
            cout << EnemySymbol;
            gotoxy(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            this -> v = v-1;
            SetV(v--);
        }
        if (move == 3 and WallCheck(Level, v, d + 1) == 0) {
            gotoxy(v, d + 1);
            cout << EnemySymbol;
            gotoxy(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            this -> d = d+1;
            SetD(d++);
        }
        if (move == 4 and WallCheck(Level, v + 1, d) == 0) {
            gotoxy(v + 1, d);
            cout << EnemySymbol;
            gotoxy(v, d);
            cout << " ";
            Level.SetToCoordinates(" ", v, d);
            this -> v = v+1;
            SetV(v++);
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

Enemy::Enemy(int EnemyType) {
    if (EnemyType == 0) {
        SetName("DefaultEnemy");
    }
    if (EnemyType == 1) {
        SetName("Boss");
    }
}
