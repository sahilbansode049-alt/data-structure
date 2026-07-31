#include<stdio.h>
#define MAX 5

int g_Queue[MAX];
int g_iRear=-1;
int g_iFront=-1;

int main(void)
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    Display();

    printf("\nPopped element is %d\t",DeQueue());

    Display();

    return 0;
}
int IsQueueFull()
{
    if(g_iRear==MAX-1)
        return -1;
    return 0;
}
int IsQueueEmpty()
{
    if(g_iRear==-1)
        return -1;
    return 0;
}
void Enqueue(int iNo)
{
    if(IsQueueFull())
    {
        printf("\nQueue is Full");
        return;
    }
    g_Queue[++g_iRear]=iNo;
}
int DeQueue()
{
    int iDelData;

    if(IsEmpty())
    {
        printf("\nQueue is empty");
        return 0;
    }
    iDelData=g_Queue[--g_iFront];

    if(g_iFront==g_iRear)
    {
        g_iRear=-1;
        g_iFront=0;
    }
    else
        g_iFront++;
    return iDelData;
}
void Display()
{
    int iCounter;

    for(iCounter=g_iFront;iCounter<=g_iRear;iCounter++)
    {
        printf("\n%d\t",g_Queue[iCounter]);
    }
}