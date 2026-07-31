#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node*);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst=NULL;  //list is empty

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst);
    ReverseDisplay(pFirst);
    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);

    return 0;
}
void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode=NULL;

    pNewNode=(struct node*)malloc(sizeof(struct node));
    if(NULL==pNewNode)
    {
        printf("\nMemory Allocation is failed.");
        return;
    }
    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;

    if(NULL==*ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead=pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;
    *ppHead=pNewNode;
    pNewNode=NULL;
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
void ReverseDisplay(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("\nlist is Empty.");
        return;
    }
    while(pHead->pNext!=NULL)
        pHead=pHead->pNext;

    while(pHead!=NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pPrev;
    }
    printf("NULL\n");
}
void DeleteAll(struct node **ppHead)
{
    struct node *pTemp=NULL;

    while(*ppHead!=NULL)
    {
        pTemp=*ppHead;
        *ppHead=pTemp->pNext;
        free(pTemp);
    }
}
