/*
 * ============================================================================
 *
 *       Filename:  07_queue_stack.cc
 *
 *    Description:  Use queue to finish stack
 *
 *        Version:  1.0
 *        Created:  08/21/13 15:02:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <assert.h>
#include    <iostream>
#include    <queue>
using namespace std;

template <typename Type>
class Stack
{
    public:
        int Pop(Type &ele)
        {
            assert(first_queue.empty() or second_queue.empty());

            if (first_queue.empty() and second_queue.empty())
            {
                cerr << "Stack is empty" << endl;
                return -1;
            }

            queue<Type> &no_empty_queue = FindNoEmpty();
            ele = no_empty_queue.front();
            no_empty_queue.pop();
            return 0;
        }

        void Push(Type ele)
        {
            assert(first_queue.empty() or second_queue.empty());

            queue<Type> &no_empty_queue = FindNoEmpty();
            queue<Type> &empty_queue = FindEmpty();

            empty_queue.push(ele);
            while(!no_empty_queue.empty())
            {
                empty_queue.push(no_empty_queue.front());
                no_empty_queue.pop();
            }
        }

    private:
        queue<Type> first_queue;
        queue<Type> second_queue;
        queue<Type> & FindNoEmpty()
        { 
            assert(first_queue.empty() or second_queue.empty());
            if (!first_queue.empty()) return first_queue;
            if (!second_queue.empty()) return second_queue;
        }

        queue<Type> & FindEmpty()
        {
            assert(first_queue.empty() or second_queue.empty());
            if (first_queue.empty()) return first_queue;
            if (second_queue.empty()) return second_queue;
        }
};

int main()
{
    Stack<int> first_stack;
    first_stack.Push(1);
    first_stack.Push(2);

    int temp = 0;
    first_stack.Pop(temp);
    cout << "temp:" << temp << endl;

    first_stack.Pop(temp);
    cout << "temp:" << temp << endl;

    first_stack.Push(3);
    first_stack.Pop(temp);
    cout << "temp:" << temp << endl;

    first_stack.Pop(temp);
    cout << "temp:" << temp << endl;

    return 0;
}
