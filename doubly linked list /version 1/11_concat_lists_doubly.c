#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int iNo);
void Display(struct node *);
void ConcatLists(struct node **,struct node **);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst=NULL;
    struct node *pSecound=NULL;

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    InsertFirst(&pSecound,60);
    InsertFirst(&pSecound,50);
    InsertFirst(&pSecound,40);

    Display(pFirst);
    Display(pSecound);

    ConcatLists(&pFirst,&pSecound);
    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);

    return 0;
}
void ConcatLists(struct node **ppHead1,struct node **ppHead2)
{
    struct node *pTemp=NULL;

    if(NULL==*ppHead2)  //1st and 2nd scenario
        return;
    //surely 2nd list present
    if(NULL==*ppHead1)   //3rd scenario
    {
        *ppHead1=*ppHead2;
        *ppHead2=NULL;
        //2nd list becomes empty

        return;
    }
    //5th scenario

    pTemp=*ppHead1;  //point to first node of 1st list
    while(pTemp->pNext!=NULL)
        pTemp=pTemp->pNext;
    
    pTemp->pNext=*ppHead2;
    (*ppHead2)->pPrev=pTemp;
    *ppHead2=NULL;
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
