#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};
void EnQueue(struct node **, int);
int DeQueue(struct node **);
void Display(struct node *);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pQueue = NULL;

    EnQueue(&pQueue, 10);
    EnQueue(&pQueue, 20);
    EnQueue(&pQueue, 30);

    Display(pQueue);

    printf("\nPopped element is %d\n", DeQueue(&pQueue));

    Display(pQueue);
    DeleteAll(&pQueue);
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
    if (NULL == pNewNode)
    {
        printf("Memory allocation failed\n");
        return;
    }

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
int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp=NULL;
    if(IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is empty");
        return -1;
    }

    if(NULL==*ppHead)
        return 0;

    pTemp=*ppHead;   
    *ppHead=pTemp->pNext;    
    iDelData=pTemp->iData;

    free(pTemp);

    return iDelData;

}
int IsQueueFull(struct node *pHead)
{
    if(CountNodes(pHead)==MAX)
        return 1;
    return 0;
}
int IsQueueEmpty(struct node *pHead)
{
    if(NULL==pHead)
        return 1;
    return 0;
}
int CountNodes(struct node *pHead)
{
    int iCount=0;

    if(NULL==pHead)
        return 0;

    while(pHead!=NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
}
void Display(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("\nQueue is empty");
        return;
    }
    while(pHead!=NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("NULL");
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
}