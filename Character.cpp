#include "Character.h"
#include "LevelDesign.h"
#include "UserInterface.h"
#include "Utility.h"

/*============================================================ Character ============================================================
===================================================================================================================================== */
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
string Character::GetName() {
    return Name;
}
void Character::SetName(string Name) {
    this -> Name = Name;
}



/*============================================================ Player ============================================================
===================================================================================================================================== */

Player::Player() = default;


Player::Player(string ClassName) {
    if (ClassName == "Knight") {
        SetName(ClassName);
        SetHealth(130);
        SetStamina(100);
        SetArmor(30);
        SetDamage(20);
    }
    if (ClassName == "Archer") {
        SetName(ClassName);
        SetHealth(100);
        SetStamina(100);
        SetArmor(10);
        SetDamage(30);
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


/*============================================================ PlayerController ============================================================
===================================================================================================================================== */

void PlayerController::TakeItem(class Armor & Item) {
    InvSlot Slot;
    Slot.Name = Item.GetName();
    Slot.Point = Item.GetArmorPoints();
    Inventory.push_back(Slot);
}

void PlayerController::TakeItem(Weapon & Item){
    InvSlot Slot;
    Slot.Name = Item.GetName();
    Slot.Point = Item.GetWeaponDamage();
    Inventory.push_back(Slot);
}

void PlayerController::TakeItem(Potion & Item) {
    InvSlot Slot;
    Slot.Name = Item.GetName();
    //Slot.Point = Item.Get
    //Inventory.push_back(Slot);
}

void PlayerController::DropItem(InvSlot & Item) {
    //inventory pop item
}

int PlayerController::GetX() {
    return x;
}
int PlayerController::GetY() {
    return y;
}

void PlayerController::InteractWith() {
    gotoxy(0, 0); cout << "e: ID";
}

void PlayerController::MovementInit(Player & Player, GameLevel & Level) {
    Level.DrawVisibleField(x, y);

    DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());

    EnemyAI EnemyAI;
    string PlayerSymbol = GetPlayerSymbol();
    TurnLightRed;

    gotoxy(x, y);
    cout << PlayerSymbol;
    gotoxy(x, y);
    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();
            if (KeyCheck(Key) == 1 and WallCheck(Level, x, y - 1) == 0) {
                gotoxy(x, y - 1); cout << PlayerSymbol; Level.SetToCoordinates("@", x, y-1);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y--;
            }
            if (KeyCheck(Key) == 2 and WallCheck(Level, x - 1, y) == 0) {
                gotoxy(x - 1, y); cout << PlayerSymbol; Level.SetToCoordinates("@", x-1, y);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x--;
            }
            if (KeyCheck(Key) == 3 and WallCheck(Level, x, y + 1) == 0) {
                gotoxy(x, y + 1); cout << PlayerSymbol; Level.SetToCoordinates("@", x, y+1);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y++;
            }
            if (KeyCheck(Key) == 4 and WallCheck(Level, x + 1, y) == 0) {
                gotoxy(x + 1, y); cout << PlayerSymbol; Level.SetToCoordinates("@", x+1, y);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x++;
            }


            if (KeyCheck(Key) == 6) {
                InteractWith();
            }
            if (KeyCheck(Key) == 7) {
                OpenInventory(Inventory);
            }


            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                Level.DrawVisibleField(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                gotoxy(x, y);
                EnemyAI.AutoMovement(Level, x, y);
                Level.CheckForEnemiesAround(x, y);

                continue;

            }
        }
    }
}

string PlayerController::GetPlayerSymbol() {
    return PlayerSymbol;
}

int PlayerController::WallCheck(GameLevel & Level, int x, int y) {
    string MapElement = Level.GetFromCoordinates(x, y);
    if (MapElement == "█") {
       return 1;
    } else if (MapElement == "░") {
       return 2;
    } else return 0;
}

/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

Enemy::Enemy(int EnemyType) {
    if (EnemyType == 0) {
        SetName("DefaultEnemy");
    }
    if (EnemyType == 1) {
        SetName("Boss");
    }
}

Enemy::Enemy() = default;

/*============================================================== EnemyAI ==============================================================
===================================================================================================================================== */

EnemyAI::EnemyAI() = default;

void EnemyAI::AutoMovement(GameLevel & Level, int x, int y) {
    for (auto & i: Level.EnemyCoordinates) {
        int v = i.x; int d = i.y;
        string EnemySymbol = GetEnemySymbol();
        TurnGreen;
//        gotoxy(v, d);
//        cout << EnemySymbol;
//        gotoxy(v, d);
        if (((v - x) ^ 2 + (d - y) ^ 2) < 1) {
            if (v < x and d < y) {
//                gotoxy(v + 1, d + 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                //
                Level.SetToCoordinates(EnemySymbol, v+1, d+1);
                Level.SetToCoordinates(" ", v, d);
                v++;
                d++;
            } else if (v > x and d < y) {
//                gotoxy(v - 1, d + 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                //
                Level.SetToCoordinates(EnemySymbol, v-1, d+1);
                Level.SetToCoordinates(" ", v, d);
                v--;
                d++;
            } else if (v < x and d > y) {
//                gotoxy(v + 1, d - 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                //
                Level.SetToCoordinates(EnemySymbol, v+1, d-1);
                Level.SetToCoordinates(" ", v, d);
                v++;
                d--;
            } else if (v > x and d > y) {
//                gotoxy(v - 1, d - 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";

                Level.SetToCoordinates(EnemySymbol, v-1, d-1);
                Level.SetToCoordinates(" ", v, d);
                v--;
                d--;
            } else if (v == x and d < y) {
//                gotoxy(v, d + 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                //
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                d++;
            } else if (v == x and d > y) {
//                gotoxy(v, d - 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                //
                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                d--;
            } else if (v < x and d == y) {
//                gotoxy(v + 1, d);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";

                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                v++;
            } else if (v > x and d == y) {
//                gotoxy(v - 1, d);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";

                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                v--;
            }
        } else {
            int move = 1 + rand() % 4;
            if (move == 1 and WallCheck(Level, v, d - 1) == 0) {
//                gotoxy(v, d - 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";

                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                d--;
            }
            if (move == 2 and WallCheck(Level, v - 1, d) == 0) {
//                gotoxy(v - 1, d);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                v--;
            }
            if (move == 3 and WallCheck(Level, v, d + 1) == 0) {
//                gotoxy(v, d + 1);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                d++;
            }
            if (move == 4 and WallCheck(Level, v + 1, d) == 0) {
//                gotoxy(v + 1, d);
//                cout << EnemySymbol;
//                gotoxy(v, d);
//                cout << " ";
                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                v++;
            }
        }
        i.x = v; i.y = d;
    }
}

string EnemyAI::GetEnemySymbol() {
    return EnemySymbol;
}

