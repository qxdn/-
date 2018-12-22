#include <stdio.h>
#include <stdlib.h>
#define elem int
#define list_init_size 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
elem data[8]= {49,38,65,97,76,13,27,49}; //����������
typedef struct sqlist
{
    elem* Elem;
    int length;
    int list_size;
} SqList;
/********************
˳����ʼ��
********************/
int SqList_init(SqList &L)
{
    L.Elem=(elem*)malloc(list_init_size*sizeof(elem));
    if(NULL==L.Elem)
        return OVERFLOW;
    L.list_size=list_init_size;
    L.length=0;
    return OK;
}
/********************
�ݻ�˳���
********************/
void destory_SqList(SqList &L)
{
    free(L.Elem);
    L.length=0;
    L.list_size=0;
}
/*****************
װ���ֵ
*****************/
int Reload_data(SqList &L)
{
    int data_i;
    for(data_i=0; data_i<(sizeof(data)/sizeof(elem)); data_i++)    //����������˳���
        L.Elem[data_i]=data[data_i];
    L.length=(sizeof(data)/sizeof(elem));
    return OK;
}
/*****************************
���˳���ֵ
******************************/
void printf_Sqlist(SqList &L)
{
    int i;
    for(i=0; i<L.length; i++)
        printf("%d ",L.Elem[i]);
    printf("\b\n");
}
/***************************
�򵥲�������  v1PASS
**************************/
void insertsort(SqList &L)
{
    int i;
    int j;
    int temp;
    for(i=1; i<L.length; i++)      //�ӵڶ��ʼ��
    {
        temp=L.Elem[i];                 //��ʱ�������һ�������
        for(j=i; j>0; j--)
        {
            if(temp<L.Elem[j-1])     //���������С�ڵ�ǰ�����
            {
                L.Elem[j]=L.Elem[j-1];
            }
            else                     //�ҵ������
                break;
        }
        L.Elem[j]=temp;      //����
    }
}
/***********************
����˳��������Ԫ��
************************/
void swap_sqlist(elem *a,elem *b)
{
    elem temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
/************************
ð������  v1PASS
************************/
void Bubble_sort(SqList &L)
{
    int i,j;
    for(i=0; i<L.length-1; i++)
        for(j=0; j<L.length-1-i; j++)
        {
            if(L.Elem[j]>L.Elem[j+1])
            {
                swap_sqlist(&L.Elem[j],&L.Elem[j+1]);
            }
        }
}
/**********************
����������λ��
***********************/
int partiton(SqList &L,int low,int high)
{
    while(low<high)
    {
        while(low<high&&L.Elem[high]>=L.Elem[low])
            high--;
        swap_sqlist(&L.Elem[low],&L.Elem[high]);
        while(low<high&&L.Elem[high]>=L.Elem[low])
            low++;
        swap_sqlist(&L.Elem[low],&L.Elem[high]);
    }
    return low;
}
/**************************
�ݹ���п�������
***************************/
void qsort(SqList &L,int low,int high)
{
    int pivotloc;     //����
    if(low<high)
    {
        pivotloc=partiton(L,low,high);
        qsort(L,low,pivotloc-1);
        qsort(L,pivotloc+1,high);
    }
}
/***************************
�������� v1pass
*****************************/
void quick_sort(SqList &L)
{
    qsort(L,0,L.length-1);
}
/*************************
�鲢���� �ϲ�
**************************/
void Merge(SqList temp_L,SqList &L,int i,int m, int n)
{
    //��i~m��m+1~n�ϲ�
    int j,k;
    for(j=m+1,k=i; i<=m&&j<=n; k++)             //�Ƚϴ�С�ϲ�
        if(temp_L.Elem[i]<=temp_L.Elem[j])
            L.Elem[k]=temp_L.Elem[i++];
        else
            L.Elem[k]=temp_L.Elem[j++];
    while(i<=m)                               //�ϲ�ʣ��
        L.Elem[k++]=temp_L.Elem[i++];
    while(j<=n)                              //�ϲ�ʣ��
        L.Elem[k++]=temp_L.Elem[j++];
}
/***************************
�鲢���� �ֿ����� �ݹ鷨
****************************/
void Msort(SqList temp_L,SqList &L,int s,int t)
{
    SqList temp_L_1;
    int m;
    SqList_init(temp_L_1);
    if(s==t)
        L.Elem[s]=temp_L.Elem[s];
    else
    {
        m=(s+t)/2;    //temp_Lƽ����·s~m,m+1~t
        Msort(temp_L,temp_L_1,s,m);   //����s~m
        Msort(temp_L,temp_L_1,m+1,t); //����m+1~t
        Merge(temp_L_1,L,s,m,t);  //�ϲ�ת�Ƶ�L
    }
    destory_SqList(temp_L_1);
}
/***********************
�鲢���� pass
***********************/
void Mergesort(SqList &L)
{
    Msort(L,L,0,L.length-1);
}
/******************
����һ���Ѷ�
********************/
void head_adjust(SqList &L,int s, int m)
{
    int i;
    elem temp;
    temp=L.Elem[s];
    for(i=2*s+1; i<m; i=i*2+1)//���ӽڵ㿪ʼ
    {
        if(i+1<m&&L.Elem[i]<L.Elem[i+1])   //������ӽڵ�������ӽڵ㣬ָ�����ӽڵ�
            i++;
        if(temp<L.Elem[i]) //����ӽڵ���ڸ��ڵ�
        {
            L.Elem[s]=L.Elem[i];
            s=i;
        }
        else
            break;
    }
    L.Elem[s]=temp;
}
/**********************
������ pass
************************/
void headsort(SqList &L)
{
    int i;
    for(i=L.length/2-1; i>=0; i--)      //�����һ�����ն˽ڵ㿪ʼ������һ���󶥶�
        head_adjust(L,i,L.length);
    for(i=L.length-1; i>0; i--)
    {
        swap_sqlist(&L.Elem[0],&L.Elem[i]);
        head_adjust(L,0,i);
    }
}
void print_menu(void)
{
    printf("1�����ԭʼ����\n");
    printf("2������򵥲���������\n");
    printf("3�����ð��������\n");
    printf("4���������������\n");
    printf("5������鲢������\n");
    printf("6�������������\n");
    printf("7������װ�س�ֵ\n");
    printf("8���˳�\n");
}
int main()
{
    SqList L;   //������
    int choice;
    SqList_init(L);
    Reload_data(L);
    print_menu();
    while(scanf("%d",&choice)&&choice!=8)
    {
        switch(choice)
        {
        case 1:
            Reload_data(L);
            printf_Sqlist(L);
            break;
        case 2:
            insertsort(L);
            printf_Sqlist(L);
            break;
        case 3:
            Bubble_sort(L);
            printf_Sqlist(L);
            break;
        case 4:
            quick_sort(L);
            printf_Sqlist(L);
            break;
        case 5:
            Mergesort(L);
            printf_Sqlist(L);
            break;
        case 6:
            headsort(L);
            printf_Sqlist(L);
            break;
        case 7:
            Reload_data(L);
            printf_Sqlist(L);
            break;
        }
        print_menu();
    }
    destory_SqList(L);
    return 0;
}
