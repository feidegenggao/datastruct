/*
 * =====================================================================================
 *
 *       Filename:  Maze.cpp
 *
 *    Description:  completion of Maze
 *
 *        Version:  1.0
 *        Created:  08/12/12 20:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * =====================================================================================
 */
#include   "Maze.h"

Maze::Maze(int x, int y)
{
    Point potinit;
    potinit.isPass = 0;
    potinit.isThrough = 0;

    vector<Point> potx(x, potinit);

    for (int i = 0; i < y; i++)
    {
        maze.push_back(potx);
    }
}

Maze::~Maze()
{
}

int Maze::init()
{
    //inital the Maze
}

bool Maze::Pass(PosType &pos)
{
    if (maze[pos.x, pos.y].isPass == 1)
    {
        return true;
    }
    else (maze[pos.x, pos.y].isPass == 0)
    {
        return false;
    }
}

bool Maze::FootPrint(PosType &pos)
{
    if ( (pos.x < x) && (pos.y < y))
    {
        if (maze[pos.x, pos.y].isPass == 1)
        {
            maze[pos.x, pos.y].isThrough = 1;
            return true;
        }
    }
    return false;
}

PosType Maze::NextPos(PosType &pos, int di)
{
    if ( 1 == di )
