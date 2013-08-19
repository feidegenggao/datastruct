/*
 * ============================================================================
 *
 *       Filename:  check_bracket.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/13 10:13:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "stack.h"
#include    <iostream>
#include    <string>
using namespace std;

int main(int argc, char *argv[])
{
    string brackets;
    if (argc == 1)
    {
        brackets = string("[({}))]");
    }
    else if (argc == 2)
    {
        brackets = string(argv[1]);
    }
    else
    {
        cerr << "Usage: " << argv[0] << " [brackets] " << endl;
        return -1;
    }

    Stack bracket_stack;
    for (

    return 0;
}
