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
            cout << "once" << endl;
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
