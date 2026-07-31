#include <stdio.h>
#include <stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};

void ConcateAtposition(struct node **, struct node **, int);
void InsertAtFirst(struct node **, int iNo);
void Display(struct node *);
int CountNodes(struct node *);
void ConcateLists(struct node **ppHead1, struct node **ppHead2);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecound = NULL;

    InsertAtFirst(&pFirst, 40);
    InsertAtFirst(&pFirst, 30);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 10);

    InsertAtFirst(&pSecound, 70);
    InsertAtFirst(&pSecound, 60);
    InsertAtFirst(&pSecound, 50);

    ConcateAtposition(&pFirst, &pSecound, 2);

    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
    
    return 0;
}
void ConcateAtposition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead1);
    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nposition is invalid");
        return;
    }
    // we don't know 2nd is empty or not
    // we don't know 1st is empty or not
    // if 1st list is empty then position is surely 1

    if (NULL == *ppHead2)
        return;
    // 2nd list is surely present
    // we don't know 1 st list is empty or not
    // if 1st list is empty then position is surely 1

    if (iPos == 1)
    {
        ConcateLists(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }
    // surely both list are present and position not 1

    /*if (iPos == iCount + 1)
    {
        ConcateLists(ppHead1, ppHead2);
        return;
    }*/
    // pos is btween two nodes

    pTemp1 = *ppHead1;
    iCount = 1;
    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = *ppHead2;
    while (pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = NULL;
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
void ConcateLists(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

    pTemp = *ppHead1;
    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
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