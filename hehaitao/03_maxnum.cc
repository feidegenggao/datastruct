/*
 * ============================================================================
 *
 *       Filename:  03_maxnum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/13 20:49:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <assert.h>
#include    <iostream>
using namespace std;

bool FindMax(int array[][4], int rows, int colums, int dstnum)
{
    for (int i = 0; i != rows; i++)
        for (int j = 0; j != colums; j++)
            cout << "ele:" << array[i][j] << endl;

    assert( (array != NULL) and (rows > 0) and (colums > 0) );
    int row = rows - 1;
    int colum = 0;

    while ( row >= 0 and colum <= colums)
    {
        if (array[row][colum] == dstnum)
        {
            return true;
        }
        else if (array[row][colum] > dstnum)
        {
            row--;
        }
        else if (array[row][colum] < dstnum)
        {
            colum++;
        }
    }
    return false;
}

int main()
{
    int array[2][4] = { {1,2,3,9}, {2,4,9,12}};
    if (FindMax(array, 2, 4, 8))
    {
        cout << "Find it" << endl;
    }
    return 0;
}
