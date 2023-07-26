#include<stdio.h>
#include<stdlib.h>

int main()
{
int n;
printf("enter number of nodes \n");
scanf("%d",&n);
int graph[n+1][n+1],dist[n+1][n+1];

for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
    if(i!=j)
    {
    printf(" 1.enter weight if edge exists \n or \n 0.no edge \n  %d ---> %d\n",i,j);
       int ch;
        scanf("%d",&ch);
if(ch==0)
    {
dist[i][j]=10000;
graph[i][j]=-1;
    }else{
dist[i][j]=ch;
graph[i][j]=1;
  }
}
else{
   dist[i][j]=0;
graph[i][j]=1;
}
}
}
for(int k=1;k<=n;k++)
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(graph[i][k]==1 && graph[k][j]==1 && dist[i][j]>(dist[i][k]+dist[k][j]))
{
dist[i][j]=(dist[i][k]+dist[k][j]);
}
}
}
}
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(dist[i][j]!=10000)
{
    if(i!=j)
    {
printf("The shortest distance between %d and %d is %d \n",i,j,dist[i][j]);
  }
}else{
printf("No edge  between %d and %d  \n",i,j);
}

}
}

}
