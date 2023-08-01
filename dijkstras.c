#include<stdio.h>
#include<conio.h>
int graph[10][10];
int cost[10][10];
int main()
{
	int n;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("1.Enter edge value if edge exists\n 0.no edge \n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				int val;
				printf("%d --> %d  ",i,j);
				scanf("%d",&val);
				printf("\n");
				graph[i][j]=1;
				cost[i][j]=val;
				if(val==0)
				{
					graph[i][j]=-1;
					cost[i][j]=1000;
				}
			}else{
				graph[i][j]=0;
				cost[i][j]=0;
			}
		}
	}
	int src;
	printf("Enter source vertex\n");
	scanf("%d",&src);
	
	int dist[n+1],vis[n+1];
	int edges[n+1][n+1];
	int k=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		if(graph[src][i]!=1000)
		{
			dist[i]=cost[src][i];
		}
	}
	dist[src]=0;
	vis[src]=1;
	int cnt=1,u;
	while(cnt<n)
	{
		int min=1000;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i] && dist[i]<min)
			{
				u=i;
				min=dist[i];
			}
		}
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]>(cost[u][i]+dist[u]) && !vis[i] )
			{
				dist[i]=(cost[u][i]+dist[u]);
			}
		}
		cnt++;
		printf("%d --> %d is %d  \n",src,u,dist[u]);
		
	}
	
	
}
