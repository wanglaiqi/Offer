#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define OVERFLOW -1
//求二叉树的深度
//二叉树的节点结构
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBinTree(BiTree T);
int DepthOfTree(BiTree T);
//构建二叉树
BiTree CreateBinTree(BiTree T)
{
    char ch;
    ch = getchar();
    if(ch=='#')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
        {
            exit(OVERFLOW);
        }
        T->data = ch;
        T->lchild = CreateBinTree(T->lchild);
        T->rchild = CreateBinTree(T->rchild);
    }
    return T;
}

int DepthOfTree(BiTree T)
{
    int depth = 0;
    int leftDepth,rightDepth;
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        leftDepth = DepthOfTree(T->lchild);
        rightDepth = DepthOfTree(T->rchild);

        depth = 1 + (leftDepth>rightDepth?leftDepth:rightDepth);
    }
    return depth;
}

int main()
{
    cout<<"***********************程序运行结果********************************"<<endl;
    int depth = 0;
    BiTree T;
    T = NULL;
    cout<<"请你输入二叉树的节点:"<<endl;
    T = CreateBinTree(T);
    depth = DepthOfTree(T);
    cout<<"二叉树的深度是:"<<depth<<endl;
    cout<<"***********************程序运行结束*********************************"<<endl;
    return 0;
}
