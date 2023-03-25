#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
private:
    string GameLevelArray[35][122];
public:
    GameLevel(int RoomType);
    string GetFromCoordinates(int x, int y);
    void SetToCoordinates(string NewMapElement, int x, int y);
    void DrawGameLevel();
    void Draw(int x1, int y1, int x2, int y2,string symbol);
    void DrawFrame();
    void DrawVisibleField(int x, int y);
    void ColorCheck(int x, int y);
    int BossRoom(int x1,int y1,int x2,int y2);
};



#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
