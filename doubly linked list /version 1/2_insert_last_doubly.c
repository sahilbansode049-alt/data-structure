#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);
void InsertLast(struct node **, int);
int main(void)
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst);

    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);
    InsertLast(&pFirst, 70);

    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);

    return 0;
}
void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    pNewNode->pNext = NULL;
    pNewNode->iData = iNo;
    if (NULL == *ppHead)
    {
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }
    pTemp = *ppHead;
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("\nMemory Allocation is failed.");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
    pNewNode = NULL;
}
void Display(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("\nlist is empty.");
        return;
    }
    while(pHead!=NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    }
    printf("NULL\n");
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