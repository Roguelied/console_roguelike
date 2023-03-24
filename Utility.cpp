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

void gotovd(int v, int d)
{
    COORD coord;
    coord.X = v;
    coord.Y = d;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}