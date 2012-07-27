/*
 *       Filename:  test_Sqlist.cpp
 *    Description:  
 *         Author:  jumbal
 *          Email:  the.jumbal@gmail.com
 *        Created:  07/21/12 07:29:29
 */
#include    "Sqlist.h"

int main(int argc, char** argv)
{
    if (argc !=2)
    {
        cerr<<"Usage: ./test listsize"<<endl;
        return ERROR;
    }
    int list_size = atoi(argv[1]);
    Sqlist* list_a = new Sqlist();
    for (int i = 1; i <= list_size; ++i)
    {
        if (ERROR == (list_a->ListInsert_Sq(i, i)))
        {
            cerr<<"Insert error"<<endl;
            return ERROR;
        }
    }
    list_a->Print_elem();
    int listlength = list_a->GetLength();
    for (int i = 1; i < (listlength*2); ++i)
    {
        ElemType temp;
        if (ERROR == (list_a->ListDelete_Sq(i, temp)))
        {
            cerr<<"Delete error"<<endl;
            list_a->Print_elem();
            return ERROR;
        } 
    }
    list_a->Print_elem();

    return SUCCESS;
}
