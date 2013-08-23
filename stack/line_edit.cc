/*
 * ============================================================================
 *
 *       Filename:  line_edit.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/13 15:19:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <string>
#include    <iostream>
using namespace std;

#include    "stack.hpp"

int main(int argc, char *argv[])
{
    string line_buf;
    if (argc == 1)
    {
        line_buf = string("whli##ilr#e(s#*s)");
    }
    else if (argc == 2)
    {
        line_buf = string(argv[1]);
    }
    else
    {
        cerr << "Usage:" << argv[0] << " [line_buf] " << endl;
        return -1;
    }

    Stack<char> line_stack;
    for (string::const_iterator it = line_buf.begin(); it != line_buf.end(); ++it)
    {
        switch (*it)
        {
            char temp;
            case '#':
                {
                    line_stack.Pop(temp);
                    break;
                }
            case '@':
                {
                    line_stack.Clear();
                    break;
                }
            default:
                {
                    line_stack.Push(*it);
                    break;
                }
        }
    }

    Stack<char> line_temp;
    while (line_stack.Length() != 0)
    {
        char temp;
        line_stack.Pop(temp);
        line_temp.Push(temp);
    }

    cout << "This line is :" ;
    while (line_temp.Length() != 0)
    {
        char temp;
        line_temp.Pop(temp);
        cout << temp;
    }

    cout << endl;

    return 0;
}
