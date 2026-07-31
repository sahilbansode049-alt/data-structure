#include <stdio.h>
#include <stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, struct node **, int iNo);
void Display(struct node *, struct node *);
void InsertLast(struct node **, struct node **, int);
int DeleteFirst(struct node **, struct node **);
int DeleteLast(struct node **, struct node **);
void InsertAtposition(struct node **, struct node **, int, int);
int DeleteAtPosition(struct node **, struct node **, int);
int CountNodes(struct node *, struct node *);
int SearchFirstOccurrence(struct node *, struct node *, int);
int SearchLastOccurrence(struct node *, struct node *, int);
int SearchAllOccurrences(struct node *, struct node *, int);
void ConcateLists(struct node **, struct node **, struct node **, struct node **);
void ConcateAtposition(struct node **, struct node **,
                       struct node **, struct node **, int);
void PhysicalReverse(struct node **, struct node **);
void ReverseDisplay(struct node *, struct node *);
void DeleteAll(struct node **, struct node **);

int main(void)
{
    int iCount, iDelData;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;

    InsertFirst(&pFirst, &pLast, 30);
    InsertFirst(&pFirst, &pLast, 40);
    InsertFirst(&pFirst, &pLast, 30);
    InsertFirst(&pFirst, &pLast, 20);
    InsertFirst(&pFirst, &pLast, 10);

    Display(pFirst, pLast);

    InsertLast(&pFirst, &pLast, 50);
    InsertLast(&pFirst, &pLast, 60);
    InsertLast(&pFirst, &pLast, 70);

    Display(pFirst, pLast);
    iDelData = DeleteFirst(&pFirst, &pLast);
    if (iDelData != -1)
        printf("\nFirst node deleted data is %d\n", iDelData);
    Display(pFirst, pLast);

    iDelData = DeleteLast(&pFirst, &pLast);
    if (iDelData != -1)
        printf("\nlast node deleted data is %d\n", iDelData);
    Display(pFirst, pLast);

    InsertAtposition(&pFirst, &pLast, 70, 2);
    Display(pFirst, pLast);

    iDelData = DeleteAtPosition(&pFirst, &pLast, 2);
    if (iDelData != -1)
        printf("deleted node data %d\n", iDelData);

    iCount = CountNodes(pFirst, pLast);
    if (iCount != -1)
        printf("\nnumber of count node is %d\n", iCount);

    iCount = SearchFirstOccurrence(pFirst, pLast, 30);
    if (iCount != 0)
        printf("\nfirst %d found at %d position\n", 30, iCount);

    iCount = SearchLastOccurrence(pFirst, pLast, 30);
    if (iCount != 0)
        printf("\nlast %d found at %d position\n", 30, iCount);

    iCount = SearchAllOccurrences(pFirst, pLast, 30);
    if (iCount != 0)
        printf("\nall %d found %d time\n", 30, iCount);

    InsertLast(&pFirst1, &pLast1, 100);
    InsertLast(&pFirst1, &pLast1, 200);
    InsertLast(&pFirst1, &pLast1, 300);

    Display(pFirst1, pLast1);
    ConcateLists(&pFirst, &pLast, &pFirst1, &pLast1);
    Display(pFirst, pLast);

    ConcateAtposition(&pFirst, &pLast, &pFirst1, &pLast1, 3);
    Display(pFirst, pLast);

    printf("physically reverce function.\n");
    PhysicalReverse(&pFirst, &pLast);
    Display(pFirst, pLast);
    PhysicalReverse(&pFirst, &pLast);

    printf("only reverce function.\n");
    ReverseDisplay(pFirst, pLast);
    Display(pFirst, pLast);

    DeleteAll(&pFirst, &pLast);
    Display(pFirst, pLast);

    return 0;
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        // New node becomes first.
        *ppTail = pNewNode;
        // NewNode becomes last.
        (*ppTail)->pNext = *ppHead;
        // circular effect.
        return;
    }
    pNewNode->pNext = *ppHead;
    // old first becomes second
    *ppHead = pNewNode;
    // new node becomes last.
    (*ppTail)->pNext = *ppHead;
}

void Display(struct node *pHead, struct node *pTail)
{
    if (NULL == pHead)
    {
        printf("\nlist is empty");
        return;
    }

    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    printf("NULL\n");
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("\nmemmory allocation is failed.");
        return;
    }
    pNewNode->iData = iNo;
    // pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }

    (*ppTail)->pNext = pNewNode;

    *ppTail = pNewNode;
    (*ppTail)->pNext = *ppHead;
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData;

    if (NULL == *ppHead)
        return -1;

    iDelData = (*ppHead)->iData;
    if (*ppHead == *ppTail) // Single node
    {
        free(*ppHead); // single node delete
        *ppHead = *ppTail = NULL;
        // list becomes empty.
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        // 2nd node becomes first.
        free((*ppTail)->pNext);
        // old 1st is deleted
        (*ppTail)->pNext = *ppHead;
        // circular effect
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
    {
        return -1;
    }
    iDelData = (*ppTail)->iData;
    free(*ppTail); // last node deleted.

    if (*ppHead == *ppTail) // in single node case
    {
        *ppHead = *ppTail = NULL;
    }
    else
    {
        pTemp = *ppHead;
        while (pTemp->pNext != *ppTail)
            pTemp = pTemp->pNext;

        free(*ppTail);
        *ppTail = pTemp;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

void InsertAtposition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    int iCount;
    iCount = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nInvalid input");
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(ppHead, ppTail, iNo);
        return;
    }
    /*if(iPos==iCount+1)
    {
        InsertLast(ppHead,ppTail,iNo);
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

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    int iCount;
    iCount = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCount)
        return -1;

    if (iPos == -1)
        return DeleteFirst(ppHead, ppTail);

    // if(iPos==iCount)
    // return DeleteLast(ppHead,ppTail);

    pTemp1 = *ppHead;
    iCount = 1;
    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = pTemp1->pNext;

    pTemp1->pNext = pTemp2->pNext;
    iCount = pTemp2->iData;
    free(pTemp2);

    return iCount;
}

int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCounter = 0;
    if (NULL == pHead)
        return 0;

    do
    {
        iCounter++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCounter;
}

int SearchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPos = 0;
    if (NULL == pHead)
        return 0;

    do
    {
        ++iPos;
        if (pHead->iData == iKey)
            return iPos;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return 0; // if list empty.
}

int SearchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        ++iPos;
        if (pHead->iData == iKey)
            iLastPos = iPos;

        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iLastPos;
}

int SearchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCount = 0;
    if (NULL == pHead)
        return 0;

    do
    {
        if (pHead->iData == iKey)
            iCount++;
        pHead = pHead->pNext;

    } while (pHead != pTail->pNext);

    return iCount;
}

void ConcateLists(struct node **ppHead1, struct node **ppTail1,
                  struct node **ppHead2, struct node **ppTail2)
{
    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }
    (*ppTail1)->pNext = *ppHead2;
    *ppTail1 = *ppTail2;
    // last node of 1st list becomes last node of 1st list.

    (*ppTail1)->pNext = *ppHead1;
    *ppHead2 = *ppTail2 = NULL;
}

void ConcateAtposition(struct node **ppHead1, struct node **ppTail1,
                       struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead1, *ppTail1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nposition is invalid");
        return;
    }

    if (*ppHead2 == NULL)
        return;

    if (iPos == 1)
    {
        // ConcateLists(ppHead1, ppTail1, ppHead2, ppTail2);
        return;
    }

    pTemp = *ppHead1;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext = *ppHead2;

    if (pTemp == *ppTail1)
    {
        *ppTail1 = *ppTail2;
    }

    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = NULL;
    *ppTail2 = NULL;
}

void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if (NULL == *ppHead)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    } while (pCurrent != *ppHead);

    *ppTail = *ppHead;
    *ppHead = pPrev;
}

void ReverseDisplay(struct node *pHead, struct node *pTail)
{
    if (NULL == pHead)
    {
        printf("\nlist is empty.");
        return;
    }
    PhysicalReverse(&pHead, &pTail);
    Display(pHead, pTail);
    PhysicalReverse(&pHead, &pTail);
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;

    (*ppTail)->pNext = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    *ppTail = NULL;
}