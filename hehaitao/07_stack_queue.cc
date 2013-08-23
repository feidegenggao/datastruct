/*
 * ============================================================================
 *
 *       Filename:  07_stack_queue.cc
 *
 *    Description:  two stack to finish the queue
 *
 *        Version:  1.0
 *        Created:  08/21/13 14:45:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <stack>
using namespace std;

template <typename Type>
class Queue
{
    public:
        void Enqueue(Type ele)
        {
            in_stack.push(ele);
        }

        int Dequeue(Type &ele)
        {
            if (out_stack.empty())
            {
                while (!in_stack.empty())
                {
                    out_stack.push(in_stack.top());
                    in_stack.pop();
                }
            }

            if (out_stack.empty())
            {
                cout << "Queue is empty" << endl;
                return -1;
            }
            else
            {
                ele = out_stack.top();
                out_stack.pop();
                return 0;
            }
        }

    private:
        stack<Type> in_stack;
        stack<Type> out_stack;
};

int main()
{
    Queue<int> queue_first;
    queue_first.Enqueue(1);
    queue_first.Enqueue(2);

    int temp;
    queue_first.Dequeue(temp);
    cout << "temp:" << temp << endl;
    queue_first.Dequeue(temp);
    cout << "temp:" << temp << endl;
    queue_first.Dequeue(temp);
    cout << "temp:" << temp << endl;
    queue_first.Dequeue(temp);
    cout << "temp:" << temp << endl;

    return 0;
}


