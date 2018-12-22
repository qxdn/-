#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define overflow (-2)
typedef struct List
{
    int data;
    struct List* next;
} ListNode,*Linklist;
/**************************
��ӡ����Ԫ��
******************************/
int print_list(Linklist &L)
{
    Linklist p=NULL;
    int i=1;
    if(L==NULL)
    {
        printf("��δ��ʼ�������ʼ������\n");
        return ERROR;
    }
    printf("����������Ϊ:\n");
    p=L->next;
    while(p)
    {
        printf("%d     %d\n",i,p->data);
        p=p->next;
        i++;
    }
    return OK;
}
/**********************
�����ʼ��
***********************/
int List_Init(Linklist &L)
{
    if(L==NULL)
    {
        L=(Linklist)malloc(sizeof(ListNode));
        L->next=NULL;
    }
    else
    {
        printf("�Ѿ�������ʼ��\n");
        return OK;
    }
    if(L==NULL)
    {
        printf("�����ʼ��ʧ��\n");
        return ERROR;
    }
    else
    {
        printf("�����ʼ�����\n");
        return OK;
    }
}
/******************************
����ڵ�
******************************/
int insert_Node(Linklist &L)
{
    Linklist p=NULL,new_node=NULL;
    int data,place;
    int i=1;
    if(L==NULL)
    {
        printf("��δ��ʼ�������ʼ������\n");
        return ERROR;
    }
    printf("���������ڵ��λ�ã�������Ϊ�ڼ����ڵ㣩\n");
    scanf("%d",&place);
    printf("������Ҫ���������\n");
    scanf("%d",&data);
    p=L;
    while(p&&i<place)
    {
        p=p->next;
        i++;
    }
    if(!p||i>place)
        return  overflow;
    new_node=(Linklist)malloc(sizeof(ListNode));
    new_node->data=data;
    new_node->next=p->next;
    p->next=new_node;
    printf("�������\n");
    return OK;
}
/*******************
ɾ���ڵ�
******************/
int del_node(Linklist &L)
{
    Linklist p=NULL,temp=NULL;
    int i=1;
    int place;
    char check;
    if(L==NULL)
    {
        printf("��δ��ʼ�������ʼ������\n");
        return ERROR;
    }
    printf("�������ɾ���ڵ��λ��\n");
    scanf("%d",&place);
    p=L;
    while(!p&&i<place)
    {
        p=p->next;
        i++;
    }
    if(!p||i>place)
        return overflow;
    temp=p->next;
    printf("Ҫɾ����������%d,Yȷ��ɾ��(�����ִ�Сд)\n",temp->data);
    getchar();
    scanf("%c",&check);
    if(check=='Y'||check=='y')
    {
        p->next=temp->next;
        free(temp);
        printf("ɾ�����\n");
        return OK;
    }
    else
        return OK;
}
int find_node(Linklist &L)
{
    Linklist p=NULL;
    int n;
    int i=1;
    if(L==NULL)
    {
        printf("��δ��ʼ�������ʼ������\n");
        return ERROR;
    }
    printf("��������Ҫ���ҵĽڵ㣺\n");
    scanf("%d",&n);
    p=L->next;
    while(p)
    {
        if(p->data==n)
        {
            printf("�ڵ��λ����%d\n",i);
            return OK;
        }
        p=p->next;
        i++;
    }
    printf("û�иýڵ�\n");
}
void print_menu(void)
{
    printf("���ã�������ѡ�\n");
    printf("1����ʼ������\n");
    printf("2���ڳ�ʼ����ɵ�����������µĽڵ�\n");
    printf("3��ɾ���������һ��ֵ\n");
    printf("4�����ҽڵ�λ��\n");
    printf("5����ӡ�����е�����Ԫ��\n");
    printf("6���˳�\n");
}
int main()
{
    int n;
    Linklist L=NULL;
    print_menu();
    scanf("%d",&n);
    while(n!=6)
    {
        if(!(n>=1&&n<=5))
        {
            printf("��Ч���룬������\n");
            scanf("%d",&n);
            continue;
        }
        switch(n)
        {
        case 1:
            List_Init(L);
            break;
        case 2:
            insert_Node(L);
            break;
        case 3:
            del_node(L);
            break;
        case 4:
            find_node(L);
            break;
        case 5:
            print_list(L);
            break;
        }
        print_menu();
        scanf("%d",&n);
    }
}
