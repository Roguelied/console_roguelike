#include "UserInterface.h"
#include "Utility.h"
//using namespace std;


int UserInterface::ShowStartScreen() {

    cout << "Введите 1 чтобы начать игру или введите 0 чтобы выйти"<<endl;
    int Result;
    cin >> Result;

    if (Result == 1) {
        return 1;
    } else if (Result == 0) {
        return 0;
    }
}
