#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};

void EnQueue(struct node **ppHead, int iNo);
int DeQueue(struct node *pHead);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
void Display(struct node *);

int main(void)
{
    struct node *pQueue = NULL;

    EnQueue(&pQueue, 10);
    EnQueue(&pQueue, 20);
    EnQueue(&pQueue, 30);

    Display(pQueue);

    printf("\nPopped element is %d", DeQueue(&pQueue));

    Display(pQueue);

    return 0;
}
void EnQueue(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    if (IsQueueFull(*ppHead))
    {
        printf("\nQueue is full");
        return;
    }
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}
int DeQueue(struct node *pHead)
{
    int DelData;
    if (IsQueueEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *pHead)
        return 0;

    pTemp = *pHead;
    *pHead = pTemp->pNext;
    iDelData = pTemp->iData;

    free(pTemp);

    return iDelData;
}
int IsFull(struct node *pHead)
{
    if (CountNodes(pHead) == MAX)
        return 1;
    return 0;
}
int IsEmpty(struct node *pHead)
{
    if (NULL == pHead)
        return 1;
    return 0;
}
void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nlist is empty");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL");
}
int CountNodes(struct node *pHead)
{
    int iCount = 0;

    if (NULL == pHead)
        return 0;

    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}