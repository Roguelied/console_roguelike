//
// Created by kolonist on 18.03.2023.
//

#include "PlayerItems.h"
#include "Utility.h"

PlayerItem::PlayerItem(string Name) {
    this->Name = Name;
}

string PlayerItem::GetName() {
    return Name;
}

Armor::Armor(string Name, int ArmorPoints) : PlayerItem(Name) {
    this -> ArmorPoints = ArmorPoints;
}

int Armor::GetArmorPoints() {
    return ArmorPoints;
}

void Armor::SetArmorPoints(int ArmorPoints) {
    this->ArmorPoints = ArmorPoints;
}

Weapon::Weapon(string Name, int WeaponDamage) : PlayerItem(Name) {
    this->WeaponDamage = WeaponDamage;

}

int Weapon::GetWeaponDamage() {
    return WeaponDamage;
}

void Weapon::SetWeaponDamage(int WeaponDamage) {
    this->WeaponDamage = WeaponDamage;
}
