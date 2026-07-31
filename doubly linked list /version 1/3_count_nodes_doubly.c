#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};
int CountNodes(struct node *);
void InsertAtFirst(struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iCount;
    struct node *pFirst = NULL;

    InsertAtFirst(&pFirst, 10);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 30);
    InsertAtFirst(&pFirst, 40);

    iCount = CountNodes(pFirst);
    printf("\nNumber of nodes in list is:%d\n\n", iCount);

    Display(pFirst);

    DeleteAll(&pFirst);

    Display(pFirst);

    return 0;
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
void InsertAtFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    (*ppHead)->pPrev = pNewNode;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    pNewNode = NULL;
}
void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nlist is empty.");
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
