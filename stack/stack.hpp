#ifndef     _STACK_HEADER
#define     _STACK_HEADER
typedef int Status;

const Status ERROR = 1;
const Status SUCCESS = 0;

const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 10;

template <typename Elemtype>
class Stack
{
    public:
        Stack();
        ~Stack();

    private:
        Status  Init();
    public:
        Status  Clear();
        //false:Non-empyt true:Empty
        bool IsEmpty();
        int     Length() { return m_ElemSize;}
        int     Size()   { return m_StackSize;}
        Status  Push(Elemtype&);
        Status  Pop(Elemtype&);
        Status  Traverse(Status(*vist)(void*));
        Status  GetTop(Elemtype&);

    private:
        Elemtype    *m_pBase;
        Elemtype    *m_pTop;
        int         m_StackSize;
        int         m_ElemSize;
};

#include 	<iostream>
#include    <errno.h>
#include    <string.h>
#include    <strings.h>
using namespace std;

template <typename Elemtype>
Stack<Elemtype>::Stack()
{
    m_pBase = NULL;
    m_pTop  = NULL;
    m_StackSize = 0;
    m_ElemSize  = 0;
    Init();
}

template <typename Elemtype>
Stack<Elemtype>::~Stack()
{
    delete [] m_pBase;
}

template <typename Elemtype>
Status Stack<Elemtype>::Init()
{
    m_pBase = new Elemtype[STACK_INIT_SIZE];
    if (m_pBase == NULL)
    {
        std::cerr<<"new memory error:"<<strerror(errno)<<std::endl;
        return ERROR;
    }

    m_pTop  = m_pBase;
    m_StackSize = STACK_INIT_SIZE;
    m_ElemSize  = 0;

    return SUCCESS;
}

template <typename Elemtype>
Status Stack<Elemtype>::Clear()
{
    m_pTop = m_pBase;
    m_ElemSize = 0;
    return SUCCESS;
}

template <typename Elemtype>
bool Stack<Elemtype>::IsEmpty()
{
    if (m_pBase == m_pTop)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Elemtype>
Status Stack<Elemtype>::Push(Elemtype &elm)
{
    if (m_pBase == NULL)
    {
        std::cerr<<"Stack NULL"<<std::endl;
        return ERROR;
    }
    else if (m_StackSize == m_ElemSize)
    {
        std::cerr<<"Stack overflow"<<std::endl;
        return ERROR;
    }
    else
    {
        *m_pTop = elm;
        m_pTop++;
        m_ElemSize++;

        return SUCCESS;
    }
}

template <typename Elemtype>
Status Stack<Elemtype>::Pop(Elemtype &elm)
{
    if (m_pBase == NULL)
    {
        std::cerr<<"Stack NULL"<<std::endl;
        return ERROR;
    }
    else if (m_pBase == m_pTop)
    {
        std::cerr<<"Stack empty"<<std::endl;
        return ERROR;
    }
    else
    {
        m_pTop--;
        elm = *m_pTop;
        m_ElemSize--;

        return SUCCESS;
    }
}

template <typename Elemtype>
Status Stack<Elemtype>::Traverse(Status(*visist)(void*))
{
    Elemtype *temp = m_pBase;
    for(int i = 0; i < m_ElemSize; ++i)
    {
        if ( ERROR == visist(temp))
        {
            std::cerr<<"i:"<<i<<"\tvisist() error"<<std::endl;
            return ERROR;
        }
        temp++;
    }

    return SUCCESS;
}

template <typename Elemtype>
Status Stack<Elemtype>::GetTop(Elemtype &elem)
{
    Elemtype temp;
    if (SUCCESS == Pop(temp))
    {
        Push(temp);
        elem = temp;
        return SUCCESS;
    }

    return ERROR;
}


#endif
