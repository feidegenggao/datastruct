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
#include    "BinaryTree.h"

Status Visit(TElemType );
int main(void)
{
    BinaryTree *btree = new BinaryTree();

    btree->Init();
    cout<<"PreOrderTraverse"<<endl;
    btree->PreOrderTraverse(btree->Root(), Visit);
    cout<<"InOrderTraverse"<<endl;
    btree->InOrderTraverse(btree->Root(), Visit);
    cout<<"PostOrderTraverse"<<endl;
    btree->PostOrderTraverse(btree->Root(), Visit);
    cout<<"LevelOrderTraverse"<<endl;
    btree->LevelOrderTraverse(btree->Root(), Visit);
    cout<<"InOrderTraverse_NON_Recursion"<<endl;
    btree->InOrderTraverse_NON_Recursion(btree->Root(), Visit);
    cout<<"PreOrderTraverse_NON_Recursion"<<endl;
    btree->PreOrderTraverse_NON_Recursion(btree->Root(), Visit);
    cout<<"PostOrderTraverse_NON_Recursion"<<endl;
    btree->PostOrderTraverse_NON_Recursion(btree->Root(), Visit);

    return 0;
}

Status Visit(TElemType e)
{
    cout<<"DATA:"<<e<<endl;

    return SUCCESS;
}
