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
#include    "stack.hpp"
#include    <iostream>
#include    <string>
using namespace std;

int main(int argc, char *argv[])
{
    string brackets;
    if (argc == 1)
    {
        brackets = string("[({})]");
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

    cout << "brackets:" << brackets << endl;

    Stack<char> bracket_stack;
    for (string::const_iterator it = brackets.begin(); it != brackets.end(); it++)
    {
        char temp = '#';
        bracket_stack.GetTop(temp);
        switch (*it)
        {
            case '[':
            case '{':
            case '(':
                {
                    bracket_stack.Push(*it);
                    break;
                }
            case ']':
                {
                    if (temp == '[')
                    {
                        bracket_stack.Pop(temp);
                    }
                    else
                    {
                        cerr << "Empty stack with ]" << endl;
                        return -1;
                    }

                    break;
                }
            case '}':
                {
                    if (temp == '{')
                    {
                        bracket_stack.Pop(temp);
                    }
                    else
                    {
                        cerr << "Empty stack with }" << endl;
                        return -1;
                    }

                    break;
                }
            case ')':
                {
                    if (temp == '(')
                    {
                        bracket_stack.Pop(temp);
                    }
                    else
                    {
                        cerr << "Empty stack with )" << endl;
                        return -1;
                    }

                    break;
                }

            default:
                {
                    //Error conditions
                    cerr << "non char" << endl;
                    return -1;
                }
        }
    }
    cout << "Prefect" << endl;

    return 0;
}
