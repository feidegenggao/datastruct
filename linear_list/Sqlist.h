/*
 * =====================================================================================
 *
 *       Filename:  Sqlist.h
 *
 *    Description:  defination of Sqlist stored in squeces
 *
 *        Version:  1.0
 *        Created:  07/20/12 07:08:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
#include    <stdlib.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

typedef int ElemType;
typedef int Status;

const Status ERROR = 1;
const Status SUCCESS = 0;

const int LIST_INIT_SIZE = 100;
const int LIST_INCREMENT = 10;
const int ELEMSIZE = sizeof(ElemType);

class Sqlist
{
    public:
        Sqlist();
        ~Sqlist();
        Status ListInsert_Sq(int, ElemType);
        Status ListDelete_Sq(int, ElemType&);
        Status ListGet_Sq(int, ElemType&);
        Status Print_elem();
        inline int GetLength() { return length;}
        inline int GetSize() { return listsize;}

    private:
        ElemType *elem;
        int length;
        int listsize;
};
