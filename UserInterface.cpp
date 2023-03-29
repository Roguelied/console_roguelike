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

void OpenInventory(vector<InvSlot> Inventory) {
    //system("cls");
    gotoxy(0, 30);
    for (int i = 0; i < 120; i++) {
        gotoxy(0+i, 30);
        cout << "*";
        gotoxy(0+i, 58);
        cout << "*";
    }
    for (int i = 0; i < 29; i++) {
        gotoxy(0, 30+i);
        cout << "*";
        gotoxy(119, 30+i);
        cout << "*";
    }
    gotoxy(25, 32);
    cout << ".__                                  __                           "; gotoxy(25, 33);
    cout <<  "|__|  ____  ___  __  ____    ____  _/  |_   ____  _______  ___.__."; gotoxy(25, 34);
    cout <<  "|  | /    \\ \\  \\/ /_/ __ \\  /    \\ \\   __\\ /  _ \\ \\_  __ \\<   |  |"; gotoxy(25, 35);
    cout <<  "|  ||   |  \\ \\   / \\  ___/ |   |  \\ |  |  (  <_> ) |  | \\/ \\___  |"; gotoxy(25, 36);
    cout <<  "|__||___|  /  \\_/   \\___  >|___|  / |__|   \\____/  |__|    / ____|"; gotoxy(25, 37);
    cout <<  "         \\/             \\/      \\/                         \\/     ";

    gotoxy(7, 44);
    int c = 1;
    for (auto & i : Inventory) {
        c++;
        cout << i.Name << " " << i.Point;
        gotoxy(7+(c*20), 44);
    }

}

void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold) {
    gotoxy(8, 0); cout << "HP:" << Health;
    TurnBrightAqua;
    gotoxy(15, 0); cout << "STM:" << Stamina;
    TurnMagenta;
    gotoxy(23, 0); cout << "ARM:" << Armor;
    TurnLightRed;
    gotoxy(31, 0); cout << "DMG:" << Damage;
    TurnYellow;
    gotoxy(40, 0); cout << "GOLD:" << Damage;
    TurnMagenta;
    gotoxy(45, 0); cout << "Press I to open inventory, Press E to interact with something";
}