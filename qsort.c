#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


int maxn = 1000;
int a[1000];

int cmp(int *x, int *y)
{
	return *x - *y;
}

int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF){
		for(i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		for(i = 0; i < n; i++)
			printf("%d ",&a[i]);
		printf("\n");
	} 
	return 0;
 } 
