/*
 * ============================================================================
 *
 *       Filename:  1.cc
 *
 *    Description:  modify binary tree to double link list
 *
 *        Version:  1.0
 *        Created:  07/05/13 10:09:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <binarytree.h>

Node *g_list_head = NULL;
void ModifyNode(Node *pRoot)
{
    static Node *last_node = NULL;

    pRoot->pleft_ = last_node;
    if (last_node == NULL)
    {
        g_list_head = pRoot;
    }
    else
    {
        last_node->pright_ = pRoot;
    }

    last_node = pRoot;
}

void InorderTravesal(Node *pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }

    InorderTravesal(pRoot->pleft_);
    ModifyNode(pRoot);
    InorderTravesal(pRoot->pright_);
}

void PrintList(Node *p_list_head)
{
    while (p_list_head)
    {
        cout << "node: " << p_list_head->data_ <<endl;
        p_list_head = p_list_head->pright_;
    }
}

int main()
{
    Node *pRoot = CreateBinaryTree();

    InorderTravesal(pRoot);

    PrintList(g_list_head);

    return 0;

}
