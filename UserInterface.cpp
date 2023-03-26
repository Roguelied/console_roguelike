#include "UserInterface.h"
#include "Utility.h"
//using namespace std;


int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;

    gotoxy(60, 8);
    TurnWhite;
    cout << "START";
    gotoxy(60, 18);
    cout << "EXIT";
    //frame for START
    TurnGreen;
    gotoxy(58, 7); cout << "█████████";
    gotoxy(58, 9); cout << "█████████";
    gotoxy(58, 8); cout << "██";
    gotoxy(65, 8); cout << "██";
    gotoxy(66, 9);
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3) {
            gotoxy(58, 7); cout << "         ";
            gotoxy(58, 9); cout << "         ";
            gotoxy(58, 8); cout << "  ";
            gotoxy(65, 8); cout << "  ";
            //frame for EXIT
            gotoxy(58, 17); cout << "█████████";
            gotoxy(58, 19); cout << "█████████";
            gotoxy(58, 18); cout << "██";
            gotoxy(65, 18); cout << "██";
            gotoxy(66, 19);
            flag++;
        } else if (KeyCheck(Key) == 1) {
            gotoxy(58, 17); cout << "         ";
            gotoxy(58, 19); cout << "         ";
            gotoxy(58, 18); cout << "  ";
            gotoxy(65, 18); cout << "  ";
            //frame for START
            gotoxy(58, 7); cout << "█████████";
            gotoxy(58, 9); cout << "█████████";
            gotoxy(58, 8); cout << "██";
            gotoxy(65, 8); cout << "██";
            gotoxy(66, 9);
            flag++;
        }
        if (flag % 2 == 0 and KeyCheck(Key) == 5) {
            system("cls");
            return choice;
        } else if (flag % 2 == 1 and KeyCheck(Key) == 5) {
            exit(0);
        }
    }
}


string UserInterface::ClassMenu() {
    int flag = 0;
    string choice;
    TurnWhite;
    gotoxy(60, 8); cout << "KNIGHT";
    gotoxy(60, 18); cout << "ARCHER";
    //frame for START
    TurnGreen;
    gotoxy(58, 7); cout << "██████████";
    gotoxy(58, 9); cout << "██████████";
    gotoxy(58, 8); cout << "██";
    gotoxy(66, 8); cout << "██";
    gotoxy(67, 9);
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3) {
            gotoxy(58, 7); cout << "          ";
            gotoxy(58, 9); cout << "          ";
            gotoxy(58, 8); cout << "  ";
            gotoxy(66, 8); cout << "  ";
            //frame for EXIT
            gotoxy(58, 17); cout << "██████████";
            gotoxy(58, 19); cout << "██████████";
            gotoxy(58, 18); cout << "██";
            gotoxy(66, 18); cout << "██";
            gotoxy(67, 19);
            flag++;
        } else if (KeyCheck(Key) == 1) {
            gotoxy(58, 17); cout << "          ";
            gotoxy(58, 19); cout << "          ";
            gotoxy(58, 18); cout << "  ";
            gotoxy(66, 18); cout << "  ";
            //frame for START
            gotoxy(58, 7); cout << "██████████";
            gotoxy(58, 9); cout << "██████████";
            gotoxy(58, 8); cout << "██";
            gotoxy(66, 8); cout << "██";
            gotoxy(67, 9);
            flag++;
        }
        if (flag % 2 == 0 and KeyCheck(Key) == 5) {
            system("cls");
            return "Knight";
        } else if (flag % 2 == 1 and KeyCheck(Key) == 5) {
            system("cls");
            return "Archer";
        }
    }
}
