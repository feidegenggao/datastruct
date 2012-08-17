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
    m_root = NULL;
    m_depth = 0;
    m_nodesum = 0;
}

BinaryTree::~BinaryTree()
{
    cout<<"destructor of BinaryTree"<<endl;
    delete [] m_root;
}

Status BinaryTree::Init()
{
    m_depth = 0;
    m_nodesum = 0;

    CreateBiTree(m_root);

    return SUCCESS;
}

//这个地方参数是引用类型，会改变实参的值的。
Status BinaryTree::CreateBiTree(BiTree &root)
{
    //Preorder traverse to create BiTree 
    TElemType data;

    cin>>data;
    if (-1 == data)
    {
        root = NULL;
        return SUCCESS;
    }
    else
    {
        root = new BiTNode();
        root->data = data;
        m_nodesum++;
        CreateBiTree(root->lchild);
        CreateBiTree(root->rchild);
    }
}

Status BinaryTree::ClearBiTree()
{
}

bool BinaryTree::BiTreeEmpty()
{
    if (NULL == m_root)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Status BinaryTree::PreOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
    if (NULL == root)
    {
        return SUCCESS;
    }
    else
    {
        if (ERROR == Visit(root->data))
        {
            return ERROR;
        }
        else
        {
        //    if (SUCCESS == PreOrderTraverse(root->lchild, Visit))
        //        if (SUCCESS == PreOrderTraverse(root->rchild, Visit))
        //            return SUCCESS;

            PreOrderTraverse(root->lchild, Visit);
            PreOrderTraverse(root->rchild, Visit);
        }
    }
}

Status BinaryTree::InOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
}

Status BinaryTree::PostOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
}

Status BinaryTree::LevelOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
}
