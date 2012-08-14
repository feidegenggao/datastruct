/*
 * ============================================================================
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
 * ============================================================================
 */
#include   "Maze.h"

Maze::Maze(int line, int row)
{
    x = line;
    y = row;

    Point potinit;
    potinit.isPass = 0;
    potinit.isThrough = 0;

    //y row 
    vector<Point> potx(y, potinit);

    for (int i = 0; i < x; i++)
    {
        maze.push_back(potx);
    }

/*
    maze[1][1].isPass = 1;
    maze[1][3].isPass = 1;

    maze[2][1].isPass = 1;
    maze[2][2].isPass = 1;
    maze[2][3].isPass = 1;
    maze[2][4].isPass = 1;

    maze[3][1].isPass = 1;
    maze[3][3].isPass = 1;

    //maze[4][3].isPass = 1;
    maze[4][4].isPass = 1;
*/
    maze[1][1].isPass = 1;
    maze[1][2].isPass = 1;
    maze[1][4].isPass = 1;
    maze[1][5].isPass = 1;
    maze[1][6].isPass = 1;
    maze[1][8].isPass = 1;


    maze[2][1].isPass = 1;
    maze[2][2].isPass = 1;
    maze[2][4].isPass = 1;
    maze[2][5].isPass = 1;
    maze[2][6].isPass = 1;
    maze[2][8].isPass = 1;

    maze[3][1].isPass = 1;
    maze[3][2].isPass = 1;
    maze[3][3].isPass = 1;
    maze[3][4].isPass = 1;
    maze[3][7].isPass = 1;
    maze[3][8].isPass = 1;


    maze[4][1].isPass = 1;
    maze[4][5].isPass = 1;
    maze[4][6].isPass = 1;
    maze[4][7].isPass = 1;
    maze[4][8].isPass = 1;

    maze[5][1].isPass = 1;
    maze[5][2].isPass = 1;
    maze[5][3].isPass = 1;
    maze[5][5].isPass = 1;
    maze[5][6].isPass = 1;
    maze[5][7].isPass = 1;
    maze[5][8].isPass = 1;

    maze[6][1].isPass = 1;
    maze[6][3].isPass = 1;
    maze[6][4].isPass = 1;
    maze[6][5].isPass = 1;
    maze[6][7].isPass = 1;
    maze[6][8].isPass = 1;

    maze[7][1].isPass = 1;
    maze[7][8].isPass = 1;
    maze[7][5].isPass = 1;

    maze[8][2].isPass = 1;
    maze[8][3].isPass = 1;
    maze[8][4].isPass = 1;
    maze[8][5].isPass = 1;
    maze[8][6].isPass = 1;
    maze[8][7].isPass = 1;
    maze[8][8].isPass = 1;

    cout<<"Maze Map,"<<x<<" line"<<y<<" row"<<endl;
    for (int i = 0; i < x; i++)
    {
        for (int j =0; j < y; j++)
        {
            if (maze[i][j].isPass == 0)
            //if ( (i==0) || (j==0) || (i==(x-1)) ||(j == y-1))
            {
                cout<<"0 ";
            }
            else
            {
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
    cout<<"***************"<<endl;
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
    //如果一个位置可以经过，则需满足位置可以通过，且没有走过。
    if ( (pos.x < x) && (pos.y < y))
    {
        if (maze[pos.x][pos.y].isPass == 1)
        {
            if (maze[pos.x][pos.y].isThrough == 0)
            {
                return true;
            }
        }
    }
        
    return false;
}

bool Maze::FootPrint(PosType &pos)
{
    if ( (pos.x < x) && (pos.y < y))
    {
        if (maze[pos.x][pos.y].isPass == 1)
        {
            maze[pos.x][pos.y].isThrough = 1;
            return true;
        }
    }
    return false;
}

Status Maze::NextPos(PosType &pos, int di)
{
    if ( 1 == di )
    {
        pos.y++;
    }
    else if (2 == di)
    {
        pos.x++;
    }
    else if (3 == di)
    {
        pos.y--;
    }
    else if (4 == di)
    {
        pos.x--;
    }

    return SUCCESS;
}
bool Maze::MarkPrint(PosType &pos)
{
    if ( (pos.x < x) && (pos.y < y))
    {
        maze[pos.x][pos.y].isPass = 0;

        return true;
    }
    return false;
}

int Maze::PrintPath()
{
    for (int i = 0; i < x; i++)
    {
        for (int j =0; j < y; j++)
        {
            if (maze[i][j].isThrough == 1)
            {
                cout<<"* ";
            }
            else if (maze[i][j].isPass == 1)
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<"***************"<<endl;
}
