#include<stdio.h>
#include<malloc.h>
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};
void Push(struct node **,int);
int Pop(struct node **);
void Display(struct node*);
int IsFull(struct node *);
int IsEmpty(struct node *);
int CountNodes(struct node *);

int main(void)
{
    struct node *pStack=NULL;

    Push(&pStack,10);
    Push(&pStack,20);
    Push(&pStack,30);

    Display(pStack);

    printf("\nPopped element is %d\n",Pop(&pStack));

    Display(pStack);

    return 0;
}
void Push(struct node **ppHead,int iNo)
{
    struct node *pNewNode=NULL;
    if(IsFull(*ppHead))
    {
        printf("\nStack is overflow");
        return;
    }

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
int Pop(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp=NULL;
    if(IsEmpty(*ppHead))
    {
        printf("\nstack is overflow");
        return -1;
    }

    if(NULL==*ppHead)
        return 0;

    pTemp=*ppHead;   
    *ppHead=pTemp->pNext;    
    iDelData=pTemp->iData;

    free(pTemp);

    return iDelData;
}
int IsFull(struct node *pHead)
{
    if(CountNodes(pHead)==MAX)
        return 1;
    return 0;
}
int IsEmpty(struct node *pHead)
{
    if(NULL==pHead)
        return 1;
    return 0;
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