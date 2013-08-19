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
class MinStack
{
    public:
        Status push(ElementType ele)
        {
            Status result = data_.push(ele);
            if (SUCCESSFUL == result)
            {
                if (min_.size() == 0)
                {
                    min_.push(ele);
                }
                else
                {
                    ElementType min_ele = min_.top();
                    if (ele < min_ele)
                    {
                        min_ele = ele;
                    }
                    min_.push(min_ele);
                }

                return SUCCESSFUL;
            }
            else
            {
                return FAILED;
            }
        }

        ElementType min() const
        {
            assert(min_.size() != 0);

            return min_.top();
        }

        void PrintMinStack() const 
        {
            min_.PrintStack();
        }

    private:
        Stack data_;
        Stack min_;
};

int main()
{
    Stack *pStackA = new Stack();

    for (ElementType ele = 0; ele < 5; ele++)
        pStackA->push(ele);

    pStackA->PrintStack();

    MinStack *pMinStackA = new MinStack();

    for (ElementType ele = 5; ele < 9; ele++)
    {
        pMinStackA->push(ele);
        cout << "pMinStackA's min :" << pMinStackA->min() << endl;
    }

    pMinStackA->push(2);
    pMinStackA->PrintMinStack();

    return SUCCESSFUL;
}
