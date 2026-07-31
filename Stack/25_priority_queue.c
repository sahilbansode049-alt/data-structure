#include <stdio.h>
#include <stdlib.h>
#define MAX 8

struct node
{
    int iData;
    int iPriority;
    struct node *pNext;
};

void InQueue(struct node **, int iNo, int);
int DeQueue(struct node **, int);
int IsQueueFull(struct node *);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
void InsertFirst(struct node **, int, int);
void Display(struct node *);
int CountNodes(struct node *);

int main(void)
{
    struct node *pQueue = NULL;

    InQueue(&pQueue, 50, 3);
    InQueue(&pQueue, 10, 2);
    InQueue(&pQueue, 40, 1);
    InQueue(&pQueue, 30, 4);
    InQueue(&pQueue, 20, 5);
    InQueue(&pQueue, 60, 6);

    Display(pQueue);

    printf("\nDeQueue element id %d\t", DeQueue(&pQueue, 3));
    printf("\n");
    Display(pQueue);

    return 0;
}

void InQueue(struct node **ppHead, int iNo, int iPriority)
{
    struct node *pTemp = NULL, *pNewNode = NULL;
    if (IsQueueFull(*ppHead))
    {
        printf("\nQueue is full.");
        return;
    }

    if (NULL == *ppHead || iPriority > ((*ppHead)->iPriority))
    {
        InsertFirst(ppHead, iNo, iPriority);
        return;
    }
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("\nMemory allocation is failed.");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->iPriority = iPriority;
    pNewNode->pNext = NULL;

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
    {
        if (iPriority > pTemp->pNext->iPriority)
            break;

        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}
int DeQueue(struct node **ppHead, int iNo)
{
    int iDelData;
    struct node *pTemp = NULL;
    if (IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is empty");
        return -1;
    }

    if (NULL == *ppHead)
        return 0;

    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    iDelData = pTemp->iData;

    free(pTemp);

    return iDelData;
}
int IsQueueFull(struct node *pHead)
{
    if (CountNodes(pHead) == MAX)
        return 1;
    return 0;
}
int IsQueueEmpty(struct node *pHead)
{
    if (NULL == pHead)
        return 1;
    return 0;
}
void InsertFirst(struct node **ppHead, int iNo, int iPri)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    // pNewNode->iPriority = iPri;
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
    printf("NULL\n");
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