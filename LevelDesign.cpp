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
        }

        DrawFrame();
        DrawWall();
        DrawAir();
    }


//    if(RoomType == 1){
//        for (auto & i :GameLevelArray){
//            for (auto & j : i){
//
//            }
//        }



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
    Draw(2,1,117,28,"#");
}
void GameLevel::DrawAir() {
    Draw(10,8,50,20," ");
    Draw(50,13,60,15," ");
}


