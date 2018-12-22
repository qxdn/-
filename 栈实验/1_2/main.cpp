#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define List_init_size 100
#define elem char
#define elem2 int
typedef struct
{
    elem *base;
    elem *top;
    int ListSize;
} SqStack;  //����ջ
typedef struct
{
    elem2 *base;
    elem2 *top;
    int ListSize;
} SqStack2;  //������ջ
/**********
����������ʼ��ջ
������SqStack
���أ�void
**********/
void Init_Stack(SqStack &S)
{
    S.base=(elem *)malloc(List_init_size*sizeof(elem));
    if(!S.base)
        printf("ջ��ʼ��ʧ��\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}
void Init_Stack_num(SqStack2 &S)
{
    S.base=(elem2 *)malloc(List_init_size*sizeof(elem2));
    if(!S.base)
        printf("ջ��ʼ��ʧ��\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}
/**********
������������ջ
������SqStack x
���أ�OK
**********/
int push(SqStack &S,elem x)
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
int push_num(SqStack2 &S,elem2 x)
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
int Pop(SqStack &S,elem &x)
{
    if(S.base==S.top)
    {
        printf("ջ�Ѿ�����\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}
int Pop_num(SqStack2 &S,elem2 &x)
{
    if(S.base==S.top)
    {
        printf("ջ�Ѿ�����\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}

/********************
������Ƚ�
*******************/
elem precede(elem a,elem b)
{
    switch(a)
    {
    case'+':
    case'-':
    {
        if('+'==b||'-'==b||')'==b||'#'==b)
            return '>';
        else
            return '<';
        break;
    }
    case '*':
    case '/':
    {
        if('('==b)
            return '<';
        else
            return  '>';
        break;
    }
    case '(':
    {
        if(')'==b)
            return '=';
        else if('#'==b)
            return '>';
        else
            return '<';
        break;
    }
    case ')':
    {
        if('('==b)
            return '=';
        else
            return '<';
        break;
    }
    case '#':
        return '<';
        break;
    }
}
/**********
�õ�ջ��Ԫ��
***********/
elem get_top(SqStack S)
{
    elem x;
    if(S.base==S.top)
    {
        printf("��\n");
        exit(0);
    }
    x=*(S.top-1);
    return x;
}
elem2 get_top_num(SqStack2 S)
{
    elem2 x;
    if(S.base==S.top)
    {
        printf("��\n");
        exit(0);
    }
    x=*(S.top-1);
    return x;
}
/*******************
����
*********************/
int operate(elem2 a,elem theta,elem2 b)
{
    switch (theta)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default:
        exit(0);
    }
}
/******************
���ܣ�����
������void
*****************/
int Make_str(void)
{
    SqStack OPTR;
    SqStack2 OPND;  // OPTR�����ջ��OPND������ջ
    elem x,theta;
    elem2 a,b;
    char c;
    Init_Stack(OPTR);
    Init_Stack_num(OPND);
    push(OPTR,'#');
    printf("��������ʽ��\n");
    c=getchar();
    while(c!='#'||get_top(OPTR)!='#')
    {
        if(c>='0'&&c<='9')
        {
            push_num(OPND,c-'0');
            c=getchar();
        }
        else
        {
            switch (precede(get_top(OPTR),c))
            {
            case '<':
                push(OPTR,c);
                c=getchar();
                break;
            case '=':
                Pop(OPTR,x);
                c=getchar();
                break;
            case '>':
                Pop(OPTR,theta);
                Pop_num(OPND,b);
                Pop_num(OPND,a);
                push_num(OPND,operate(a,theta,b));
                break;
            }
        }
    }
    return get_top_num(OPND);
}
int main()
{
    int value;
    while(1)
    {
    value=Make_str();
    printf("%d\n",value);
    }
}


