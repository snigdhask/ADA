#include<stdio.h>
int dp[100][100];

int knapSack(int ind,int sum,int weight[],int profit[]){

    if(sum == 0) return 0;
    if(ind < 0) return 0;

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int take = -1e8;

    if(sum>=weight[ind]) take = profit[ind] + knapSack(ind-1,sum-weight[ind],weight,profit);

    int notTake = knapSack(ind-1, sum, weight, profit);

    return dp[ind][sum] = (take>=notTake)?take:notTake;
}

int main(){
    int n,size;
    printf("Enter no.of items (N) and size of the sack(M) \n");
    scanf("%d %d", &n, &size);

    int weight[n],profit[n];
    printf("Enter weight and profit : \n");
    for(int i=0;i<n;i++){
        scanf("%d %d", &weight[i], &profit[i]);
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j] = -1;
        }
    }
    printf("The maximum profit earned is %d\n", knapSack(n-1,size,weight,profit));
}
