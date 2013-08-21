/*
 * ============================================================================
 *
 *       Filename:  preordertravel.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/27/13 10:48:24
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
using namespace std;

Node* CreateBinaryTree()
{
    Node *root = new Node(10);

    Node *node2 = new Node(6);
    Node *node3 = new Node(14);

    Node *node4 = new Node(4);
    Node *node5 = new Node(8);
    Node *node6 = new Node(12);
    Node *node7 = new Node(18);

    root->pleft_ = node2;
    root->pright_ = node3;

    node2->pleft_ = node4;
    node2->pright_ = node5;

    node3->pleft_ = node6;
    node3->pright_ = node7;

    return root;
}

void PreorderTraversal(Node *proot)
{
    if (proot == NULL) return;

    cout << proot->data_ << endl;
    PreorderTraversal(proot->pleft_);
    PreorderTraversal(proot->pright_);
}

void InorderTraversal(Node *proot)
{
    if (proot == NULL) return;

    InorderTraversal(proot->pleft_);
    cout << proot->data_ << endl;
    InorderTraversal(proot->pright_);
}

void PostorderTraversal(Node *proot)
{
    if (proot == NULL) return;

    PostorderTraversal(proot->pleft_);
    PostorderTraversal(proot->pright_);
    cout << proot->data_ << endl;
}

int main()
{
    Node *root = CreateBinaryTree();
    cout << "PreorderTraversal" << endl;
    PreorderTraversal(root);

    cout << "InorderTraversal" << endl;
    InorderTraversal(root);

    cout << "PostorderTraversal" << endl;
    PostorderTraversal(root);

    return 0;
}
