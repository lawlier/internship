#include<stdio.h> 
#include<iostream>
#include<string.h>
#include<string>
#include<map>
#include<set>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;

const int maxn =  1000;

int partition(int a[], int l, int r)
{
	if(l >= r)
		return l;
	int i = l, j = r + 1;
	while(i < j){
		while( ++i < r + 1 && a[i] <= a[l])
			;
		while( --j > l && a[j] >= a[l])
			;
		if(i < j){
			swap(a[i], a[j]);
						
		}
	}
	swap(a[j], a[l]);
	return j;
}

void quickSort(int a[], int l, int r)
{
	if( l >= r)
		return;
	int m = partition(a, l, r);
	quickSort(a, l, m);
	quickSort(a, m + 1, r);
}

int a[maxn];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		quickSort(a, 0, n - 1); 
		for(int i = 0; i < n; i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	
	return 0;
}

/*
5
1 2 3 4 5
6
6 5 4 3 2 1
7
1 1 1 1 2 2 2
8
2 2 2 2 1 1 1 1
6
1 3 5 7 9 2 
5
-1 -22 -3 -3 -2 

*/
