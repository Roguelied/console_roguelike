#include "Utility.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

class Player {
    friend void Player_class (Player &prime);

private:
    int health = 100;
    int damage = 10;
    int stamina = 100;

public:
    string name;
    int chosen_class;

    void Print(){
        cout << "Имя " << name << "\nКласс " << chosen_class << endl << endl;
    }

};

void Player_class (Player &prime) {
    if (prime.chosen_class == 0){
        prime.health *= 1.5;
        prime.damage *= 2;
    } else {
        prime.damage *= 1.5;
        prime.stamina *= 2;
    }

};

int main() {
    setlocale(LC_ALL, "ru");
    Player player;
    cout << "Введите имя игрока:\n"; cin >> player.name;
    cout << "Выберите класс персонажа (0 - воин, 1 - лучник):\n"; cin >> player.chosen_class;
    player.Print();

    return 0;
}
