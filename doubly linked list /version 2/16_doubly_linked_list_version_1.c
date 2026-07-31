#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
void InsertLast(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int CountNodes(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);
int SearchFirstOccurrence(struct node *, int);
int SearchLastOccurrence(struct node *, int);
int SearchAllOccurrences(struct node *, int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void ConcatLists(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void DeleteAll(struct node **);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst); // list is empty

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst); // 10 20 30

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);

    Display(pFirst); // 10 20 30 40 50 60

    InsertAtPosition(&pFirst, 20, 4);

    Display(pFirst); // 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst);
    if (iData != -1)
        printf("First node Deleted data is %d\n", iData); // 10

    Display(pFirst); // 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if (iData != -1)
        printf("Last node Deleted data is %d\n", iData); // 60

    Display(pFirst); // 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst, 4);
    if (iData != -1)
        printf("Deleted data is %d\n", iData); // 40

    Display(pFirst); // 20 30 20 50

    iData = SearchFirstOccurrence(pFirst, 20);
    if (iData != 0)
        printf("First occurrence of %d is at %d position\n", 20, iData); // 1

    iData = SearchLastOccurrence(pFirst, 20);
    if (iData != 0)
        printf("Last occurrence of %d is at %d position\n", 20, iData); // 3

    iData = SearchAllOccurrences(pFirst, 20);
    printf("%d found %d times\n", 20, iData); // 2

    iData = CountNodes(pFirst);
    printf("Total node count is %d\n", iData); // 4

    Display(pFirst); // 20 30 20 50
    PhysicalReverse(&pFirst);
    Display(pFirst); // 50 20 30 20
    PhysicalReverse(&pFirst);
    Display(pFirst);        // 20 30 20 50
    ReverseDisplay(pFirst); // 50 20 30 20
    Display(pFirst);        // 20 30 20 50

    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);

    Display(pFirst);  // 20 30 20 50
    Display(pSecond); // 100 200 300
    ConcatLists(&pFirst, &pSecond);
    Display(pFirst);  // 20 30 20 50 100 200 300
    Display(pSecond); // List is empty

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);

    Display(pFirst);  // 20 30 20 50 100 200 300
    Display(pSecond); // 400 500 600
    ConcatAtPosition(&pFirst, &pSecond, 4);
    Display(pFirst);  // 20 30 20 400 500 600 50 100 200 300
    Display(pSecond); // List is empty
    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if (pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }

    Display(pFirst);  // List is empty
    Display(pSecond); // List is empty

    return 0;
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
    if (NULL == pHead)
    {
        printf("\nlist is empty.\n");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
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
void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
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
        InsertFirst(ppHead, iNo);
        return;
    }
    /*if(iPos==iCount+1)
    {
        InsertLast(ppHead,iNo);
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
    if (pTemp->pNext != NULL)
        pNewNode->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pNewNode;

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;
    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    if (NULL == *ppHead)
        return 0;
    iDelData = (*ppHead)->iData;

    if (NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        //(*ppHead)->pPrev->pNext=NULL;
        (*ppHead) = (*ppHead)->pNext;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev = NULL;
    }
    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return 0;
    pTemp = *ppHead;

    if (NULL == pTemp->pNext)
        *ppHead = NULL;
    else
    {
        while (pTemp->pNext != NULL)
            pTemp = pTemp->pNext;

        pTemp->pPrev->pNext = NULL;
    }
    iDelData = pTemp->iData;
    free(pTemp);

    return iDelData;
}
int DeleteAtPosition(struct node **ppHead, int iPos)
{
    struct node *pTemp = NULL;
    int iCount;
    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
        return -1;

    if (iPos == -1)
        return DeleteFirst(ppHead);
    // if(iPos==iCount)
    // return DeleteLast(ppHead);

    pTemp = *ppHead;
    iCount = 1;
    while (iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }
    if (pTemp->pNext != NULL)
        pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pTemp->pPrev;

    iCount = pTemp->iData;
    free(pTemp);

    return iCount;
}
int SearchFirstOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0;
    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            return iPos;
        pHead = pHead->pNext;
    }
    return 0;
}
int SearchLastOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0;
    int iLastPos = 0;
    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            iLastPos = iPos;
        pHead = pHead->pNext;
    }
    if (iLastPos == 0)
        return 0;
    else
        return iLastPos;
}
int SearchAllOccurrences(struct node *pHead, int iKey)
{
    int iCount = 0;
    while (pHead != NULL)
    {
        if (pHead->iData == iKey)
            iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}
void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = NULL;
    struct node *pNext = NULL;

    pCurrent = (struct node *)malloc(sizeof(struct node));

    pCurrent = *ppHead;

    while (pCurrent != NULL)
    {
        pNext = pCurrent->pNext;

        pCurrent->pNext = pPrev;
        pCurrent->pPrev = pNext;

        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}
void ReverseDisplay(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nlist is Empty.");
        return;
    }
    while (pHead->pNext != NULL)
        pHead = pHead->pNext;

    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pPrev;
    }
    printf("NULL\n");
}
void ConcatLists(struct node **ppHead1, struct node **ppHead2)
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
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
}
void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
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

    if (NULL == *ppHead2)
        return;

    if (iPos == 1)
    {
        ConcatLists(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    /*if(iPos==iCount+1)
    {
        ConcateLists(ppHead1,ppHead2);
        return;
    }*/

    pTemp1 = *ppHead1;
    iCount = 1;
    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = *ppHead2;
    while (pTemp2->pNext != NULL)
        pTemp2 = pTemp2->pNext;

    pTemp2->pNext = pTemp1->pNext;
    if (pTemp1->pNext != NULL)
        pTemp1->pNext->pPrev = pTemp2;

    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1;

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