#include "LevelDesign.h"

#include <utility>
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
        for (auto &i: GameLevelArray) {
            for (auto &j: i) {
                j = " ";
            }
            DrawFrame();
            Draw(2, 1, 117, 28, "░");
            Draw(10, 8, 50, 20, " ");
            Draw(50, 13, 60, 15, " ");
            Draw(59, 14, 62, 17, " ");
            Draw(61, 16, 64, 19, " ");
            Draw(63, 18, 66, 21, " ");
            Draw(60, 21, 69, 26, " ");
            Draw(59, 13, 75, 15, " ");
            Draw(59, 9, 61, 13, " ");
            Draw(60, 9, 67, 10, " ");
            Draw(65, 8, 69, 11, " ");
            Draw(74, 11, 80, 17, " ");
            Draw(76, 17, 78, 20, " ");
            Draw(72, 20, 82, 23, " ");
            Draw(79, 12, 86, 13, " ");
            Draw(85, 7, 87, 13, " ");
            Draw(82, 4, 89, 7, " ");
            Draw(85, 9, 98, 10, " ");
            Draw(97, 9, 99, 13, " ");
            Draw(94, 12, 102, 15, " ");
            Draw(97, 14, 99, 18, " ");
            Draw(98, 17, 100, 19, " ");
            Draw(99, 18, 101, 20, " ");
            Draw(100, 19, 102, 21, " ");
            Draw(99, 21, 101, 23, " ");
            Draw(100, 22, 105, 23, " ");
            Draw(104, 18, 113, 27, " ");
            Draw(113, 25, 116, 27, " ");
            Draw(115, 25, 116, 27, "#");

        }
    }
    if (RoomType == 1) {
        for (auto &i: GameLevelArray) {
            for (auto &j: i) {
                j = " ";
            }
        }
        DrawFrame();
        Draw(2, 1, 117, 28, "░");
        Draw(3, 2, 7, 4, " ");
        Draw(3, 2, 4, 4, "#");
        Draw(6, 3, 8, 5, " ");
        Draw(7, 4, 9, 7, " ");
        Draw(6, 6, 8, 9, " ");
        Draw(6, 9, 22, 15, " ");
        Draw(13, 8, 17, 9, " ");
        Draw(11, 6, 19, 8, " ");
        Draw(20, 14, 22, 18, " ");
        Draw(16, 17, 21, 18, " ");
        Draw(13, 16, 18, 19, " ");
        Draw(15, 19, 16, 24, " ");
        Draw(16, 23, 88, 24, " ");
        Draw(22,12,40,13," ");
        Draw(23,10,27,14," ");
        Draw(35,6,55,15," ");
        Draw(33,7,35,8," ");
        Draw(29,5,33,9," ");
        Draw(35,13,38,17," ");
        Draw(33,16,36,18," ");
        Draw(31,17,34,21," ");
        Draw(33,20,36,22," ");
        Draw(35,21,38,23," ");
        Draw(46,21,54,26," ");
        Draw(55,14,57,18," ");
        Draw(54,18,62,20," ");
        Draw(62,19,85,20," ");
        Draw(85,19,88,23," ");
        Draw(55,8,57,9," ");
        Draw(57,8,63,11," ");
        Draw(63,9,80,10," ");

        Draw(110,25,116,27," ");
        Draw(115,25,116,27,"#");
    }
}


void GameLevel::DrawGameLevel() {
    for (auto &i: GameLevelArray) {
        for (auto &j: i) {
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
    Draw(0, 0, 2, 29, "█");
    Draw(0, 0, 119, 1, "█");
    Draw(117, 0, 119, 29, "█");
    Draw(0, 28, 129, 29, "█");
}



string GameLevel::GetFromCoordinates(int x, int y) {
    return GameLevelArray[y][x];
}

void GameLevel::SetToCoordinates(string NewMapElement, int x, int y) {
    GameLevelArray[y][x] = std::move(NewMapElement);
}


