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
        bool BiTreeEmpty();
        int BiTreeDepth(){ return depth;}
        int BiTreeNum(){ return nodesum;}

        Status PreOrderTraverse(Status(*Visit(TElemType)));
        Status InOrderTraverse(Status(*Visit(TElemType)));
        Status PostOrderTraverse(Status(*Visit(TElemType)));
        Status LevelOrderTraverse(Status(*Visit(TElemType)));
        
    private:
        Status CreateBiTree(BiTree);
        BiTree root;
        int depth;
        int nodesum;
};
#endif
