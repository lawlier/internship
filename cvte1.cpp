#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void find(int n){
	for(int i = 2; i <= n ; i++){
		int x = 0;
		int flag = ( 2 * n + i - i * i ) % ( 2 * i);
		if(flag == 0){
			x = (2 * n + i - i * i ) / ( 2 * i);
			 
		}
		if( x > 0){
			
			for(int j = 0; j < i; j++){
				printf("%d ",x + j);
			}
			printf("\n");
		}
		 
	}
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		find(n);
	} 
	return 0;	
} 
