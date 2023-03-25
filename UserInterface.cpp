#include "UserInterface.h"
#include "Utility.h"
//using namespace std;


int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    gotoxy(60, 8);
    cout << "START";
    gotoxy(60, 18);
    cout << "EXIT";
    //frame for START
    gotoxy(58, 7);
    cout << "█████████";
    gotoxy(58, 9);
    cout << "█████████";
    gotoxy(58, 8);
    cout << "██";
    gotoxy(65, 8);
    cout << "██";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3) {
            //" "
            gotoxy(58, 7);
            cout << "         ";
            gotoxy(58, 9);
            cout << "         ";
            gotoxy(58, 8);
            cout << "  ";
            gotoxy(65, 8);
            cout << "  ";
            //frame for EXIT
            gotoxy(58, 17);
            cout << "█████████";
            gotoxy(58, 19);
            cout << "█████████";
            gotoxy(58, 18);
            cout << "██";
            gotoxy(65, 18);
            cout << "██";
            flag++;
        } else if (KeyCheck(Key) == 1) {
            //" "
            gotoxy(58, 17);
            cout << "         ";
            gotoxy(58, 19);
            cout << "         ";
            gotoxy(58, 18);
            cout << "  ";
            gotoxy(65, 18);
            cout << "  ";
            //frame for START
            gotoxy(58, 7);
            cout << "█████████";
            gotoxy(58, 9);
            cout << "█████████";
            gotoxy(58, 8);
            cout << "██";
            gotoxy(65, 8);
            cout << "██";
            flag++;
        }
        if (flag % 2 == 0 and KeyCheck(Key) == 5) {
            return choice;
        } else if (flag % 2 == 1 and KeyCheck(Key) == 5) {
            exit(0);
        }
    }
}


string UserInterface::ClassCoiceMenu() {
    int flag = 0;
    string choice;
    gotoxy(60, 8);
    cout << "KNIGHT";
    gotoxy(60, 18);
    cout << "ARCHER";
    //frame for START
    gotoxy(58, 7);
    cout << "██████████";
    gotoxy(58, 9);
    cout << "██████████";
    gotoxy(58, 8);
    cout << "██";
    gotoxy(66, 8);
    cout << "██";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3) {
            //" "
            gotoxy(58, 7);
            cout << "          ";
            gotoxy(58, 9);
            cout << "          ";
            gotoxy(58, 8);
            cout << "  ";
            gotoxy(66, 8);
            cout << "  ";
            //frame for EXIT
            gotoxy(58, 17);
            cout << "██████████";
            gotoxy(58, 19);
            cout << "██████████";
            gotoxy(58, 18);
            cout << "██";
            gotoxy(66, 18);
            cout << "██";
            flag++;
        } else if (KeyCheck(Key) == 1) {
            //" "
            gotoxy(58, 17);
            cout << "          ";
            gotoxy(58, 19);
            cout << "          ";
            gotoxy(58, 18);
            cout << "  ";
            gotoxy(66, 18);
            cout << "  ";
            //frame for START
            gotoxy(58, 7);
            cout << "██████████";
            gotoxy(58, 9);
            cout << "██████████";
            gotoxy(58, 8);
            cout << "██";
            gotoxy(66, 8);
            cout << "██";
            flag++;
        }
        if (flag % 2 == 0 and KeyCheck(Key) == 5) {
            choice = "KNIGHT";
            return choice;
        } else if (flag % 2 == 1 and KeyCheck(Key) == 5) {
            choice = "ARCHER";
            return choice;
        }
    }
}
