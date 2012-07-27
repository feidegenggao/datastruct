/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  defination of linear list
 *
 *        Version:  1.0
 *        Created:  07/19/12 06:43:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

typedef int ListDatatype;
struct Element
{
    Elemtype* Prior;
    Elemtype* Next;
    ListDatatype data;
};
typedef struct Elemtype Elemtype;

class linear_list
{
    public:
        linear_list();
        init();
        ~linear_list();

        int ClearList();
        int ListEmpty();
        int ListLength();
        int GetElem(i, &Elemtype);
        int LocateElem(Elemtype, compare());
        int PriorElem(Elemtype, &Elemtype);
        int NextElem(Elemtype, &Elemtype);
        int ListInsert(int, Elemtype);
        int ListDelete(i, &Elemtype);
        int ListTraverse(vist());

    private:
        int list_length;
        Elemtype header;
};
