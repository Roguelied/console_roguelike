#include "UserInterface.h"
#include "Utility.h"
//using namespace std;


int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    TurnMagenta;
    gotoxy(5, 5);
    cout
            << "SUPER DUPER ROGULIKE 2001 MINI XS MAX 3310 PRO ELITE EXPERIENCE ROYAL 1.6 DELUXE VERSION EDITION 1ST GENERATION";
    TurnWhite;
    gotoxy(60, 24);
    cout << "EXIT";
    TurnBackGreen;
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
            TurnBackGreen;
            gotoxy(60, 14);
            cout << "START";
            gotoxy(64, 14);
            TurnWhite;

            flag++;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "START";
            TurnBackGreen;
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
    TurnMagenta;
    gotoxy(50, 5);
    cout << "SELECT CHARACTER`S CLASS";
    TurnWhite;
    gotoxy(60, 24);
    cout << "ARCHER";
    TurnBackGreen;
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
            TurnBackGreen;
            gotoxy(60, 14);
            cout << "KNIGHT";
            gotoxy(64, 14);
            TurnWhite;

            flag++;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "KNIGHT";
            TurnBackGreen;
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

void OpenInventory(vector<InvSlot> Inventory) {
    //system("cls");
    gotoxy(0, 30);
    for (int i = 0; i < 120; i++) {
        gotoxy(0 + i, 30);
        cout << "*";
        gotoxy(0 + i, 58);
        cout << "*";
    }
    for (int i = 0; i < 29; i++) {
        gotoxy(0, 30 + i);
        cout << "*";
        gotoxy(119, 30 + i);
        cout << "*";
    }
    gotoxy(25, 32);
    cout << ".__                                  __                           ";
    gotoxy(25, 33);
    cout << "|__|  ____  ___  __  ____    ____  _/  |_   ____  _______  ___.__.";
    gotoxy(25, 34);
    cout << "|  | /    \\ \\  \\/ /_/ __ \\  /    \\ \\   __\\ /  _ \\ \\_  __ \\<   |  |";
    gotoxy(25, 35);
    cout << "|  ||   |  \\ \\   / \\  ___/ |   |  \\ |  |  (  <_> ) |  | \\/ \\___  |";
    gotoxy(25, 36);
    cout << "|__||___|  /  \\_/   \\___  >|___|  / |__|   \\____/  |__|    / ____|";
    gotoxy(25, 37);
    cout << "         \\/             \\/      \\/                         \\/     ";

    gotoxy(7, 44);
    int c = 1;
    for (auto &i: Inventory) {
        c++;
        cout << i.Name << " " << i.Point;
        gotoxy(7 + (c * 20), 44);
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
            cout << "$";
            gotoxy(0 + i, 58);
            cout << "$";
        }
        for (int i = 0; i < 29; i++) {
            gotoxy(0, 30 + i);
            cout << "$";
            gotoxy(119, 30 + i);
            cout << "$";
        }
    }
    TurnMagenta;
    gotoxy(56, 30);
    cout << "SHOP";
    //header for colum
    TurnAqua;
    gotoxy(25, 32);
    cout << "ITEM";
    gotoxy(70, 32);
    cout << "PRICE";
    gotoxy(98, 32);
    cout << "ATTRIBUTE";
    TurnWhite;
    //column border
    for (int i = 0; i < 25; i++) {
        gotoxy(59, 33 + i);
        cout << "|";
        gotoxy(84, 33 + i);
        cout << "|";
    }
    gotoxy(0, 30);
    TurnBrightAqua;
    cout << "Your Gold : ";    //+cout<<Ебейшее число текущкей голды
    TurnBrightGreen;
    int currentY = 33;
    gotoxy(1, currentY);
    cout << "=>";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 3 and currentY < 57) {
            gotoxy(1, currentY);
            cout << "  ";
            currentY++;
            gotoxy(1, currentY);
            cout << "=>";
        } else if (KeyCheck(Key) == 1 and currentY > 33) {
            gotoxy(1, currentY);
            cout << "  ";
            currentY--;
            gotoxy(1, currentY);
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