#include<stdio.h>
#define MAX 5

int g_Stack[MAX];
int g_iTop=-1;

void Push(int );
int Pop(void);
void Display(void);
int IsFull(void);
int IsEmpty(void);

int main(void)
{
    Push(10);
    Push(20);
    Push(30);

    Display();

    printf("\nPopped element is %d\n",Pop());

    Display();

    return 0;
}

void Push(int iNo)
{
    if(IsFull())
    {
        printf("\nStack is overflow");
        return;
    }
    g_Stack[++g_iTop]=iNo;    //aadhi pudha ja mg value tak
}
int Pop(void)
{
    int iPoppedData;
    if(IsEmpty())
    {
        printf("\nstack is Full.");
        return 0;
    }

    iPoppedData=g_Stack[g_iTop--];   //aadhi value de mg pudhe ja

    return iPoppedData;
}
int IsFull(void)
{
    if(g_iTop==MAX-1)
        return 1;
    return 0;
}
int IsEmpty(void)
{
    if(g_iTop==-1)
        return 1;
    return 0;
}
void Display(void)
{
    int iCounter;
    if(g_iTop==-1)
    {
        printf("\nstack is empty.");
        return;
    }

    for(iCounter=0;iCounter<=g_iTop;iCounter++)
    {
        printf("%d\t",g_Stack[iCounter]);
    }
}//output:
/*
10      20      30
Popped element is 30    20      10
*/