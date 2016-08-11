#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


const int maxn = 1000;
int a[maxn];

int cmp(int *x, int *y)
{
	return *x - *y;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		for(int i = 0; i < n; i++)
			printf("%d ",&a[i]);
		printf("\n");
	} 
	return 0;
 } 
