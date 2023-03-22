#include "UserInterface.h"
#include "Utility.h"
#include <iostream>
#include <string>
using namespace std;


int UserInterface::ShowStartScreen() {

    cout << "Введите 1 чтобы начать игру или введите 0 чтобы выйти";
    int Result;
    cin >> Result;

    if (Result == 1) {
        return 1;
    } else if (Result == 0) {
        return 0;
    }
}
