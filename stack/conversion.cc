/*
 * ============================================================================
 *
 *       Filename:  conversion.cc
 *
 *    Description:  Convert N from decimal to octal  
 *
 *        Version:  1.0
 *        Created:  08/19/13 09:52:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <assert.h>
#include    <stdlib.h>
#include    <iostream>
using namespace std;

#include    "stack.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage:" << argv[0] << " N_decimal dest_system" << endl;
        return -1;
    }
    const int dest_system = atoi(argv[2]);
    assert(dest_system > 0);
    int num_decimal = atoi(argv[1]);
    assert(num_decimal > 0);

    Stack<int> octal_stack;
    while (num_decimal != 0)
    {
        int temp = num_decimal % dest_system;
        octal_stack.Push(temp);
        num_decimal = num_decimal / dest_system;
    }

    cout << "Result:" << endl;
    while (!octal_stack.IsEmpty())
    {
        int temp;
        octal_stack.Pop(temp);
        cout << temp;
    }
    cout << endl;

    return 0;
}
