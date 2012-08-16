/*
 * ============================================================================
 *
 *       Filename:  binarytree.cpp
 *
 *    Description:  defination of binarytree
 *
 *        Version:  1.0
 *        Created:  08/16/12 22:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333 at gmail dot com
 *   Organization:  NDSL UESTC
 *
 * ============================================================================
 */
#include    "binarytree.h"

BinaryTree::BinaryTree()
{
    root = NULL;
    depth = 0;
    nodesum = 0;
}

BinaryTree::~BinaryTree()
{
    delete [] root;
}

Status BinaryTree::Init()
{
    root = new BiTNode();
    bzero(root, sizeof(BiTNode));
    depth = 0;
    nodesum = 0;

    CreateBiTree(root);

    return SUCCESS;
}

Status BinaryTree::CreateBiTree(BiTree root)
{
    TElemType data;

    cin>>data;
    if (-1 == data)
    {
        root = NULL;
    }
    else
    {
        BiTree root = new BiTNode();
        root->data = data;
        nodesum++;
        CreateBiTree(root->lchild);
        CreateBiTree(root->rchild);
    }
}

Status BinaryTree::ClearBiTree()
{
}

bool BinaryTree::BiTreeEmpty()
{
    if (NULL == root)
    {
        return true;
    }
    else
    {
        return false;
    }
}
