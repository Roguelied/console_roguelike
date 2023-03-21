#include "LevelDesign.h"
#include "Utility.h"

using namespace std;


//Room resolution 29/119
GameLevel::GameLevel(int RoomType) {
    /*Пусть тут будет несколько комнат, которые вы будете сами строить в конструкторе класса.
      Тип комнаты будет зависеть от того, какой номер передается в конструктор.
      Например, если вы вызвали конструктор GameLevel(0), то построится начальная комната,
      в которой игрок спавнится.
    */

    //Строю белая рамка по разрешению, указанному в LevelDesign.h
    if (RoomType == 0) {
        for (auto & i: GameLevelArray) {
            for (auto &j: i) {
                j = " ";
            }
            DrawFrame();
            DrawWall();
            DrawAir();
        }
    }
}




void GameLevel::DrawGameLevel() {
    for (auto & i : GameLevelArray) {
        for (auto & j : i) {
            cout << j;
        }
        cout << endl;
    }
}

void GameLevel::Draw(int x1, int y1, int x2, int y2, std::string symbol) {
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            GameLevelArray[i][j] = symbol;
        }
    }
}



void GameLevel::DrawFill(int x1, int y1, int x2, int y2) {
}

void GameLevel::DrawFrame() {
    Draw(0, 0, 2, 29,"█");
    Draw(0, 0, 119, 1,"█");
    Draw(117, 0, 119, 29,"█");
    Draw(0, 28, 129, 29,"█");
}
void GameLevel::DrawWall() {
    Draw(2,1,117,28,"░");
}
void GameLevel::DrawAir() {
    Draw(10,8,50,20," ");
    Draw(50,13,60,15," ");
    Draw(59,14,62,17," ");
    Draw(61,16,64,19," ");
    Draw(63,18,66,21," ");
    Draw(60,21,69,26," ");
    Draw(59,13,75,15," ");
    Draw(59,9,61,13," ");
    Draw(60,9,67,10," ");
    Draw(65,8,69,11," ");
    Draw(74,11,80,17," ");
    Draw(76,17,78,20," ");
    Draw(72,20,82,23," ");
    Draw(79,12,86,13," ");
    Draw(85,7,87,13," ");
    Draw(82,4,89,7," ");
    Draw(85,9,98,10," ");
    Draw(97,9,99,13," ");
    Draw(94,12,102,15," ");
    Draw(97,14,99,18," ");
    Draw(98,17,100,19," ");
    Draw(99,18,101,20," ");
    Draw(100,19,102,21," ");
    Draw(99,21,101,23," ");
    Draw(100,22,105,23," ");
    Draw(104,18,113,27," ");
    Draw(113,25,116,27," ");
    Draw(115,25,116,27,"#");
}


