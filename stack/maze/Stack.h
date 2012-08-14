#ifndef     _STACK_HEADER
#define     _STACK_HEADER
#include    "Maze.h"
#include    "my.h"
const int STACK_INIT_SIZE = 100;

class Stack
{
    public:
        Stack();
        ~Stack();

        Status  Init();
        Status  ClearStack();
        //ERROR:Non-empyt SUCCESS:Empty
        Status  IsEmpty();
        int     GetLength() { return m_ElemSize;}
        int     GetSize()   { return m_StackSize;}
        Status  Push(Elemtype&);
        Status  Pop(Elemtype&);
        Status  Traverse(Status(*vist)(void*));

        private:
        Elemtype    *m_pBase;
        Elemtype    *m_pTop;
        int         m_StackSize;
        int         m_ElemSize;
};
#endif
