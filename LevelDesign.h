#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"
#include "PlayerItems.h"
#include "Character.h"

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
    void SetItemToCoordinates(const PlayerItem& Item, int x, int y);
    void SetEnemyToCoordinates(Enemy Enemy, int x, int y);

};



#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
