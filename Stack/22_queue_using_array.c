#include<stdio.h>
#define MAX 5

int g_Queue[MAX];
int g_iRear=-1;
int g_iFront=-1;

int IsQueueFull(void);
int IsQueueEmpty(void);
void EnQueue(int );
int DeQueue(void);
void Display(void);

int main(void)
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);

    Display();

    printf("\nDeQueue element is %d\n",DeQueue());

    Display();

    return 0;
}
int IsQueueFull(void)
{
    if(g_iRear==MAX-1)
        return 1;
    return 0;
}
int IsQueueEmpty(void)
{
    if(g_iFront==-1)
        return 1;
    return 0;
}
void EnQueue(int iNo)
{
    if(IsQueueFull())
    {
        printf("\nQueue is Full");
        return;
    }
    if(g_iFront == -1)   // first element
        g_iFront = 0;

    g_Queue[++g_iRear]=iNo;
}
int DeQueue(void)
{
    int iDelData;

    if(IsQueueEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }
    iDelData=g_Queue[g_iFront];  //adhi value de

    if(g_iFront==g_iRear)    //only one element 
    {
        g_iRear=-1;          //mg reset kr
        g_iFront=-1;
    }
    else
        g_iFront++;
    return iDelData;
}
void Display(void)
{
    int iCounter;

    for(iCounter=g_iFront;iCounter<=g_iRear;iCounter++)
    {
        printf("%d\t",g_Queue[iCounter]);
    }
}