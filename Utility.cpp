#include "Utility.h"

void InitializeSettings() {
    SetConsoleOutputCP( 65001 );
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void wait() {
    int a;
    cin >> a;
}