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
    int Gold{0}; string Name{"NonClassified"};
public:
    int GetStamina();
    void SetStamina(int Stamina);

    int GetGold();
    void SetGold(int Gold);

    void SetName(string Name);
    string GetName();
};

class PlayerController : public Player {
private:
    int y{20}; int x{10}; //current position
    int p_y{}; int p_x{}; //Previous position
public:
    void MovementInit(GameLevel HomeLevel);
};

class Rogue : public Player {
public:
    Rogue() {
        SetHealth(80);
        SetDamage(35);
        SetArmor(10);
    }
};


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
