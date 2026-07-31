#include<stdio.h>
#include<stdlib.h>
struct node
{
    int iData;
    struct node *pNext;
};
void InsertLast(struct node **ppHead,int iNo);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst=NULL;
    InsertLast(&pFirst,10);
    InsertLast(&pFirst,20);
    InsertLast(&pFirst,30);

    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
    return 0;
}
void InsertLast(struct node **ppHead,int iNo)
{
    struct node *pTemp=NULL;
    struct node *pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

    pNewNode->iData=iNo;
    pNewNode->pNext=NULL;

    if(NULL==*ppHead)
    {
        *ppHead=pNewNode;  //last as well as first node
        return;
    }

    pTemp=*ppHead;   //pointing to first node

    while(pTemp->pNext!=NULL)
        pTemp=pTemp->pNext;
    
    pTemp->pNext=pNewNode;

}

void Display(struct node *pHead)
{
    if(NULL==pHead)
    {
        printf("\nList is Empty");
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