#ifndef CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#define CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#include "Utility.h"
#include "LevelDesign.h"
#include "PlayerItems.h"

class Character {
private:
    int MaxHealth{100}; int Health{100};
    int Damage{1};
    int Armor{1};
    string Name{"NonClassified"};

public:
    int GetHealth();
    void SetHealth(int Health);

    int GetDamage();
    void SetDamage(int Damage);

    int GetArmor();
    void SetArmor(int Armor);

    void SetName(string Name);
    string GetName();
};


class Player : public Character {
protected:
    int MaxStamina{100}; int Stamina{100};
    int Gold{0};
public:
    Player(string ClassName);

    Player();

    int GetStamina();
    void SetStamina(int Stamina);

    int GetGold();
    void SetGold(int Gold);
};

class PlayerController : public Player {
private:
    string PlayerSymbol{"@"};

    //lvl 1 - 28 14
public:
    typedef struct InvSlot {
        string Name;
        int Point;
    } InvSlot;

    vector<InvSlot> Inventory;

    void TakeItem(class Armor Item);
    void TakeItem(Weapon Item);
    void TakeItem(Potion Item);

    void DropItem(InvSlot Item);
    void OpenInventory();
    void InteractWith();
    string GetPlayerSymbol();
    void MovementInit(GameLevel HomeLevel);
    int WallCheck(GameLevel Level, int x, int y);

    int x{5}; int y{2}; //current position
    int GetX();
    int GetY();
};






class Enemy : public Character {

public:
    Enemy(int EnemyType);
    Enemy();
    //Enemy();
    //0 - DefaultEnemy, 1 - Boss
};

class EnemyAI : public PlayerController {
private:
    string EnemySymbol{"&"};
public:
    EnemyAI();
    string GetEnemySymbol();
    void AutoMovement(GameLevel HomeLevel, int x, int y);

    int v{15}; int d{10}; //current position
    void SetV(int v);
    void SetD(int d);

    int GetV();
    int GetD();
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
