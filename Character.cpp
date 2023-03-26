#include "Character.h"
#include "LevelDesign.h"
#include "Utility.h"
#include <cstdlib>

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




/*============================================================ PlayerController ============================================================
===================================================================================================================================== */

void PlayerController::TakeItem(class Armor Item) {
    InvSlot Slot;
    Slot.Name = Item.GetName();
    Slot.Point = Item.GetArmorPoints();
    Inventory.push_back(Slot);
}

void PlayerController::TakeItem(Weapon Item){
    InvSlot Slot;
    Slot.Name = Item.GetName();
    Slot.Point = Item.GetWeaponDamage();
    Inventory.push_back(Slot);
}

void PlayerController::TakeItem(Potion Item) {
    InvSlot Slot;
    Slot.Name = Item.GetName();
    //Slot.Point = Item.Get
    //Inventory.push_back(Slot);
}

void PlayerController::DropItem(InvSlot Item) {
    //inventory pop item
}


void PlayerController::OpenInventory() {
    //system("cls");
    gotoxy(0, 30);
    for (int i = 0; i < 120; i++) {
        gotoxy(0+i, 30);
        cout << "*";
        gotoxy(0+i, 58);
        cout << "*";
    }
    for (int i = 0; i < 29; i++) {
        gotoxy(0, 30+i);
        cout << "*";
        gotoxy(119, 30+i);
        cout << "*";
    }
    gotoxy(25, 32);
    cout << ".__                                  __                           "; gotoxy(25, 33);
    cout <<  "|__|  ____  ___  __  ____    ____  _/  |_   ____  _______  ___.__."; gotoxy(25, 34);
    cout <<  "|  | /    \\ \\  \\/ /_/ __ \\  /    \\ \\   __\\ /  _ \\ \\_  __ \\<   |  |"; gotoxy(25, 35);
    cout <<  "|  ||   |  \\ \\   / \\  ___/ |   |  \\ |  |  (  <_> ) |  | \\/ \\___  |"; gotoxy(25, 36);
    cout <<  "|__||___|  /  \\_/   \\___  >|___|  / |__|   \\____/  |__|    / ____|"; gotoxy(25, 37);
    cout <<  "         \\/             \\/      \\/                         \\/     ";

    gotoxy(7, 44);
    int c = 1;
    for (auto & i : Inventory) {
        c++;
        cout << i.Name << " " << i.Point;
        gotoxy(7+(c*20), 44);
    }

}

void PlayerController::InteractWith() {
    gotoxy(0, 0); cout << "e: Input detected";
}
void PlayerController::MovementInit(GameLevel Level) {
    Level.DrawVisibleField(x, y);

    gotoxy(8, 0); cout << "HP:" << GetHealth();
    TurnBrightAqua;
    gotoxy(15, 0); cout << "STM:" << GetStamina();
    TurnMagenta;
    gotoxy(23, 0); cout << "ARM:" << GetArmor();
    TurnLightRed;
    gotoxy(31, 0); cout << "DMG:" << GetDamage();
    TurnYellow;
    gotoxy(40, 0); cout << "Press I to open inventory, Press E to interact with something";

    TurnGreen;
    EnemyAI EnemyAI;
    string PlayerSymbol = GetPlayerSymbol();

    gotoxy(x, y);
    cout << PlayerSymbol;
    gotoxy(x, y);

    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();
            if (KeyCheck(Key) == 1 and WallCheck(Level, x, y - 1) == 0) {
                gotoxy(x, y - 1); cout << PlayerSymbol;
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y--;
            }
            if (KeyCheck(Key) == 2 and WallCheck(Level, x - 1, y) == 0) {
                gotoxy(x - 1, y); cout << PlayerSymbol;
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x--;
            }
            if (KeyCheck(Key) == 3 and WallCheck(Level, x, y + 1) == 0) {
                gotoxy(x, y + 1); cout << PlayerSymbol;
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y++;
            }
            if (KeyCheck(Key) == 4 and WallCheck(Level, x + 1, y) == 0) {
                gotoxy(x + 1, y); cout << PlayerSymbol;
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x++;
            }


            if (KeyCheck(Key) == 5) {
                InteractWith();
            }
            if (KeyCheck(Key) == 6) {
                OpenInventory();
            }


            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                Level.DrawVisibleField(x, y);
                gotoxy(8, 0); cout << "HP:" << GetHealth() << " ";
                TurnBrightAqua;
                gotoxy(15, 0); cout << "STM:" << GetStamina();
                TurnMagenta;
                gotoxy(23, 0); cout << "ARM:" << GetArmor();
                TurnLightRed;
                gotoxy(31, 0); cout << "DMG:" << GetDamage();
                TurnYellow;
                gotoxy(40, 0); cout << "Press I to open inventory, Press E to interact with something";

                TurnLightRed;
                EnemyAI.AutoMovement(Level);
                TurnGreen;
                Level.SetToCoordinates(" ", x, y);
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


