#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std; 

const int MAX_LEN = 1100;

int dp[MAX_LEN][MAX_LEN];

int main()
{
	char str[MAX_LEN], ptr[MAX_LEN];
	while(scanf("%s",str) != EOF){
		int len = strlen(str);
		for(int i = 0; i < len; i++)
			ptr[len - i - 1] = str[i];
			
		ptr[len] = '\0';
		
		memset(dp, 0, sizeof(dp));
	
		for(int i = 1; i <= len; i ++){
			
			for(int j = 1; j <= len; j++){
				if(str[i - 1] == ptr[j - 1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n",len -  dp[len][ len]  );		
	} 
	return 0;
}
