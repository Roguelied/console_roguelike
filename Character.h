#ifndef CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#define CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#include "Utility.h"
#include "LevelDesign.h"

class Character {
private:
    int MaxHealth{100}; int Health{100};
    int Damage{1};
    int Armor{1};

public:
    int GetHealth();
    void SetHealth(int Health);

    int GetDamage();
    void SetDamage(int Damage);

    int GetArmor();
    void SetArmor(int Armor);

};


class Player : public Character {
protected:
    int MaxStamina{100}; int Stamina{100};
    int Gold{0};
public:
    int GetStamina();
    void SetStamina(int Stamina);

    int GetGold();
    void SetGold(int Gold);
};

class PlayerController : public Player {
private:
    int y{20};
    int x{10};
public:
    void Movement(GameLevel HomeLevel) {
        for (;;) {
            if (_kbhit()) {
                switch (_getch()) {
                    case 'e':
                        //something

                    case 'w':
                        HomeLevel.GameLevelArray[x][y] = "█"; x--;
                        HomeLevel.GameLevelArray[x][y] = "@";
                        system("cls");
                        HomeLevel.DrawGameLevel();
                        continue;
                    case 'd':
                        HomeLevel.GameLevelArray[x][y] = "█"; y++;
                        HomeLevel.GameLevelArray[x][y] = "@";
                        system("cls");
                        HomeLevel.DrawGameLevel();
                        continue;
                    case 's':
                        HomeLevel.GameLevelArray[x][y] = "█"; x++;
                        HomeLevel.GameLevelArray[x][y] = "@";
                        system("cls");
                        HomeLevel.DrawGameLevel();
                        continue;
                    case 'a':
                        HomeLevel.GameLevelArray[x][y] = "█"; y--;
                        HomeLevel.GameLevelArray[x][y] = "@";
                        system("cls");
                        HomeLevel.DrawGameLevel();
                        continue;

                }
            }
        }
    }

};


class Rogue : public Player {
public:
    Rogue() {
        SetHealth(80);
        SetDamage(35);
        SetArmor(10);
    }
};

//Default player controllable,
class Swordsman : public Player {
public:
    Swordsman() {
        SetHealth(120);
        SetDamage(20);
        SetArmor(20);
    }
};

// Ability : Can skip first enemy attack instance
class Archer : public Player {
public:
    Archer() {
        SetHealth(100);
        SetDamage(25);
        SetArmor(0);
    }
};

class Monk : public Player {
public:
    Monk() {
        SetHealth(110);
        SetDamage(10);
        SetArmor(60);
    }
};

class Enemy : Character {

};

#endif //CONSOLE_ROGUELIKE_CPP_CHARACTER_H
