#include "UserInterface.h"
#include "Utility.h"
//using namespace std;


int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    TurnBrightAqua;
    if (KeyCheck(6)) {
        gotoxy(0, 30);
        for (int i = 0; i < 120; i++) {
            gotoxy(0 + i, 0);
            cout << "▀";
            gotoxy(0 + i, 29);
            cout << "▄";
        }
        for (int i = 0; i < 30; i++) {
            gotoxy(0,  i);
            cout << "█";
            gotoxy(119, i);
            cout << "█";
        }
    }
    gotoxy(5, 5);
    cout<< "SUPER DUPER ROGULIKE 2001 MINI XS MAX 3310 PRO ELITE EXPERIENCE ROYAL 1.6 DELUXE VERSION EDITION 1ST GENERATION";
    TurnWhite;
    gotoxy(60, 24);
    cout << "EXIT";
    TurnBrightAqua;
    gotoxy(60, 14);
    cout << "START";
    gotoxy(64, 14);
    TurnWhite;
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 1) {
            TurnWhite;
            gotoxy(60, 24);
            cout << "EXIT";
            TurnBrightAqua;
            gotoxy(60, 14);
            cout << "START";
            gotoxy(64, 14);
            TurnWhite;

            flag++;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "START";
            TurnBrightAqua;
            gotoxy(60, 24);
            cout << "EXIT";
            gotoxy(63, 24);
            TurnWhite;
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
    TurnAqua;
    if (KeyCheck(6)) {
        gotoxy(0, 30);
        for (int i = 0; i < 120; i++) {
            gotoxy(0 + i, 0);
            cout << "▀";
            gotoxy(0 + i, 29);
            cout << "▄";
        }
        for (int i = 0; i < 30; i++) {
            gotoxy(0,  i);
            cout << "█";
            gotoxy(119, i);
            cout << "█";
        }
    }
    gotoxy(50, 5);
    cout << "SELECT CHARACTER`S CLASS";
    TurnWhite;
    gotoxy(60, 24);
    cout << "ARCHER";
    TurnAqua;
    gotoxy(60, 14);
    cout << "KNIGHT";
    gotoxy(64, 14);
    TurnWhite;
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 1) {
            TurnWhite;
            gotoxy(60, 24);
            cout << "ARCHER";
            TurnAqua;
            gotoxy(60, 14);
            cout << "KNIGHT";
            gotoxy(64, 14);
            TurnWhite;

            flag++;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "KNIGHT";
            TurnAqua;
            gotoxy(60, 24);
            cout << "ARCHER";
            gotoxy(63, 24);
            TurnWhite;
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

//==========================================================SHOP==========================================================
//========================================================================================================================

void OpenShop() {
    TurnYellow;
    if (KeyCheck(6)) {
        gotoxy(0, 30);
        for (int i = 0; i < 120; i++) {
            gotoxy(0 + i, 30);
            cout << "▀";
            gotoxy(0 + i, 58);
            cout << "▄";
        }
        for (int i = 0; i < 29; i++) {
            gotoxy(0, 30 + i);
            cout << "█";
            gotoxy(119, 30 + i);
            cout << "█";
        }
    }

    gotoxy(7, 32);
    TurnYellow;
    cout << " SHOP ";
    gotoxy(7, 33);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(100,31);
    TurnWhite;
    cout << "YOUR GOLD : ";    //+cout<<Ебейшее число текущкей голды
    TurnYellow;
    gotoxy(98,30);
    for (int i = 0; i < 3; i++) {
        gotoxy(98, 30 + i);
        cout << "█";
    }
    gotoxy(99,32);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";



    //header for colum
    gotoxy(26, 35);
    cout << "ITEM";
    gotoxy(21,36);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(70, 35);
    cout << "PRICE";
    gotoxy(65,36);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(98, 35);
    cout << "ATTRIBUTE";
    gotoxy(95,36);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(0, 30);
    int currentY = 38;
    gotoxy(6, currentY);
    cout << "=>";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3 and currentY < 56) {
            gotoxy(6, currentY);
            cout << "  ";
            currentY++;
            currentY++;
            gotoxy(6, currentY);
            cout << "=>";
        } else if (KeyCheck(Key) == 1 and currentY > 38) {
            gotoxy(6, currentY);
            cout << "  ";
            currentY--;
            currentY--;
            gotoxy(6, currentY);
            cout << "=>";
        }
    }
}


void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold) {
    gotoxy(8, 0);
    cout << "HP:" << Health;
    TurnBrightAqua;
    gotoxy(15, 0);
    cout << "STM:" << Stamina;
    TurnMagenta;
    gotoxy(23, 0);
    cout << "ARM:" << Armor;
    TurnLightRed;
    gotoxy(31, 0);
    cout << "DMG:" << Damage;
    TurnYellow;
    gotoxy(40, 0);
    cout << "GOLD:" << Gold;
    TurnMagenta;
    gotoxy(50, 0);
    cout << "Press I to open inventory, Press E to interact with something";
}

void ShowXY(int x, int y) {
    gotoxy(0, 28);
    cout << "        ";
    gotoxy(0, 28);
    cout << x << " " << y;
}