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
int DeleteFirst(struct node **);
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

    iDelData=DeleteFirst(&pFirst);
    if(iDelData!=-1)
    {
        printf("\ndata of first deleted node is:%d\n\n",iDelData);
    }
    Display(pFirst);

    DeleteAll(&pFirst);
    Display(pFirst);
    
    return 0;
}
int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    if(NULL==*ppHead)
        return 0;
    iDelData=(*ppHead)->iData;

    if(NULL==(*ppHead)->pNext) //single node
    {
        free(*ppHead); //single node deleted
        *ppHead=NULL;   //list becomes Empty.
    }
    else
    {
        //(*ppHead)->pPrev->pNext=NULL;
        (*ppHead)=(*ppHead)->pNext;   //second node becomes first.
        free((*ppHead)->pPrev);  //old first deleted.
        (*ppHead)->pPrev=NULL;
    }
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
