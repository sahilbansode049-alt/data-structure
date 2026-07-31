#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void InsertAtFirst(struct node **,int iNo);
void Display(struct node *);
int DeleteLast(struct node **);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst=NULL;

    InsertAtFirst(&pFirst,50);
    InsertAtFirst(&pFirst,60);
    InsertAtFirst(&pFirst,40);
    InsertAtFirst(&pFirst,30);
    InsertAtFirst(&pFirst,20);
    InsertAtFirst(&pFirst,10);

    Display(pFirst);

    iDelData=DeleteLast(&pFirst);
    printf("\nData of Last Deleted node is:%d\n",iDelData);

    Display(pFirst);
    DeleteAll(pFirst);
    Display(pFirst);
    
    return 0;
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