
#include "Utility.h"

#include <string>
#include <iostream>
#include <windows.h>


int main() {
    SetConsoleOutputCP( 65001 );
    for (;;) {PlayCharacterAttackAnimation(); }

    int a;
    std::cin >> a;
}
