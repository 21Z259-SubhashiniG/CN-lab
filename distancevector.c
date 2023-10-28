#include<stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=1;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix :\n");
int flag = 0;
int count2 = 0;
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            rt[i].from[j]=j;
        }
    }
        while(count!=0)
        { flag = 0;
            count=0;
            for(i=0;i<nodes;i++)//We choose arbitary vertex k and we calculate the direct distance from the node i to k using the cost matrix
            //and add the distance from k to node j
            {
for(j=0;j<nodes;j++)
       {   for(k=0;k<nodes;k++)
{
       if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
       {//We calculate the minimum distance
           rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
           rt[i].from[j]=k;
flag = 1;
           count++;
       }
}
}
}
if ( count != 0)
{
printf("After %dth iteration\n", ++count2);
for(int i1=0;i1<nodes;i1++)
{
printf("\n\n For router %d\n",i1+1);
for(int j1=0;j1<nodes;j1++)
{
   printf("%d\t", rt[i1].dist[j1]);
}
printf("\n");
    }
printf("\n\n");
}
        }
    printf("\n\n");
return 0;
}

/*
input:

0 1 9999 9999 1 1
1 0 1 1 9999 1
9999 1 0 9999 9999 9999
9999 1 9999 0 9999 9999
1 9999 9999 9999 0 9999
1 1 9999 9999 9999 0 

*/