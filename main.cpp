#include <iostream>
#include <cstring>

class Item
{
private:
    std::string Name;

};

class Sword : public Item
{
private:
    int Damage;
    int Durability = 100;
public:
    void Attack(int enemy) {
        //do something
        this -> Durability--;
    }

};




int main() {

}
