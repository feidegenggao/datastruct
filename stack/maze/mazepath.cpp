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
#include    "Stack.h"
#include    "my.h"

Status MazePath(Maze&, const PosType&, const PosType&);
int
main()
{
    Maze ma(MAZE_SIZE_X, MAZE_SIZE_Y);
    PosType start(1, 1);
    PosType end(MAZE_SIZE_X - 2, MAZE_SIZE_Y - 2);

    if (SUCCESS == MazePath(ma, start, end))
    {
        cout<<"find the path of maze success"<<endl;
        ma.PrintPath();
    }
    else
    {
        cout<<"can't find the path"<<endl;
        ma.PrintPath();
    }

    return 0;
}

Status MazePath(Maze &maze, const PosType &start, const PosType &end)
{
    PosType curpos = start;
    int curstep = 1;
    Stack s;
    s.Init();

    do{
        if (maze.Pass(curpos))
        {
            maze.FootPrint(curpos);
            Elemtype e(curstep, curpos, 1);
            if ( ERROR == s.Push(e))
            {
                cerr<<"stack push error"<<endl;
                return ERROR;
            }

            if (curpos == end)
            {
                cout<<"sum of step:"<<curstep<<endl;
                return SUCCESS;
            }

            maze.NextPos(curpos, 1);
            curstep++;
        }
        else
        {
            if (ERROR == s.IsEmpty())
            {
                Elemtype e;
                s.Pop(e);

                while( e.di == 4 && (ERROR == s.IsEmpty()))
                {
                    maze.MarkPrint(e.seat);
                    s.Pop(e);
                }
                if (e.di < 4)
                {
                    e.di++;
                    if ( ERROR == s.Push(e))
                    {
                        cerr<<"stack push error"<<endl;
                        return ERROR;
                    }
                    curpos = e.seat;
                    maze.NextPos(curpos, e.di);
                }
            }
        }
    }while(ERROR == s.IsEmpty());

    cout<<"sum of step:"<<curstep<<endl;
    return ERROR;
}
