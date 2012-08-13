/*
 * =====================================================================================
 *
 *       Filename:  mazepath.cpp
 *
 *    Description:  finde the path of maze
 *
 *        Version:  1.0
 *        Created:  08/12/12 21:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * =====================================================================================
 */
#include    "Maze.h"
#inlcude    "Stack.h"

Status MazePath(Maze&, PosType&, PosType&);
int
main()
{
    Maze *ma = new Maze(6, 6);
    PosType start(1, 1);
    PosType end(4, 4);

    return 0;
}
