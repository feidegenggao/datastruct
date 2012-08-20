/*
 * ============================================================================
 *
 *       Filename:  binarytree.h
 *
 *    Description:  header of binarytree
 *
 *        Version:  1.0
 *        Created:  08/16/12 21:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333 at gmail dot com
 *   Organization:  NDSL UESTC
 *
 * ============================================================================
 */
#ifndef     _TREE_BINARYTREE_HEADER
#define     _TREE_BINARYTREE_HEADER
#include    "../../my.h"
#include    <queue>

typedef int TElemType;

typedef struct BiTNode{
    TElemType   data;
    struct BiTNode *lchild, *rchild;

    BiTNode()
    {
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
}BiTNode, *BiTree;

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        Status Init();
        Status ClearBiTree();
        BiTree Root() { return m_root;}
        bool BiTreeEmpty();
        int BiTreeDepth(){ return m_depth;}
        int BiTreeNum(){ return m_nodesum;}

        Status PreOrderTraverse(BiTree, Status(* Visit)(TElemType));
        Status InOrderTraverse(BiTree, Status(*Visit)(TElemType));
        Status PostOrderTraverse(BiTree, Status(*Visit)(TElemType));
        Status LevelOrderTraverse(BiTree, Status(*Visit)(TElemType));
        
    private:
        Status CreateBiTree(BiTree&);
        BiTree m_root;
        int m_depth;
        int m_nodesum;
};
#endif
