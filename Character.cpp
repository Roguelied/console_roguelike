#include "Character.h"
#include "LevelDesign.h"
#include "UserInterface.h"
#include "AnimationAndSprites.h"
#include "Utility.h"
void OpenInventory1(Player & Player, vector<Weapon> & WeaponSlots, vector<Armor> & ArmorSlots, vector<Potion> & PotionSlots);
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

void PlayerController::TakeItem(class Armor Item) {
//    InvSlot Slot;
//    Slot.Name = Item.GetName();
//    Slot.Point = Item.GetArmorPoints();
//    Inventory.push_back(Slot);
    ArmorSlots.push_back(Item);
}

void PlayerController::TakeItem(Weapon Item){
//    InvSlot Slot;
//    Slot.Name = Item.GetName();
//    Slot.Point = Item.GetWeaponDamage();
//    Inventory.push_back(Slot);
    WeaponSlots.push_back(Item);
}

void PlayerController::TakeItem(Potion Item) {
    PotionSlots.push_back(Item);
}



void PlayerController::InteractWith(Player & Player, GameLevel & Level, int x, int y, int flag) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            //gotoxy(x+i, y+j); cout << "2";
            if (flag == 0 and Level.GetFromCoordinates(x+i, y+j) == "$") {
                Player.SetGold(Player.GetGold() + Random(20, 100));
                Level.SetToCoordinates(" ", x+i, y+j);
                Level.DrawVisibleField(x, y);
            }
            if (flag == 1 and Level.GetFromCoordinates(x+i, y+j) == "*") {
                gotoxy(0, 0); cout << "sd";
            }
        }
    }

}

void PlayerController::MovementInit(Player & Player, GameLevel & Level) {
    Level.DrawVisibleField(x, y);
    DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());

    EnemyAI EnemyAI;
    string PlayerSymbol = GetPlayerSymbol();

    gotoxy(x, y);
    cout << PlayerSymbol;
    gotoxy(x, y);

    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();
            if ((x == 115 and y == 25) or (x == 115 and y == 26) or (x == 115 and y == 27)) {
                system("cls");
                x = 10; y = 10;
                return;
            }
            InteractWith(Player, Level, x, y, 0);
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
                InteractWith(Player, Level, x, y, 1);
            }
            if (KeyCheck(Key) == 7) {
                OpenInventory1(Player, WeaponSlots, ArmorSlots, PotionSlots);
            }


            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                ShowXY(x, y);
                EnemyAI.AutoMovement(Level, x, y);
                Level.DrawVisibleField(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                CheckForEnemiesAround(Level, Player, x, y);
                gotoxy(x, y);
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
    if (MapElement == "█") { //old wall
       return 1;
    } else if (MapElement == "░") { //wall
       return 2;
    } else if (MapElement == "*") { //shopkeeper
        return 3;
    } else return 0;
}


/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

Enemy::Enemy(int EnemyType) {
    if (EnemyType == 0) {
        SetName("DefaultEnemy");
        SetDamage(50);
        SetHealth(170);
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
    for (int i = 0; i < r + 1; i++) {
        for (int j = 0; j < r; j++) {
            if (Level.GetFromCoordinates(x-r/2+i, y-r/2+j) == "&") {
                Enemy Enemy(0);
                //ZAMENITB!
                int Result = FightInitialize(Player, Enemy);
                if (Result) {
                    Level.SetToCoordinates(" ", x-r/2+i, y-r/2+j);
                    for (int k = 0; k < Level.EnemyCoordinates.capacity() ; k++) {
                        if ((Level.EnemyCoordinates[k].x == x-r/2+i) and (Level.EnemyCoordinates[k].y == y-r/2+j)) {
                            Level.EnemyCoordinates.erase(Level.EnemyCoordinates.begin() + k);
                        }
                    }
                    system("cls");
                    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
                    gotoxy(0,0);
                    Level.DrawMemorised();
                    gotoxy(x, y);
                    return;
                } else if (Result == 0) {
                    system("cls"); cout << "U lose"; wait(); exit(1);
                }
            }
        }
    }
    gotoxy(0,0);

}


void OpenInventory1(Player & Player, vector<Weapon> & WeaponSlots, vector<Armor> & ArmorSlots, vector<Potion> & PotionSlots) {
    TurnAqua;
    for (int i = 0; i < 120; i++) {
        gotoxy(0+i, 30);
        cout << "▀";
        gotoxy(0+i, 58);
        cout << "▄";
    }
    for (int i = 0; i < 29; i++) {
        gotoxy(0, 30+i);
        cout << "█";
        gotoxy(119, 30+i);
        cout << "█";
    }
    for (int i = 0; i < 19; i++) {
        gotoxy(95, 34+i); cout << "█";
    }
    for (int i = 0; i < 24; i++) {
        gotoxy(95+i, 34); cout << "▄";
    }
    for (int i = 0; i < 24; i++) {
        gotoxy(95+i, 53); cout << "▀";
    }
    TurnWhite;
    gotoxy(101, 37); cout << "PLAYER STATS";
    TurnGreen;
    gotoxy(101, 41); cout << "Health: " << Player.GetHealth();
    TurnBrightAqua;
    gotoxy(101, 43); cout << "Stamina: " << Player.GetStamina();
    TurnGrey;
    gotoxy(101, 45); cout << "Armor: " << Player.GetArmor();
    TurnLightRed;
    gotoxy(101, 47); cout << "Damage: " << Player.GetDamage();
    TurnYellow;
    gotoxy(101, 49); cout << "Gold: " << Player.GetGold();
    TurnWhite;

    gotoxy(7, 34); TurnWhite; cout << " PLAYER ITEMS ";
    gotoxy(7, 35); TurnAqua; cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    gotoxy(14, 37); cout << "WEAPONS"; gotoxy(39, 37); cout << "ARMOR"; gotoxy(62, 37); cout << "POTIONS";
    gotoxy(12, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄"; gotoxy(36, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄"; gotoxy(60, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄";


    for (int i = 0; i < WeaponSlots.capacity(); i++) {
        gotoxy(8, 40+2*i);
        TurnAqua; cout << "*" << WeaponSlots[i].GetName() << " "; TurnLightRed;
        cout << WeaponSlots[i].GetWeaponDamage();
    }
    for (int i = 0; i < ArmorSlots.capacity(); i++) {
        gotoxy(34, 40+2*i);
        TurnAqua; cout << "*" << ArmorSlots[i].GetName() << " "; TurnGrey;
        cout << ArmorSlots[i].GetArmorPoints();
    }
    TurnAqua;
    gotoxy(58, 40); cout << "Remaining "; TurnGreen; cout << "HP"; TurnAqua; cout << " Potions: " << 2;
    gotoxy(58, 42); cout << "Remaining "; TurnBrightAqua; cout << "STM"; TurnAqua; cout << " Potions: " << 3;

//    gotoxy(7, 44);
//    int c = 1;
//    for (auto & i : ArmorSlots) {
//        c++;
//        cout << i.GetName() << " " << i.GetArmorPoints();
//        gotoxy(7+(c*20), 44);
//    }
//
//    for (auto & i : WeaponSlots) {
//        c++;
//        cout << i.GetName() << " " << i.GetWeaponDamage();
//        gotoxy(7+(c*20), 47);
//    }


}


