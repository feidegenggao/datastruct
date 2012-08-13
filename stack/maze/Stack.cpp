#include    "Stack.h"

Stack::Stack()
{
    m_pBase = NULL;
    m_pTop  = NULL;
    m_StackSize = 0;
    m_ElemSize  = 0;
}

Stack::~Stack()
{
    delete [] m_pBase;
}

Status Stack::Init()
{
    m_pBase = new Elemtype[STACK_INIT_SIZE];
    if (m_pBase == NULL)
    {
        cerr<<"new memory error:"<<strerror(errno)<<endl;
        return ERROR;
    }

    m_pTop  = m_pBase;
    m_StackSize = STACK_INIT_SIZE;
    m_ElemSize  = 0;

    return SUCCESS;
}

Status Stack::ClearStack()
{
    m_pTop = m_pBase;
    m_ElemSize = 0;
    return SUCCESS;
}

Status Stack::IsEmpty()
{
    if (m_pBase == m_pTop)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}


Status Stack::Push(Elemtype &elm)
{
    if (m_pBase == NULL)
    {
        cerr<<"Stack NULL"<<endl;
        return ERROR;
    }
    else if (m_StackSize == m_ElemSize)
    {
        cerr<<"Stack overflow"<<endl;
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

Status Stack::Pop(Elemtype &elm)
{
    if (m_pBase == NULL)
    {
        cerr<<"Stack NULL"<<endl;
        return ERROR;
    }
    else if (m_pBase == m_pTop)
    {
        cerr<<"Stack empty"<<endl;
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

Status Stack::Traverse(Status(*visist)(void*))
{
    Elemtype *temp = m_pBase;
    for(int i = 0; i < m_ElemSize; ++i)
    {
        if ( ERROR == visist(temp))
        {
            cerr<<"i:"<<i<<"\tvisist() error"<<endl;
            return ERROR;
        }
        temp++;
    }

    return SUCCESS;
}
