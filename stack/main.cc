#include    "my.h"
#include    "Stack.h"

typedef int Elemtype;
void conversion(int temp);

int
main()
{
    Stack *sa = new Stack();
    sa->Init();

    Elemtype itemp = 2;
    sa->Push(itemp);
    itemp = 4;
    sa->Push(itemp);

    while (ERROR == sa->IsEmpty())
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

void conversion(Elemtype temp)
{
    Stack *sb = new Stack();
    Elemtype itemp;
    sb->Init();

    while(temp)
    {
        Elemtype midle = temp%8;
        sb->Push(midle);
        cout<<"PUSH:"<<midle<<endl;
        temp = temp/8;
    }

    cout<<temp<<"Result-->>";
    while (ERROR == sb->IsEmpty())
    {
        if (SUCCESS == (sb->Pop(itemp)))
        {
            cout<<itemp;
        }
    }
    cout<<endl;
}
