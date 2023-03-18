#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
public:
    string GameLevelArray[29][119];
    GameLevel(int RoomType);
    void DrawGameLevel();

};
#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
