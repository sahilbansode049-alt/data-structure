#include<stdio.h>
#include<stdlib.h>
struct edge;
struct vertex
{
    struct vertex *pNextVertex;;
    int iData;
    struct edge *pAdjecent;
};
struct edge
{
    struct vertex *pAdjVertex;
    struct edge *pNextEdge;
};

int main(void)
{
    int iVertex,iAdjVertex;
    struct node *pVertex=NULL;
    struct node *pEdge=NULL;

    while(1)
    {
        printf("\nEnter the vertex:");
        scanf("%d",&iVertex);

        printf("\nEnter the Adjacent vertex for %d:",iVertex);
        scanf("%d",&iAdjVertex);

        InsertVertex(&pVertex,iVertex);
        InsertAdj(&pVertex,&pEdge,&iAdjVertex);

    }
}
void InsertVertex(struct node **ppHead,int iNo)
{
    struct vertex *pNewNode=NULL;

    pNewNode=(struct vertex**)malloc(sizeof(struct vertex));

    if(NULL==pNewNode)
    {
        printf("\nmemory allocation is failed.");
        return;
    }
    pNewNode=*ppHead;
    if(*ppHead==NULL)
    {
        pNewNode->pNextVertex=NULL;
        pNewNode->iData=iNo;
        pNewNode->pAdjecent=NULL;

        *ppHead=pNewNode;
    }
    

}