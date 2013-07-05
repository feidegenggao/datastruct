/*
 * ============================================================================
 *
 *       Filename:  binarytree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/27/13 10:37:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#ifndef     _BINARYTREE_HEADER
#define     _BINARYTREE_HEADER
#include    <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include    <cstddef>
class Node
{
    typedef int ElementData;
    public:
        Node(ElementData data):data_(data), pleft_(NULL), pright_(NULL){}
        ElementData data_;
        Node*       pleft_;
        Node*       pright_;
};

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
#endif
