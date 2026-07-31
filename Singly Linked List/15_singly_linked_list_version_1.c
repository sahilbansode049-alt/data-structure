#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int iNo);
void Display(struct node *);
void InsertLast(struct node **ppHead, int iNo);
int CountNodes(struct node *pHead);
int SearchFirstOccurrence(struct node *, int);
int SearchLastOccurrence(struct node *, int iNo);
int SearchAllOccurrences(struct node *, int iNo);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
void InsertAtPosition(struct node **, int, int);
int DeleteAtPosition(struct node **, int);
void ConcateAtposition(struct node **, struct node **, int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);
void ConcateLists(struct node **, struct node **);

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
        printf("\nDeleted data is %d\n", iData); // 10

    Display(pFirst); // 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if (iData != -1)
        printf("\nDeleted data is %d\n", iData); // 60

    Display(pFirst); // 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst, 4);
    if (iData != -1)
        printf("\nDeleted data is %d\n", iData); // 40

    Display(pFirst); // 20 30 20 50

    iData = SearchFirstOccurrence(pFirst, 20);
    if (iData != 0)
        printf("\nFirst occurrence of %d is at %d position", 20, iData); // 1

    iData = SearchLastOccurrence(pFirst, 20);
    if (iData != 0)
        printf("\nLast occurrence of %d is at %d position", 20, iData); // 3

    iData = SearchAllOccurrences(pFirst, 20);
    printf("\n%d found %d times", 20, iData); // 2

    iData = CountNodes(pFirst);
    printf("\nTotal node count is %d\n", iData); // 4

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
    ConcateLists(&pFirst, &pSecond);
    Display(pFirst);  // 20 30 20 50 100 200 300
    Display(pSecond); // List is empty

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);

    Display(pFirst);  // 20 30 20 50 100 200 300
    Display(pSecond); // 400 500 600
    ConcateAtposition(&pFirst, &pSecond, 4);
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
void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("Memory allocation failed\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
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
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    iDelData = pTemp->iData;
    // pTemp->pNext=NULL;

    free(pTemp);

    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
    {
        return -1;
    }
    pTemp = *ppHead;

    if (NULL == pTemp->pNext)
    {
        iDelData = pTemp->iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else
    {
        while (pTemp->pNext->pNext != NULL)
            pTemp = pTemp->pNext;

        iDelData = pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }
    return iDelData;
}
int DeleteAtPosition(struct node **ppHead, int iPos)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    int iCount;
    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
        return -1;

    if (iPos == 1)
        return DeleteFirst(ppHead);
    // if(iPos==iCount)
    // return DeleteLast(ppHead);

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
int SearchFirstOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0;
    while (pHead != NULL)
    {
        ++iPos;
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
        ++iPos;
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
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}
void ConcateLists(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2) // 1st and 2nd scenario
        return;
    // surely 2nd list present
    if (NULL == *ppHead1) // 3rd scenario
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        // 2nd list becomes empty

        return;
    }
    // 5th scenario

    pTemp = *ppHead1; // point to first node of 1st list
    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL; // 2nd list becomes empty
}

void ReverseDisplay(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nlist is Empty.");
        return;
    }
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
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