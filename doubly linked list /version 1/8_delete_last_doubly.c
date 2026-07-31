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
int DeleteLast(struct node **);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst=NULL;  //list is empty

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);
    InsertFirst(&pFirst,60);

    Display(pFirst);

    iDelData=DeleteLast(&pFirst);
    if(iDelData!=-1)
        printf("\ndata of Last deleted node is:%d\n\n",iDelData);

    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);
    
    return 0;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp=NULL;

    if(NULL==*ppHead)
        return 0;
    pTemp=*ppHead;  //point to first node

    if(NULL==pTemp->pNext)   //only one node
        *ppHead=NULL;
    else
    {
        while(pTemp->pNext!=NULL)
            pTemp=pTemp->pNext;

        pTemp->pPrev->pNext=NULL;   //secong last becomes last
    }
    iDelData=pTemp->iData;
    free(pTemp);
    
    return iDelData;
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
