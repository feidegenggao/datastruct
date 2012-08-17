/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  test binarytree
 *
 *        Version:  1.0
 *        Created:  08/16/12 23:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333 at gmail dot com
 *   Organization:  NDSL UESTC
 *
 * ============================================================================
 */
#include    "binarytree.h"

Status Visit(TElemType );
int main(void)
{
    BinaryTree *btree = new BinaryTree();

    btree->Init();
    btree->PreOrderTraverse(btree->Root(), Visit);

    return 0;
}

Status Visit(TElemType e)
{
    cout<<"DATA:"<<e<<endl;

    return SUCCESS;
}
