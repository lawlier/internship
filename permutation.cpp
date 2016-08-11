#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int x, n;
	int vis[21];
	while(scanf("%d%d", &x, &n)!=EOF){
		memset(vis, 0, sizeof(vis));
		int current = x;
		vis[x] = 1;
		for(int i = 1; i <= n; i++){
			current = (current + i) % 20 + 1;
			vis[current]++;
		}
		int flag = 1;
		for(int i = 1; i <= 20; i++){
			if(vis[i] == 0 && flag){
				printf("%d", i);
				flag = 0;
			}else if(vis[i] == 0){
				printf(" %d", i);
			}
		}
        if(flag)
            printf("-1\n");
        else
			printf("\n"); 
		
	} 
	return 0;
}
