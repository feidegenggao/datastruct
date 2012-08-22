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
#include    "BinaryTree.h"

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
    if (root)
    {
        if (SUCCESS == Visit(root->data))
            if (SUCCESS == PreOrderTraverse(root->lchild, Visit))
                if (SUCCESS == PreOrderTraverse(root->rchild, Visit))
                    return SUCCESS;
        return ERROR;
    }
    else
        return SUCCESS;
}

Status BinaryTree::InOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
    if (root)
    {
        if (SUCCESS == InOrderTraverse(root->lchild, Visit))
            if (SUCCESS == Visit(root->data))
                if (SUCCESS == InOrderTraverse(root->rchild, Visit))
                    return SUCCESS;

        return ERROR;
    }
    else
        return SUCCESS;
}

Status BinaryTree::PostOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
    if (root)
    {
        if (SUCCESS == InOrderTraverse(root->lchild, Visit))
            if (SUCCESS == InOrderTraverse(root->rchild, Visit))
                if (SUCCESS == Visit(root->data))
                    return SUCCESS;

        return ERROR;
    }
    else
        return SUCCESS;
}

Status BinaryTree::LevelOrderTraverse(BiTree root, Status(*Visit)(TElemType))
{
    queue<BiTree> nodeQueue;

    nodeQueue.push(root);
    int levelsize = 1;
    while(!nodeQueue.empty())
    {
        int this_levelsize = 0;
        for (int i = 0; i < levelsize; ++i)
        {
            if (nodeQueue.front()->lchild)
            {
                nodeQueue.push(nodeQueue.front()->lchild);
                ++this_levelsize;
            }
            if (nodeQueue.front()->rchild)
            {
                nodeQueue.push(nodeQueue.front()->rchild);
                ++this_levelsize;
            }
            Visit(nodeQueue.front()->data);
            nodeQueue.pop();
        }
        levelsize = this_levelsize;
    }
}

Status BinaryTree::PreOrderTraverse_NON_Recursion(
       BiTree root,
       Status(*Visit)(TElemType))
{
    Stack sBiTree;
    sBiTree.Init();

    sBiTree.Push(root);

    while(ERROR == sBiTree.IsEmpty())
    {
        BiTree temp = NULL;
        while ((SUCCESS == sBiTree.GetTop(temp)) && temp)
        {
            if (ERROR == Visit(temp->data))
                return ERROR;
            sBiTree.Push(temp->lchild);
        }

        sBiTree.Pop(temp);

        if (ERROR == sBiTree.IsEmpty())
        {
            sBiTree.Pop(temp);
            sBiTree.Push(temp->rchild);
        }
    }
} 

Status BinaryTree::InOrderTraverse_NON_Recursion(
        BiTree root, 
        Status(*Visit)(TElemType))
{
    Stack sBiTree;
    sBiTree.Init();

    sBiTree.Push(root);

    while(ERROR == sBiTree.IsEmpty())
    {
        BiTree temp = NULL;
        while((SUCCESS == sBiTree.GetTop(temp)) && temp)
        {
            sBiTree.Push(temp->lchild);
        }
        sBiTree.Pop(temp);

        if (ERROR == sBiTree.IsEmpty())
        {
            sBiTree.Pop(temp);
            if (ERROR == Visit(temp->data))
            {
                return ERROR;
            }
            sBiTree.Push(temp->rchild);
        }
    }

    return SUCCESS;
}

Status BinaryTree::PostOrderTraverse_NON_Recursion(
        BiTree root_argu,
        Status(*Visit)(TElemType))
{
    BiTree root = root_argu;
    Stack sBiTree;
    sBiTree.Init();

    while (root || (ERROR == sBiTree.IsEmpty()))
    {
        while (root)
        {
            sBiTree.Push(root);
            root = root->lchild;
        }

        if (ERROR == sBiTree.IsEmpty())
        {
            sBiTree.GetTop(root);
            if (root->flag)
            {
                if (ERROR == Visit(root->data))
                    return ERROR;
                sBiTree.Pop(root);
                root = NULL;
            }
            else
            {
                root->flag = true;
                root = root->rchild;
            }
        }
    }
}
/*
Status BinaryTree::PostOrderTraverse_NON_Recursion(
        BiTree root,
        Status(*Visit)(TElemType))
{
    Stack sBiTree;
    sBiTree.Init();
    sBiTree.Push(root);

    while (ERROR == sBiTree.IsEmpty())
    {
        BiTree temp = NULL;
        while((SUCCESS == sBiTree.GetTop(temp) && temp))
        {
            if ((temp->lchild)&&(!(temp->lchild->flag)))
                temp->lchild->flag = true;
            sBiTree.Push(temp->lchild);
        }
        sBiTree.Pop(temp);
        if (ERROR == sBiTree.IsEmpty())
        {
            if (SUCCESS == sBiTree.GetTop(temp))
            {
                if (temp->flag)
                {
                    sBiTree.Pop(temp);
                    if (ERROR == Visit(temp->data))
                    {
                        return ERROR;
                    }
                    temp->flag = false;
                }
                else
                {
                    temp->flag = true;
                }
                if ((temp->rchild) &&(!(temp->rchild->flag)))
                    temp->rchild->flag = true;
                sBiTree.Push(temp->rchild);
            }
        }
    }

    return SUCCESS;
}
*/