/*
 * =====================================================================================
 *
 *       Filename:  Sqlist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/20/12 07:12:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    "Sqlist.h"

Sqlist::Sqlist()
{
    elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    cout<<"malloc_size:"<<LIST_INIT_SIZE * sizeof(ElemType)<<endl;
    if (NULL == elem)
    {
        cerr<<"Can't allocate enough memory, program will exit"<<endl;
        exit(0);
    }
    length = 0;
    listsize = LIST_INIT_SIZE;
}

Sqlist::~Sqlist()
{
    free(elem);
}

Status Sqlist::ListInsert_Sq(int elem_loc, ElemType elem_temp)
{
    //insert before elem_loc
    if ((elem_loc < 1) || (elem_loc > length + 1))
    {
        return ERROR;
    }
    if (length >= listsize)
    {
        //ElemType* newbase = (ElemType*)realloc(elem, (listsize + LIST_INCREMENT));
        //when realloc memory, we should think about sizeof(ElemType)
        ElemType* newbase = (ElemType*)realloc(elem, (listsize + LIST_INCREMENT)* sizeof(ElemType));
        cout<<"realloc_size:"<<sizeof(ElemType)*(listsize + LIST_INCREMENT)<<endl;
        if (NULL == newbase)
       {
        cerr<<"Can't allocate enough memory, can't insert."<<endl;
        return ERROR;
       } 
        elem = newbase;
        listsize += LIST_INCREMENT;
    }

    ElemType* q = elem + elem_loc - 1;
    ElemType* p = elem + length;
    for (; p > q; --p) *p = *(p-1);

    *q = elem_temp;
    ++length;
    return SUCCESS;
}

Status Sqlist::ListDelete_Sq(int elem_loc, ElemType& e)
{
    if ((elem_loc < 1) || (elem_loc > length))
    {
        return ERROR; 
    }

    ElemType* p = NULL;
    ElemType* q = NULL;

    p = elem + elem_loc -1;
    e = *p;
    q = elem + length - 1;
    for (; p < q; p++)
    {
        *p = *(p + 1);
    }
    --length;
    return SUCCESS;
}

Status Sqlist::ListGet_Sq(int elem_loc, ElemType& e)
{
    if ((elem_loc < 1) || (elem_loc > length))
    {
        return ERROR;
    }
    
    e = *(elem + elem_loc -1);
    return SUCCESS;
}

Status Sqlist::Print_elem()
{
    for (int i = 0; i < length; ++i)
    {
        cout<<i+1<<":"<<*(elem + i)<<"\t";
    }
    cout<<endl;
    cout<<"Listsize:"<<listsize<<"\tListlength:"<<length<<endl;
    return SUCCESS;
}
