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
