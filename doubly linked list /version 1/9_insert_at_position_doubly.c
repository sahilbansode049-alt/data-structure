#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};
void InsertAtposition(struct node**,int,int);
void Display(struct node*);
int CountNodes(struct node*);
void InsertFirst(struct node**,int);
void InsertLast(struct node**,int);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst=NULL;

    InsertFirst(&pFirst,50);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst);

    InsertAtposition(&pFirst,60,3);

    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);
    
    return 0;
}
void InsertAtposition(struct node **ppHead,int iNo,int iPos)
{
    struct node *pTemp=NULL;
    struct node *pNewNode=NULL;
    int iCount;
    iCount=CountNodes(*ppHead);

    if(iPos<=0 || iPos>iCount+1)
    {
        printf("\nInvalid input");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    /*if(iPos==iCount+1)
    {
        InsertLast(ppHead,iNo);
        return;
    }*/

    pNewNode=(struct node*)malloc(sizeof(struct node));

    if(NULL==pNewNode)
    {
        printf("\nMemopry allocation is failed");
        return;
    }

    pNewNode->iData=iNo;

    pTemp=*ppHead;
    iCount=1;
    while(iCount<iPos-1)   
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    if(pTemp->pNext!=NULL)
        pNewNode->pNext=pTemp->pNext;
    pTemp->pNext->pPrev=pNewNode;
    
    pTemp->pNext=pNewNode;
    pNewNode->pPrev=pTemp;
}
int CountNodes(struct node *pHead)
{
    int iCount=0;
    while(pHead!=NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;   
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
