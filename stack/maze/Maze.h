/*
 * =====================================================================================
 *
 *       Filename:  Maze.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/12 20:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * =====================================================================================
 */
#ifndef     _MAZE_HEADER
#define     _MAZE_HEADER
#include    "Stack.h"
#include    "my.h"
#include    <vector>
using std::vector;

const int   MAZE_SIZE_X = 10;
const int   MAZE_SIZE_Y = 10;

class Maze{
    public:
        Maze(int x, int y);
        ~Maze();

        int     init();
        bool    Pass(PosType&);
        bool    FootPrint(PosType&);
        Status  NextPos(PosType& curpos, int dir);
        bool    MarkPrint(PosType&);

        int     PrintPath();

    private:
        vector<vector<Point> > maze;
        int x;
        int y;
};
#endif
