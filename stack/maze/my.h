/*
 * ============================================================================
 *
 *       Filename:  my.h
 *
 *    Description:  header file of defination fo struct
 *
 *        Version:  1.0
 *        Created:  08/14/12 09:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * ============================================================================
 */
#ifndef     _MAZE_MY_HEADER
#define     _MAZE_MY_HEADER
#include 	<iostream>
#include    <errno.h>
#include    <string.h>
using namespace std;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

typedef int Status;
const Status ERROR = 1;
const Status SUCCESS = 0;

struct PosType{
    int x;
    int y;

    PosType()
    {
        x = 0;
        y = 0;
    }

    PosType(int a, int b)
    {
        x = a;
        y = b;
    }

    int operator =(const PosType &s)
    {
        x = s.x;
        y = s.y;
    }

    bool operator ==(const PosType &s)
    {
        if ( (x == s.x)&&(y == s.y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

struct Elemtype{
    int ord;
    PosType seat;
    int di;

    Elemtype()
    {
        ord = 0;
        //seat(0, 0) : error:no no match for call to '(PosType) (int, int)'
        seat.x = 0;
        seat.y = 0;
        di = 0;
    }

    Elemtype(int order, PosType st, int diraction)
    {
        ord = order;
        seat = st;
        di = diraction;
    }
};

const int CAN_PASS = 1;
const int NOT_PASS = 0;
const int IS_THROUGH = 1;
const int NOT_THROUGH = 0;
struct Point{
    //1, can pass
    //0, can't pass
    int isPass;
    //1, is go through
    //0, isn't go through
    int isThrough;
};

#endif
