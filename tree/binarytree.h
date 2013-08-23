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
//The type of tree_node's data is int not use templates
#include <cstddef>
class Node
{
    public:
        Node(int data_ = 0):data(data_), pleft(NULL), pright(NULL){}

        int data;
        Node*       pleft;
        Node*       pright;
};

void PreOrderTraversalRecursive(Node *root, void (*visit)(int*));
void InOrderTraversalRecursive(Node *root, void (*visit)(int*));
void PostOrderTraversalRecursive(Node *root, void (*visit)(int*));

void PreOrderTraversalNonRecursive(Node *root, void (*visit)(int*));
void InOrderTraversalNonRecursive(Node *root, void (*visit)(int*));
void PostOrderTraversalNonRecursive(Node *root, void (*visit)(int*));

void LevelOrderTraversal(Node *root, void (*visit)(int*));
#endif
