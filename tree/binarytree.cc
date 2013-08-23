/*
 * ============================================================================
 *
 *       Filename:  binarytree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/13 16:06:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "binarytree.h"
#include    <iostream>
#include    <stack>
using namespace std;
void PreOrderTraversalRecursive(Node *root, void (*visit)(int*))
{
    if (root == NULL) return;
    visit(&(root->data));
    PreOrderTraversalRecursive(root->pleft, visit);
    PreOrderTraversalRecursive(root->pright, visit);
}

void InOrderTraversalRecursive(Node *root, void (*visit)(int*))
{
    if (root == NULL) return;
    InOrderTraversalRecursive(root->pleft, visit);
    visit(&(root->data));
    InOrderTraversalRecursive(root->pright, visit);
}

void PostOrderTraversalRecursive(Node *root, void (*visit)(int*))
{
    if (root == NULL) return;
    PostOrderTraversalRecursive(root->pleft, visit);
    PostOrderTraversalRecursive(root->pright, visit);
    visit(&(root->data));
}

void PreOrderTraversalNonRecursive(Node *root, void (*visit)(int*))
{
    cout << "PreOrderTraversalNonRecursive:" << endl;
    stack<Node*> tree_stack;
    while(root != NULL or !tree_stack.empty())
    {
        while(root != NULL)
        {
            visit(&(root->data));
            tree_stack.push(root);
            root = root->pleft;
        }

        if (!tree_stack.empty())
        {
            root = tree_stack.top();
            tree_stack.pop();
            root = root->pright;
        }
    }
}

void InOrderTraversalNonRecursive(Node *root, void (*visit)(int*))
{
    cout  << "InOrderTraversalNonRecursive:" << endl;
    stack<Node*> tree_stack;
    while(root != NULL or !tree_stack.empty())
    {
        while (root != NULL)
        {
            tree_stack.push(root);
            root = root->pleft;
        }

        if (!tree_stack.empty())
        {
            root = tree_stack.top();
            visit(&(root->data));
            tree_stack.pop();
            root = root->pright;
        }
    }
}

struct stack_element
    {
        stack_element(Node *root, bool flag_):pnode(root),flag(flag_){}
        Node* pnode;
        //flag(false): not finish travel this node's right child
        //flag(true): finish travel this node's right child
        bool flag;
    };


void PostOrderTraversalNonRecursive(Node *root, void (*visit)(int*))
{
    cout << "PostOrderTraversalNonRecursive:" << endl;
    

    stack<stack_element> tree_stack;
    while (root!= NULL or !tree_stack.empty())
    {
        while (root != NULL)
        {
            stack_element temp(root, false);
            tree_stack.push(temp);
            root = root->pleft;
        }

        while (!tree_stack.empty() and tree_stack.top().flag)
        {
            visit(&(tree_stack.top().pnode->data));
            tree_stack.pop();
        }
 
        if (!tree_stack.empty())
        {
            tree_stack.top().flag = true;
            root = tree_stack.top().pnode->pright;
        }
    }
}

#include    <queue>
void LevelOrderTraversal(Node *root, void (*visit)(int*))
{
    cout << "LevelOrderTraversal:" << endl;
   if (NULL == root or NULL == visit) return; 

   queue<Node*> level_queue;
   queue<Node*> next_level_queue;
   level_queue.push(root);

   //flag:true(this level has elements
   //flag:false(this level has no elements, and we can return
   //bool flag = true;
   int level = 1;
   while (!level_queue.empty())
   {
       //clear next_level_queue to prepare to store data
       while (!next_level_queue.empty())
       {
           next_level_queue.pop();
       }

       cout << "==== level:" << level++ << " ====" << endl;
       while (!level_queue.empty())
       {
           Node *temp = level_queue.front();
           if (temp)
               visit(&(temp->data));
           if (temp->pleft)
               next_level_queue.push(temp->pleft);
           if (temp->pright)
               next_level_queue.push(temp->pright);

           level_queue.pop();
       }
       level_queue = next_level_queue;
   }
   cout << "====   END   ====" << endl;
}

int BinarySearchTree::Insert(int data)
{
    Node *pdst = root;
    while (pdst!= NULL)
    {
        if (data == pdst->data)
        {
            //keyword exist
            return -1;
        }
        else if (data > pdst->data)
        {
            if (NULL == pdst->pright)
            {
                Node *temp = new Node(data);
                pdst->pright = temp;
                return 0;
            }
            else
            {
                pdst = pdst->pright;
            }
        }
        else
        {
            if (NULL == pdst->pleft)
            {
                Node *temp = new Node(data);
                pdst->pleft = temp;
                return 0;
            }
            else
            {
                pdst = pdst->pleft;
            }
        }
    }
    return 0;
}

//If search it, return 0; *pnode points the keyword, *ppparent points to the parent of the node that store the key
//If not search it, return -1; *pnode points NULL, **pparent points the last node that travels
int BinarySearchTree::Search(int key, Node** ppparent, Node** ppnode)
{
    Node* pparent = NULL;
    Node* pnode = root;
    do
    {
        if (key > pnode->data)
        {
            pparent = pnode;
            pnode = pnode->pright;
        }
        else if (key < pnode->data)
        {
            pparent = pnode;
            pnode = pnode->pleft;
        }
        else if (key == pnode->data)
        {
            break;
        }
    }while(pnode != NULL);

    *ppparent = pparent;
    *ppnode = pnode;

    if (pnode == NULL)
    {
        cout << "Can't search " << key << " parent is :";
        if (pparent)
        {
            cout << pparent->data << endl;
        }
        else
        {
            cout << " NULL " << endl;
        }
        return -1;
    }
    else 
    {
        cout << "Searched " << key << " parent is :";
        if (pparent)
        {
            cout << pparent->data << endl;
        }
        else
        {
            cout << " NULL " << endl;
        }
        return 0;
    }
}

int BinarySearchTree::Search(int key)
{
    Node *pparent = NULL;
    Node *pnode = NULL;
    int result = Search(key, &pparent, &pnode);
    return result;
}

#include    <assert.h>
int BinarySearchTree::Delete(int key)
{
    Node *pparent = NULL;
    Node *pnode = NULL;
    int result = Search(key, &pparent, &pnode);
    if (result == 0)
    {
        //searched
        if (pnode->pleft == NULL and pnode->pright == NULL)
        {
            assert(pparent->pleft == pnode or pparent->pright == pnode);
            if (pparent->pleft == pnode) pparent->pleft = NULL;
            else if (pparent->pright == pnode) pparent->pright = NULL;

            delete pnode;
        }
        else if (pnode->pleft == NULL and pnode->pright)
        {
            if (pparent->pleft == pnode)
            {
                pparent->pleft = pnode->pright;
                delete pnode;
            }
            else if (pparent->pright == pnode)
            {
                pparent->pright = pnode->pright;
                delete pnode;
            }
        }
        else if (pnode->pright == NULL and pnode->pleft)
        {
            if (pparent->pleft == pnode)
            {
                pparent->pleft = pnode->pleft;
                delete pnode;
            }
            else if (pparent->pright == pnode)
            {
                pparent->pright = pnode->pleft;
                delete pnode;
            }
        }
        else
        {
            Node *parent_of_leftchild_of_node = pnode;
            Node *leftchild_of_node = pnode->pleft;

            while (true)
            {
                if (leftchild_of_node->pright)
                {
                    parent_of_leftchild_of_node = leftchild_of_node;
                    leftchild_of_node = leftchild_of_node->pright;
                }
                else
                {
                    break;
                }
            }
            cout << "leftchild_of_nodep->data:" << leftchild_of_node->data << endl;
            cout << "pnode->data:" << pnode->data << endl;
            cout << "parent_of_leftchild_of_node->data:" << parent_of_leftchild_of_node->data << endl;

            pnode->data = leftchild_of_node->data;
            if (parent_of_leftchild_of_node == pnode)
            {
                parent_of_leftchild_of_node->pleft = leftchild_of_node->pleft;
            }
            else
            {
                parent_of_leftchild_of_node->pright = leftchild_of_node->pleft;
            }
            delete leftchild_of_node;
        }
        return 0;
    }
    else if (result == -1)
    {
        //not searched the key
        return -1;
    }
    return 0;
}
