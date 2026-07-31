#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int iData;
    struct node *pNext;
};

void InsertAtFirst(struct node **,int iNo);
void Display(struct node *);
int SearchFirstOccurrence(struct node *,int );
void DeleteAll(struct node **);

int main(void)
{
    int iPos;
    struct node *pFirst=NULL;

    InsertAtFirst(&pFirst,10);
    InsertAtFirst(&pFirst,20);
    InsertAtFirst(&pFirst,30);
    InsertAtFirst(&pFirst,20);
    InsertAtFirst(&pFirst,40);
    InsertAtFirst(&pFirst,50);
    InsertAtFirst(&pFirst,60);

    iPos=SearchFirstOccurrence(pFirst,20);
    printf("\nFirst postion occurrence is:%d\n\n",iPos);

    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
    
    return 0;
}
int SearchFirstOccurrence(struct node *pHead,int iKey)
{
    int iPos=0;
    while(pHead!=NULL)
    {
        ++iPos;
        if(pHead->iData==iKey)
            return iPos;
        pHead=pHead->pNext;
    }
    return 0;
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