#include <stdio.h>
#include <stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};

void InsertAtFirst(struct node **, int iNo);
void Display(struct node *);
void ConcateLists(struct node **ppHead, struct node **ppHead2);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecound = NULL;

    InsertAtFirst(&pFirst, 10);
    InsertAtFirst(&pFirst, 20);
    InsertAtFirst(&pFirst, 30);

    InsertAtFirst(&pSecound, 40);
    InsertAtFirst(&pSecound, 50);
    InsertAtFirst(&pSecound, 60);

    ConcateLists(&pFirst, &pSecound);
    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);

    return 0;
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
void InsertAtFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (pNewNode == NULL)
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