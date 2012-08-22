//定义变量类型。
#ifndef     _TREE_BINARYTREE_ELEMTYPE_HEADER
#define     _TREE_BINARYTREE_ELEMTYPE_HEADER
typedef int TElemType;

typedef struct BiTNode{
    TElemType   data;
    struct BiTNode *lchild, *rchild;
    //flag 用于树的非递归后序遍历。其他地方未用到。
    bool flag;

    BiTNode()
    {
        data = 0;
        lchild = NULL;
        rchild = NULL;
        flag = false;
    }
}BiTNode, *BiTree;

typedef BiTree Elemtype;
#endif//_TREE_BINARYTREE_HEADER
