#include <stdio.h>
#include <stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};
void InsertAtposition(struct node **, int, int);
void Display(struct node *);
int CountNodes(struct node *);
void InsertAtFirst(struct node **, int);
void InsertAtLast(struct node **, int);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;

    InsertAtFirst(&pFirst, 50);
    InsertAtFirst(&pFirst, 40);
    InsertAtFirst(&pFirst, 30);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 10);

    Display(pFirst);

    InsertAtposition(&pFirst, 60, 3);

    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);
    
    return 0;
}
void InsertAtposition(struct node **ppHead, int iNo, int iPos)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    int iCount;
    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nInvalid input");
        return;
    }
    if (iPos == 1)
    {
        InsertAtFirst(ppHead, iNo);
        return;
    }
    /*if(iPos==iCount+1)
    {
        InsertAtLast(ppHead,iNo);
        return;
    }*/

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("\nMemopry allocation is failed");
        return;
    }

    pNewNode->iData = iNo;

    pTemp = *ppHead;
    iCount = 1;
    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}
void InsertAtFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

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
void InsertAtLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode; // last as well as first node
        return;
    }

    pTemp = *ppHead; // pointing to first node

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
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
    printf("\n");
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