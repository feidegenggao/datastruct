/*
 * ============================================================================
 *
 *       Filename:  2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/13 15:33:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "stack.h"

int main()
{
    Stack *pStackA = new Stack();

    for (ElementType ele = 0; ele < 5; ele++)
        pStackA->push(ele);

    pStackA->PrintStack();

    while (pStackA->pop() != FAILED)
        ;

    return SUCCESSFUL;
}
