/*
 * ============================================================================
 *
 *       Filename:  08_min.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/13 15:40:00
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

int FindMinLocation(int numbers[], int length)
{
    int min = numbers[0];
    for (int i = 1; i < length; ++i)
    {
        if ( numbers[i] < min)
            min = numbers[i];
    }

    return min;
}

int Min(int numbers[], int length)
{
    assert(numbers != NULL and length > 0);
    int begin = 0;
    int end = length - 1;
    int mid = begin;

    while (numbers[begin] >= numbers[end])
    {
        if ( (end - begin) == 1)
        {
            mid = end;
            break;
        }

        mid = (begin + end) / 2;

        if (numbers[begin] == numbers[mid] and numbers[mid] == numbers[end])
            return FindMinLocation(numbers, length);

        if (numbers[begin] <= numbers[mid])
        {
            begin = mid;
        }
        else if (numbers[mid] <= numbers[end])
        {
            end = mid;
        }
    }

    return numbers[mid];
}

int main()
{
    int numbers[5] = {1,0,0,1,1};
    cout << "Min:" << Min(numbers, 5) << endl;

    return 0;
}
