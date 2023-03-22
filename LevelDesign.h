#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
private:
    string GameLevelArray[29][119];
public:
    GameLevel(int RoomType);
    string GetFromCoordinates(int x, int y);
    void SetToCoordinates(string NewMapElement, int x, int y);
    void DrawGameLevel();
    void Draw(int x1, int y1, int x2, int y2,string symbol);
    void DrawFrame();
    void DrawLevel();

    void DrawFill(int x1, int y1, int x2, int y2);

};



#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
