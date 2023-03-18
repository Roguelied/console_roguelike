#include "LevelDesign.h"
#include "Utility.h"

using namespace std;


//Room resolution 29/119
GameLevel::GameLevel(int RoomType)
{
    /*Пусть тут будет несколько комнат, которые вы будете сами строить в конструкторе класса.
      Тип комнаты будет зависеть от того, какой номер передается в конструктор.
      Например, если вы вызвали конструктор GameLevel(0), то построится начальная комната,
      в которой игрок спавнится.
    */

    //Строю белый квадрат по разрешению, указанному в LevelDesign.h
    if (RoomType == 0) {
        for (auto &i: GameLevelArray) {
            for (auto &j: i) {
                j = " ";
            }
        }

        //Создаю пустое пространство (комнату)
        for (int i = 9; i < 18; i++) {
            for (int j = 7; j < 30; j++) {
                GameLevelArray[i][j] = " ";
            }
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
