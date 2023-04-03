#include "Character.h"
#include "LevelDesign.h"
#include "UserInterface.h"
#include "AnimationAndSprites.h"
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
                ShowXY(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                gotoxy(x, y);
                EnemyAI.AutoMovement(Level, x, y);
                Level.DrawVisibleField(x, y);
                CheckForEnemiesAround(Level, Player, x, y);

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
        SetDamage(20);
        SetHealth(70);
    }
    if (EnemyType == 1) {
        SetName("Boss");
        SetDamage(35);
        SetHealth(300);
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
        if (((v - x) ^ 2 + (d - y) ^ 2) < 2) {
            if (v < x and d < y and WallCheck(Level, v + 1, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++; d++;
            } else if (v > x and d < y and WallCheck(Level, v - 1, y + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--; d++;
            } else if (v < x and d > y and WallCheck(Level, v + 1, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++; d--;
            } else if (v > x and d > y and WallCheck(Level, v - 1, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--; d--;
            } else if (v == x and d < y and WallCheck(Level, v, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d++;
            } else if (v == x and d > y and WallCheck(Level, v, d-1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d--;
            } else if (v < x and d == y and WallCheck(Level, v + 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++;
            } else if (v > x and d == y and WallCheck(Level, v - 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--;
            }
        } else {
            int move = 1 + rand() % 4;
            if (move == 1 and WallCheck(Level, v, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d--;
            }
            if (move == 2 and WallCheck(Level, v - 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--;
            }
            if (move == 3 and WallCheck(Level, v, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d++;
            }
            if (move == 4 and WallCheck(Level, v + 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++;
            }
        }
        i.x = v; i.y = d;
    }
}

string EnemyAI::GetEnemySymbol() {
    return EnemySymbol;
}

void PlayerController::CheckForEnemiesAround(GameLevel & Level, Player & Player, int x, int y) {
    int r = 3;
    for (int i = 0; i < r + 2; i++) {
        for (int j = 0; j < r; j++) {
            if (Level.GetFromCoordinates(x-3+i, y-2+j) == "&") {
                Enemy Enemy(0);
                //ZAMENITB!
                if (FightInitialize(Player, Enemy) == 1) {
                    Level.SetToCoordinates(" ", x-3+i, y-2+j);
                    for (int k = 0; k < Level.EnemyCoordinates.capacity() ; k++) {
                        if ((Level.EnemyCoordinates[k].x == x-3+i) and (Level.EnemyCoordinates[k].y == y-2+j)) {
                            Level.EnemyCoordinates.erase(Level.EnemyCoordinates.begin() + k);
                        }
                    }
                    system("cls");
                    gotoxy(0,0);
                    Level.DrawMemorised();
                    return;
                }
            }
        }
    }
    gotoxy(0,0);

}