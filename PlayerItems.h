//
// Created by kolonist on 18.03.2023.
//

#ifndef CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H
#define CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H
#include "Utility.h"


class PlayerItem
{
private:
    string Name;
public:
    PlayerItem(string Name);
    string GetName();

};
class Armor: public PlayerItem
{
private:
    int ArmorPoints;
public:
    Armor(string Name, int ArmorPoints);
    int GetArmorPoints();
    void SetArmorPoints(int ArmorPoints);
};

class Weapon: public PlayerItem
{
private:
    int WeaponDamage;
public:
    Weapon(string Name, int WeaponDamage);
    int GetWeaponDamage();
    void SetWeaponDamage(int WeaponDamage);
};

class Potion: public PlayerItem
{
private:
    int Health{30};
    int Stamina{40};
public:
    Potion(string Name);
    int GetHealth();
    int GetStamina();
};











#endif //CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H

