#include <stdlib.h>
#include <stdio.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};
void InsertFirst(struct node **, struct node **, int);
void Display(struct node *, struct node *);
void DeleteAll(struct node **, struct node **);
void InsertLast(struct node **, struct node **, int);
int CountNodes(struct node *, struct node *);
int SearchFirstOccurrence(struct node *, struct node *, int);
int SearchLastOccurrence(struct node *, struct node *, int);
int SearchAllOccurrences(struct node *, struct node *, int);
int DeleteFirst(struct node **, struct node **);
int DeleteLast(struct node **, struct node **);
void InsertAtposition(struct node **, struct node **, int, int);
int DeleteAtPosition(struct node **, struct node **, int);
void ConcatLists(struct node **, struct node **, struct node **, struct node **);
void ConcateAtposition(struct node **,struct node **,struct node **,struct node **,int );
void PhysicalReverse(struct node **,struct node **);
void ReverseDisplay(struct node *,struct node *);

int main(void)
{
    int iCount, iDelData;

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;
    struct node *pFirst1 = NULL;
    struct node *pSecond1 = NULL;

    InsertFirst(&pFirst, &pSecond, 50);
    InsertFirst(&pFirst, &pSecond, 40);
    InsertFirst(&pFirst, &pSecond, 30);
    InsertFirst(&pFirst, &pSecond, 20);
    InsertFirst(&pFirst, &pSecond, 10);

    Display(pFirst, pSecond);

    InsertLast(&pFirst, &pSecond, 60);
    InsertLast(&pFirst, &pSecond, 60);
    InsertLast(&pFirst, &pSecond, 70);
    InsertLast(&pFirst, &pSecond, 80);

    Display(pFirst, pSecond);

    iCount = CountNodes(pFirst, pSecond);
    if (iCount != 0)
        printf("%d Nodes are present.\n", iCount);

    iCount = SearchFirstOccurrence(pFirst, pSecond, 60);
    if (iCount != 0)
        printf("%d found %d first occurence.\n", 60, iCount);

    iCount = SearchLastOccurrence(pFirst, pSecond, 60);
    if (iCount != 0)
        printf("%d found %d Last occurence.\n", 60, iCount);

    iCount = SearchAllOccurrences(pFirst, pSecond, 60);
    if (iCount != 0)
        printf("%d found %d times All occurence.\n", 60, iCount);

    iDelData = DeleteFirst(&pFirst, &pSecond);
    if (iDelData != 0)
        printf("First node delete its data %d.\n", iDelData);
    Display(pFirst, pSecond);

    iDelData = DeleteLast(&pFirst, &pSecond);
    if (iDelData != 0)
        printf("First node delete its data %d.\n", iDelData);
    Display(pFirst, pSecond);

    InsertAtposition(&pFirst, &pSecond, 100, 5);
    Display(pFirst, pSecond);

    DeleteAtPosition(&pFirst, &pSecond, 5);
    Display(pFirst, pSecond);

    InsertFirst(&pFirst1, &pSecond1, 400);
    InsertFirst(&pFirst1, &pSecond1, 300);
    InsertFirst(&pFirst1, &pSecond1, 200);
    InsertFirst(&pFirst1, &pSecond1, 100);

    ConcatLists(&pFirst, &pSecond, &pFirst1, &pSecond1);
    Display(pFirst, pSecond);

    ConcateAtposition(&pFirst, &pSecond, &pFirst1, &pSecond1,3);
    Display(pFirst, pSecond);

    PhysicalReverse(&pFirst, &pSecond);
    Display(pFirst, pSecond);
    PhysicalReverse(&pFirst, &pSecond);

    ReverseDisplay(pFirst, pSecond);
    Display(pFirst, pSecond);

    DeleteAll(&pFirst, &pSecond);
    Display(pFirst, pSecond);

    return 0;
}
void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    pNewNode->pPrev = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;

        // circular effect (doubly)
        (*ppHead)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppHead;

        return;
    }

    // insert at first
    pNewNode->pNext = *ppHead;
    pNewNode->pPrev = *ppTail;

    (*ppHead)->pPrev = pNewNode;
    (*ppTail)->pNext = pNewNode;

    *ppHead = pNewNode;
}
void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->pNext = NULL;
    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        pNewNode->pPrev = pNewNode;
        pNewNode->pNext = pNewNode;
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while (pTemp->pNext != *ppHead && pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;

    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;

    *ppTail = pNewNode;
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
int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if (pHead == NULL)
    {
        return 0;
    }
    do
    {
        iCount++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCount;
}
int SearchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPos = 0;
    if (pHead == NULL)
    {
        return 0;
    }
    do
    {
        iPos++;
        if (pHead->iData == iKey)
            return iPos;

        pHead = pHead->pNext;

    } while (pHead != pTail->pNext);

    return 0;
}
int SearchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    if (pHead == NULL)
    {
        return 0;
    }

    do
    {
        iPos++;
        if (pHead->iData == iKey)
            iLastPos = iPos;

        pHead = pHead->pNext;

    } while (pHead != pTail->pNext);

    if (iLastPos == 0)
        return 0;
    else
        return iLastPos;
}
int SearchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCount = 0;

    if (pHead == NULL)
    {
        return 0;
    }

    do
    {
        if (pHead->iData == iKey)
            iCount++;

        pHead = pHead->pNext;

    } while (pHead != pTail->pNext);

    return iCount;
}
int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData;

    if (NULL == *ppHead)
        return 0;

    iDelData = (*ppHead)->iData;

    if ((*ppHead) == (*ppTail)) // when single node then
    {
        free(*ppHead);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        (*ppHead) = (*ppHead)->pNext; // second node becomes first
        free((*ppHead)->pPrev);       // old first deleted

        (*ppHead)->pPrev = *ppTail; // circular effetc
        (*ppTail)->pNext = *ppHead; // circular effect
    }
    return iDelData;
}
int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return 0;

    pTemp = *ppTail; // directy point to lasts node

    iDelData = pTemp->iData;

    if (*ppHead == *ppTail) // only one node present then
    {
        free(pTemp);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        *ppTail = pTemp->pPrev;
        (*ppTail)->pNext = *ppHead; // circular effect
        (*ppHead)->pPrev = *ppTail; // circular effect

        free(pTemp);
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

    /* if(iPos==iCount+1)
     {
         InsertLast(ppHead,ppTail,iNo);
         return;
     }*/

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("\nMemory allocation is failed");
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
    pTemp->pNext->pPrev = pNewNode;

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;

    if (pNewNode->pNext == *ppHead)
    {
        *ppTail = pNewNode;
        (*ppHead)->pPrev = *ppTail;
    }
}
int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    struct node *pTemp = NULL;
    int iCount;
    int iDelData;

    iCount = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCount)
        return -1;

    if (iPos == 1)
        return DeleteFirst(ppHead, ppTail);

    /*if(iPos==iCount)
        return DeleteLast(ppHead,ppTail);
    */

    // position between two nodes

    pTemp = *ppHead;
    iCount = 1;

    while (iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pTemp->pPrev;

    iDelData = pTemp->iData;
    free(pTemp);

    return iDelData;
}
void ConcatLists(struct node **ppHead1, struct node **ppTail1,
                 struct node **ppHead2, struct node **ppTail2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2) // 1st and 2nd scenario
        return;

    // if first list is empty
    if (NULL == *ppHead1) // 3rd scenario
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = NULL;
        *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;

    (*ppTail2)->pNext = *ppHead1;
    (*ppHead1)->pPrev = *ppTail2;

    *ppTail1 = *ppTail2;
    *ppHead2 = *ppTail2 = NULL;
}

void ConcateAtposition(struct node **ppHead1,struct node **ppTail1,
    struct node **ppHead2,struct node **ppTail2,int iPos)
{
    int iCount;
    struct node *pTemp1=NULL;
    struct node *pTemp2=NULL;

    iCount=CountNodes(*ppHead1,*ppTail1);

    if(iPos<=0 || iPos>iCount+1)
    {
        printf("\nposition is invalid");
        return;
    }

    if(NULL==*ppHead2)
        return;

    // if first list empty
    if(NULL==*ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    if(iPos==1)
    {
        ConcatLists(ppHead2,ppTail2,ppHead1,ppTail1);
        *ppHead1=*ppHead2;
        *ppTail1=*ppTail2;

        *ppHead2=NULL;
        *ppTail2=NULL;
        return;
    }
    /*if(iPos==iCount+1)
    {
        ConcateLists(ppHead1,ppHead2);
        return;
    }*/

    pTemp1=*ppHead1;
    iCount=1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }

    pTemp2=*ppTail2;

    pTemp2->pNext=pTemp1->pNext;
    pTemp1->pNext->pPrev=pTemp2;

    pTemp1->pNext=*ppHead2;
    (*ppHead2)->pPrev=pTemp1;

    (*ppTail2)->pNext=*ppHead1;
    (*ppHead1)->pPrev=*ppTail2;

    *ppTail1 = *ppTail2;

    *ppHead2 = NULL;
    *ppTail2 = NULL;

    (*ppTail1)->pNext = *ppHead1;
    (*ppHead1)->pPrev = *ppTail1;
}
void PhysicalReverse(struct node **ppHead,struct node **ppTail)
{
    struct node *pPrev=NULL;
    struct node *pCurrent=NULL;
    struct node *pNext=NULL;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
        return;

    pCurrent = *ppHead;

    do
    {
        pNext = pCurrent->pNext;

        pCurrent->pNext = pPrev;
        pCurrent->pPrev = pNext;

        pPrev = pCurrent;
        pCurrent = pNext;

    } while(pCurrent != *ppHead);

    pTemp = *ppHead;
    *ppHead = *ppTail;
    *ppTail = pTemp;

    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;
}
void ReverseDisplay(struct node *pHead,struct node *pTail)
{
    if(NULL==pHead)
    {
        printf("\nlist is Empty.");
        return;
    }

    pHead = pTail;

    do
    {
        printf("|%d|->",pHead->iData);
        pHead = pHead->pPrev;

    } while(pHead != pTail);

    printf("|%d|->NULL\n",pTail->iData);
}