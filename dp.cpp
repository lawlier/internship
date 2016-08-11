#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int solve(int a[], int n, int target)
{
	int dp[target + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= target; j++)
			if(a[i] <= j)
				dp[j] = dp[j] + dp[j - a[i]];
	}
	return dp[target];
}

int main()
{
	int n, a[100];
	while(scanf("%d",&n)!=EOF){
		int target;
		scanf("%d",&target);
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int ans = solve(a, n, target);
		printf("%d\n",ans);
	} 
	return 0;	
} 
