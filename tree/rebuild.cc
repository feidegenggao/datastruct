/*
 * ============================================================================
 *
 *       Filename:  rebuild.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/13 20:29:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "binarytree.h"
#include    <assert.h>
#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;

void Visit(int *temp)
{
    cout << "element:" << *temp << endl;
}

int Rebuild(vector<int> preorder, vector<int> inorder, Node* root);
int main()
{
    Node *root = new Node();
    assert(root != NULL);
    vector<int> preorder, inorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(3);
    preorder.push_back(5);
    preorder.push_back(6);

    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(5);
    inorder.push_back(3);
    inorder.push_back(6);

    Rebuild(preorder, inorder, root);

    cout << "PreOrderTraversalRecursive:" << endl;
    PreOrderTraversalRecursive(root, &Visit);

    cout << "InOrderTraversalRecursive:" << endl;
    InOrderTraversalRecursive(root, &Visit);

    cout << "PostOrderTraversalRecursive:" << endl;
    PostOrderTraversalRecursive(root, &Visit);

    PreOrderTraversalNonRecursive(root, &Visit);
    InOrderTraversalNonRecursive(root, &Visit);
    PostOrderTraversalNonRecursive(root, &Visit);

    LevelOrderTraversal(root, &Visit);

    BinarySearchTree first_binary_search_tree(4);
    first_binary_search_tree.Insert(2);
    first_binary_search_tree.Insert(1);
    first_binary_search_tree.Insert(3);
    first_binary_search_tree.Insert(6);
    first_binary_search_tree.Insert(5);

    first_binary_search_tree.Search(3);
    first_binary_search_tree.Search(2);
    first_binary_search_tree.Search(5);

    LevelOrderTraversal(first_binary_search_tree.Root(), &Visit);
    first_binary_search_tree.Delete(4);
    LevelOrderTraversal(first_binary_search_tree.Root(), &Visit);
    return 0;
}

int Rebuild(vector<int> preorder, vector<int> inorder, Node* root)
{
    for (vector<int>::iterator it = preorder.begin(); it != preorder.end(); ++it)
    {
        cout << "preorder:" << *it << endl;
    }
    for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it)
    {
        cout << "inorder:" << *it << endl;
    }
    cout << "preorder.size():" << preorder.size() << endl;
    cout << "inorder.size():" << inorder.size() << endl;

    assert(root != NULL and preorder.size() == inorder.size() and preorder.size() > 0);

    root->data = *preorder.begin();

    vector<int>::iterator root_it = find(inorder.begin(), inorder.end(), root->data);
    assert(root_it != inorder.end());

    vector<int> sub_left_inorder(inorder.begin(), root_it);
    if (sub_left_inorder.size() == 0)
    {
        root->pleft = NULL;
    }
    else
    {
        root->pleft = new Node();
        vector<int>::iterator sub_left_preorder_begin_it = ++preorder.begin();
        vector<int>::iterator sub_left_preorder_end_it = sub_left_preorder_begin_it;
        for (vector<int>::size_type i = 0; i < sub_left_inorder.size(); ++i)
        {
            sub_left_preorder_end_it++;
        }
        vector<int> sub_left_preorder(sub_left_preorder_begin_it, sub_left_preorder_end_it);
        Rebuild(sub_left_preorder, sub_left_inorder, root->pleft);
    }

    vector<int> sub_right_inorder(++root_it, inorder.end());
    if (sub_right_inorder.size() == 0)
    {
        root->pright = NULL;
    }
    else
    {
        root->pright = new Node();
        vector<int>::iterator sub_right_preorder_end_it = preorder.end();
        vector<int>::iterator sub_right_preorder_begin_it = sub_right_preorder_end_it;
        for (vector<int>::size_type i = 0; i < sub_right_inorder.size(); ++i)
        {
            --sub_right_preorder_begin_it;
        }
        vector<int> sub_right_preorder(sub_right_preorder_begin_it, sub_right_preorder_end_it);
        Rebuild(sub_right_preorder, sub_right_inorder, root->pright);
    }

    return 0;
}
