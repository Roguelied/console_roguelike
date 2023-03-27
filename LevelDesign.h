#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
private:
    string GameLevelArray[35][122];

public:
    vector<Coords> EnemyCoordinates;

    GameLevel(int RoomType);
    string GetFromCoordinates(int x, int y);
    void SetToCoordinates(string NewMapElement, int x, int y);
    void DrawGameLevel();
    void Draw(int x1, int y1, int x2, int y2,string symbol);
    void DrawFrame();
    void DrawVisibleField(int x, int y);
    void ColorCheck(int x, int y);
    int BossRoom(int x1,int y1,int x2,int y2);
    void RandItemOrder();
    int random(int first, int second);
    void ExitCurrentStartFollowing();
    void SetEnemyCoordinates(int x, int y);
};

class TreasureBox {
private:
    int x; int y;
    string BoxSymbol{"$"};
public:
};

#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
