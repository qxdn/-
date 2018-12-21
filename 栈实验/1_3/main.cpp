#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem int
#define List_init_size 100
typedef struct
{
    int *base;
    int *top;
    int ListSize;
} SqStack;
typedef struct link_stack_node
{
    elem data;
    struct link_stack_node *next;
} link_stack_node,*link_stack;
/**********
����������ʼ��ջ
������SqStack
���أ�void
**********/
void Init_Stack(SqStack &S)
{
    S.base=(int *)malloc(List_init_size*sizeof(int));
    if(!S.base)
        printf("ջ��ʼ��ʧ��\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}
/*********************
��ʼ����ջ
**********************/
int init_link_stack(link_stack &L)
{
    L=(link_stack)malloc(sizeof(link_stack_node));
    if(NULL==L)
        exit(ERROR);
    L->next=NULL;
    return OK;
}
/************************
��ջ�ڲ���Ԫ��
************************/
int push_link_stack(link_stack &L,elem e)
{
    link_stack temp;
    temp=(link_stack)malloc(sizeof(link_stack_node));
    if(!temp)
        exit(ERROR);
    temp->data=e;
    temp->next=L->next;
    L->next=temp;
    return OK;
}
/**************
�����ջ��ջ��Ԫ��
****************/
int get_link_stack_top(link_stack &L,elem &e)
{
    if(!L->next)
        return ERROR;
    e=L->next->data;
}
/*******************
��ջ��ջ
********************/
int pop_link_stack(link_stack &L,elem &e)
{
    link_stack temp;
    if(!L->next)
        return ERROR;
    temp=L->next;
    e=temp->data;
    L->next=temp->next;
    free(temp);
    return OK;
}
/***************
�ݻ���ջ
****************/
void destory_link_Stack(link_stack &L)
{
    elem n;
    while(pop_link_stack(L,n))
        ;
    free(L);
}
/*****************
�ж���ջ�Ƿ�Ϊ��
******************/
int Is_link_stack_empty(link_stack &L)
{
    if(!L->next)
        return 1;
    else
        return 0;
}
/**********
�����������ջ
������SqStack
���أ�OK
**********/
int clear_Stack(SqStack &S)
{
    while(S.top>S.base)
    {
        S.top--;
    }
    printf("ջ�Ѿ����\n");
    return OK;
}
/**********
���������ݻ�ջ
������SqStack
���أ�OK
**********/
int destory_Stack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.ListSize=0;
    printf("ջ�Ѿ��ݻ�\n");
    return OK;
}
/**********
������������ջ
������SqStack x
���أ�OK
**********/
int push(SqStack &S,int x)
{
    if(S.top-S.base>=S.ListSize)
    {
        printf("ջ�Ѿ�����\n");
        return OVERFLOW;
    }
    *(S.top)=x;
    S.top++;
    return OK;
}
/**********
����������ջ
������SqStack x
���أ�OK
**********/
int Pop(SqStack &S,int &x)
{
    if(S.base==S.top)
    {
        printf("ջ�Ѿ�����\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}

int get_top(SqStack &S,int &x)
{
    if(S.base==S.top)
        return ERROR;
    x=*(S.top-1);
    return OK;
}
int cal_t(int n)
{
    int sum=0;
    link_stack S;
    init_link_stack(S);
    push_link_stack(S,n);
    while(1)
    {
        get_link_stack_top(S,n);
        if(n==0)
        {
            break;
        }
        else
        {
            push_link_stack(S,n/2);
        }
    }
    while(!Is_link_stack_empty(S))
    {
        pop_link_stack(S,n);
        sum=2*sum+n;
    }
    destory_link_Stack(S);
    return sum;
}
int t_n(int n)
{
    if(n==0)
        return 0;
    return 2*t_n(n/2)+n;
}
int main()
{
    int n;
    printf("������Ҫ�����ֵ\n");
    scanf("%d",&n);
    printf("�ݹ�Ľ����%d\n",t_n(n));
    printf("ջ�Ľ����%d\n",cal_t(n));
}
