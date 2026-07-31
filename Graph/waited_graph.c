#include <stdio.h>
#define MAX 4

int main(void)
{
    int iCounter1, iCounter3, iCounter2, iVert, iAdjvert, iAdj,iWeight;
    int iArr[MAX] = {0};
    int iGraph[MAX][MAX] = {0};
    int iWaight[MAX][MAX] = {0};

    printf("\nEnter number for vertices you want but <%d:", MAX);
    scanf("%d", &iVert);

    for (iCounter1 = 0; iCounter1 < iVert; iCounter1++)
    {
        printf("\nEnter %d vertex:", iCounter1 + 1);
        scanf("%d", &iArr[iCounter1]);
    }

    for (iCounter1 = 0; iCounter1 < iVert; iCounter1++)
    {
        printf("\nEnter num of Adjacent vertices for %d:", iArr[iCounter1]);
        scanf("%d", &iAdjvert);

        for (iCounter2 = 0; iCounter2 < iAdjvert; iCounter2++)
        {
            printf("\nEnter %d adjacent vertices:", iCounter2 + 1);
            scanf("%d", &iAdj);
            printf("\nEnter waiht for %d to %d:", iArr[iCounter1],iAdj);
            scanf("%d", &iWeight);
            for (iCounter3 = 0; iCounter3 < iVert; iCounter3++)
            {
                if (iArr[iCounter3] == iAdj)
                {
                    iGraph[iCounter1][iCounter3] = iAdj;
                    iWaight[iCounter1][iCounter3]=iWeight;
                    break;
                }
            }
        }
    }

    printf("\nGraph is:");
    for (iCounter1 = 0; iCounter1 < iVert; iCounter1++)
    {
        printf("\n%d=", iArr[iCounter1]);
        for (iCounter2 = 0; iCounter2 < iVert; iCounter2++)
        {
            if (iGraph[iCounter1][iCounter2] != 0)
            {
                printf("%d(%d)->", iGraph[iCounter1][iCounter2],iWaight[iCounter1][iCounter2]);
            }
        }
    }
}
