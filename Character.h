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
    string PlayerSymbol{"@"};
    int x{5}; int y{2}; //current position
public:
    string GetPlayerSymbol();
    void MovementInit(GameLevel HomeLevel);
    int WallCheck(GameLevel Level, int x, int y);
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

class Enemy : public Character { };

class EnemyAI : public Enemy {
private:
    string EnemySymbol{"&"};
    int v{10}; int d{10}; //current position

public:
    string GetEnemySymbol();
    void AutoMovement(GameLevel HomeLevel);
    int WallCheck(GameLevel Level, int v, int d);
};

class Kvadrupter : public Character {
public:
    Kvadrupter() {
        SetHealth(10);
        SetDamage(100);
        SetArmor(50);
    }
};

class Gnil : public Character {
public:
    Gnil() {
        SetHealth(150);
        SetDamage(10);
        SetArmor(50);
    }
};

class Mraz : public Character {
public:
    Mraz() {
        SetHealth(200);
        SetDamage(1);
        SetArmor(100);
    }
};

#endif //CONSOLE_ROGUELIKE_CPP_CHARACTER_H
