#include    "stack.h"
#include    <iostream>
using namespace std;

void conversion(int temp);

int main()
{
    Stack<int> *sa = new Stack<int>();

    int itemp = 2;
    sa->Push(itemp);
    itemp = 4;
    sa->Push(itemp);

    while (!sa->IsEmpty())
    {
        if (SUCCESS == (sa->Pop(itemp)))
        {
            cout<<"pop:"<<itemp<<endl;
        }
    }

    conversion(1384);
    conversion(1348);

    return SUCCESS;
}

void conversion(int temp)
{
    Stack<int> *sb = new Stack<int>();
    int itemp;

    while(temp)
    {
        int midle = temp%8;
        sb->Push(midle);
        cout<<"PUSH:"<<midle<<endl;
        temp = temp/8;
    }

    cout<<temp<<"Result-->>";
    while (!sb->IsEmpty())
    {
        if (SUCCESS == (sb->Pop(itemp)))
        {
            cout<<itemp;
        }
    }
    cout<<endl;
}
