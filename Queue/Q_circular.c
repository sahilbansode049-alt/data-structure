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