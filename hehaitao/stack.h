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
#include    <assert.h>
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
            assert(size() != MAXLEN);
            
            //put into stack
            ptop_++;
            *ptop_ = element;

            return SUCCESSFUL;
        }

        ElementType top() const
        {
            assert(size() != 0);
            return *ptop_;
        }

        ElementType top()
        {
            assert(size() != 0);
            return *ptop_;
        }

        ElementType pop()
        {
            assert(size() > 0);

            ElementType element = *ptop_--;
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

        ElementSize size() const { return (ptop_ - pbase_);}

    private:
        ElementType *pbase_;
        ElementType *ptop_;
        ElementSize len_;
        const static ElementSize MAXLEN = 10;
};
#endif
