/*
 * ============================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/13 15:33:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#ifndef     STACK_HEADER
#define     STACK_HEADER
#include    <iostream>
#include    <strings.h>
using std::cout;
using std::endl;
using std::cerr;

typedef int ElementType;
typedef unsigned int ElementSize;

typedef int Status;
const int SUCCESSFUL = 0;
const int FAILED = -1;

class Stack
{
    public:
        Stack()
        {
            len_ = MAXLEN;
            pbase_ = new ElementType[len_];
            bzero(pbase_, len_);
            pbase_--;

            ptop_ = pbase_;
        }

        ~Stack()
        {
            delete [] pbase_;
        }

        Status push(ElementType element)
        {
            if (size() == MAXLEN)
            {
                return FAILED;
            }

            //put into stack
            ptop_++;
            *ptop_ = element;

            cout << "push " << element << endl;
            return SUCCESSFUL;
        }

        ElementType pop()
        {
            if (ptop_ == pbase_)
            {
                return FAILED;
            }

            ElementType element = *ptop_--;
            cout << "pop " << element << endl;
            return element;
        }

        void PrintStack() const 
        {
            ElementType *pelement = ptop_;
            while (pelement != pbase_)
            {
                cout << "element:" << *pelement << endl;
                pelement--;
            }
        }

    private:
        ElementSize size() { return (ptop_ - pbase_);}

        ElementType *pbase_;
        ElementType *ptop_;
        ElementSize len_;
        const static ElementSize MAXLEN = 10;
};
#endif
