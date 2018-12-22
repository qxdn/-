#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
/*****************
����������
*****************/
int CreatBiTree(BiTree &T)
{
    elem ch;
    scanf("%c",&ch);
    getchar();
    if(' '==ch)
        T=NULL;
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
            return OVERFLOW;
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}
/*********************
Ѱ�Ҷ�Ϊ1�Ľڵ����
***********************/
int count_one(BiTree &T)
{
    int count_d=0;
    if(T)
    {
    if(T->lchild&&!T->rchild)
    {
        count_d++;
     //   count_d+=count_one(T->lchild);
    }
    else if(!T->lchild&&T->rchild)
    {
        count_d++;
     //   count_d+=count_one(T->rchild);
    }
    if(!T->lchild&&!T->rchild)
        return 0;
    count_d+=count_one(T->lchild);          //�޸����ڵ��������������
    count_d+=count_one(T->rchild);
    return count_d;
    }
    else
        return 0;
}

int main()
{
    BiTree T;
    printf("����һ������\n");
    CreatBiTree(T);
    printf("��Ϊһ�Ľڵ���Ϊ%d",count_one(T));
    return 0;
}
