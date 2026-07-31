#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int iNo);
void Display(struct node *);
int DeleteFirst(struct node **);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst=NULL;

    InsertFirst(&pFirst,50);
    InsertFirst(&pFirst,60);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst);

    iDelData=DeleteFirst(&pFirst);
    printf("\nData of first Deleted node is:%d\n",iDelData);

    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);

    return 0;
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

void InsertFirst(struct node **ppHead,int iNo)
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