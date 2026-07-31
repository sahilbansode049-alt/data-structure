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
int SearchAllOccurrence(struct node *,int);
void DeleteAll(struct node **);

int main(void)
{
    int iCount;
    struct node *pFirst=NULL;  //list is empty

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);
    InsertFirst(&pFirst,20);

    iCount=SearchAllOccurrences(pFirst,20);
    printf("\nAll position occurrence is:%d\n\n",iCount);

    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);

    return 0;
}
int SearchAllOccurrences(struct node *pHead,int iKey)
{
    int iCount=0;
    while(pHead!=NULL)
    {
        if(pHead->iData==iKey)
            iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
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
    printf("NULL");
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
