#include <stdio.h>
#include <stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertAtFirst(struct node **, int iNo);
void Display(struct node *);
void PhysicalReverse(struct node **);
void DeleteAll(struct node **);
int main(void)
{
    struct node *pFirst = NULL;

    InsertAtFirst(&pFirst, 10);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 30);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 40);
    InsertAtFirst(&pFirst, 50);
    InsertAtFirst(&pFirst, 60);

    Display(pFirst);

    PhysicalReverse(&pFirst);

    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);

    return 0;
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
        pCurrent = pPrev;
    }
    *ppHead = pPrev;
} 
void InsertAtFirst(struct node **ppHead,int iNo)
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