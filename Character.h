#ifndef CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#define CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#include "Utility.h"
#include "LevelDesign.h"
#include "PlayerItems.h"

class Character {
private:
    int Health{100};
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
    vector<InvSlot> Inventory; //Utility.h

    void TakeItem(class Armor & Item);
    void TakeItem(Weapon & Item);
    void TakeItem(Potion & Item);
    void DropItem(InvSlot & Item);

    void InteractWith();
    string GetPlayerSymbol();
    void MovementInit(Player & Player, GameLevel & Level);
    int WallCheck(GameLevel & Level, int x, int y);
    void CheckForEnemiesAround(GameLevel & Level, Player & Player, int x, int y);

    int x{5}; int y{2}; //current position
};

/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

class Enemy : public Character {
public:
    Enemy(int EnemyType); //0 - DefaultEnemy, 1 - Boss
    Enemy();
};


class EnemyAI : public PlayerController {
private:
    string EnemySymbol{"&"};
public:
    EnemyAI();
    string GetEnemySymbol();
    void AutoMovement(GameLevel & Level, int x, int y);
};

/*=====================================================================================================================================
===================================================================================================================================== */

#endif //CONSOLE_ROGUELIKE_CPP_CHARACTER_H
