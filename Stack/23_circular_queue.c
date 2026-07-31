#include <stdio.h>
#define MAX 5

int g_Queue[MAX];
int g_iRear = -1;
int g_iFront = -1;

int IsQueueFull(void);
int IsQueueEmpty(void);
void EnQueue(int);
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

    printf("\nDeQueue element is %d\n", DeQueue());

    Display();

    return 0;
}
void EnQueue(int iNo)
{
    if (IsQueueFull())
    {
        printf("\nQueue is full.");
        return;
    }
    if (g_iFront == -1)
        g_iFront = 0;

    if (g_iRear == MAX - 1)
        g_iRear = 0;
    else
        ++g_iRear;

    g_Queue[g_iRear] = iNo;
}
int DeQueue(void)
{
    int iDelData;
    if (IsQueueEmpty())
    {
        printf("\nQueue is Empty.");
        return 0;
    }
    iDelData = g_Queue[g_iFront];

    if (g_iRear == g_iFront)
    {
        g_iRear = -1;
        g_iFront = 0;
    }
    else if (g_iFront == MAX - 1) // circular
        g_iFront = 0;
    else
        ++g_iFront;
    return iDelData;
}
int IsQueueFull(void)
{
    if ((g_iFront == 0 && g_iRear == MAX - 1) || (g_iRear == g_iFront - 1))
        return 1;

    return 0;
}
int IsQueueEmpty(void)
{
    if (g_iFront == -1)
        return 1;
    return 0;
}
// verson 1
void Display(void)
{
    int iCounter;
    if (g_iRear == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    if (g_iFront > g_iRear) // circular
    {
        for (iCounter = g_iFront; iCounter <= MAX - 1; iCounter++)
            printf("%d\t", g_Queue[iCounter]);
        for (iCounter = 0; iCounter <= g_iRear; iCounter++)
            printf("%d\t", g_Queue[iCounter]);
    }
    else // normal
    {
        for (iCounter = g_iFront; iCounter <= g_iRear; iCounter++)
            printf("%d\t", g_Queue[iCounter]);
    }
}
// verson 2
/*void Display(void)
{
    int iCounter = g_iFront;

    if (IsQueueFull())
    {
        printf("\nQueue is full.");
        return;
    }
    if (g_iFront > g_iRear) // circular
    {
        for (; iCounter <= MAX - 1; iCounter++)
            printf("%d\t", g_Queue[iCounter]);
        return 0;
    }
    for (; iCounter <= g_iRear; iCounter++)
        printf("%d\t", g_Queue[iCounter]);
}*/