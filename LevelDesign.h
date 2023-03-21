#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
private:

public:

    string GameLevelArray[29][119];
    GameLevel(int RoomType);

    void DrawGameLevel();
    void Draw(int x1, int y1, int x2, int y2,string symbol);
    void DrawFrame();
    void DrawWall();
    void DrawAir();

    void DrawFill(int x1, int y1, int x2, int y2);


};
#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
