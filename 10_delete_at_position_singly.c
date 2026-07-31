#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void InsertAtFirst(struct node **,int iNo);
void Display(struct node *);
int DeleteAtPosition(struct node**,int);
int DeleteFirst(struct node**);
int DeleteLast(struct node**);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst=NULL;

    InsertAtFirst(&pFirst,10);
    InsertAtFirst(&pFirst,20);
    InsertAtFirst(&pFirst,30);
    InsertAtFirst(&pFirst,20);
    InsertAtFirst(&pFirst,40);
    InsertAtFirst(&pFirst,50);
    InsertAtFirst(&pFirst,60);

    Display(pFirst);

    iDelData=DeleteAtPosition(&pFirst,3);
    printf("\nDeleted data at position is:%d",iDelData);

    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);
    
    return 0;
}
int DeleteAtPosition(struct node **ppHead,int iPos)
{
    struct node *pTemp1=NULL;
    struct node *pTemp2=NULL;
    int iCount;
    iCount=CountNodes(*ppHead);

    if(iPos<=0 ||iPos>iCount)
        return -1;

    if(iPos==-1)
    return DeleteFirst(ppHead);
    //if(iPos==iCount)
    //return DeleteLast(ppHead);

    //position between tow nodes

    pTemp1=*ppHead;
    iCount=1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }

    pTemp2=pTemp1->pNext;   //pointing to deleting node

    pTemp1->pNext=pTemp2->pNext;
    iCount=pTemp2->iData;
    free(pTemp2);

    return iCount;
}
int CountNodes(struct node *pHead)
{
    int iCount=0;

    if(NULL==pHead)
        return 0;

    while(pHead!=NULL)
    {
        iCount++;
        pHead=pHead->pNext;
    }
    return iCount;
}

void InsertAtFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode=NULL;

    pNewNode=(struct node*)malloc(sizeof(struct node));

    pNewNode->iData=iNo;

    if(NULL==*ppHead)
    {
        pNewNode->pNext=NULL;
        *ppHead=pNewNode;
        return;
    }
    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp=NULL;

    if(NULL==*ppHead)
        return 0;

    pTemp=*ppHead;   //pointing to deleting node
    *ppHead=pTemp->pNext;    //pointing second node becomes first
    iDelData=pTemp->iData;
    //pTemp->pNext=NULL;

    free(pTemp);

    return iDelData;
}
int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp=NULL;

    if(NULL==*ppHead)
    {
        return -1;
    }
    pTemp=*ppHead;      //pointing to first node

    if(NULL==pTemp->pNext)    //only one node
    {
        iDelData=pTemp->iData;
        free(pTemp);   //one node deleted
        *ppHead=NULL;    //list becomes empty
    }
    else
    {
        while(pTemp->pNext->pNext!=NULL)   //will point to second last node
            pTemp=pTemp->pNext;
        
        iDelData=pTemp->pNext->iData;
        free(pTemp->pNext);  //last node deleted.
        pTemp->pNext=NULL;  //second last node becomes last
    }
    return iDelData;
}

void Display(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("\nlist is empty");
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
    struct node *pTemp = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
}