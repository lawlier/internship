#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<iostream>

using namespace std;

const int maxn = 100;

void merge(int a[], int l, int m, int r) 
{
	int i = l, j = m + 1, k = 0;
	int tmp[r - l + 1]; 
	while( i < m + 1 && j <= r)
		if(a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	if( i == m + 1 ){
		while( j <= r)
			tmp[k++] = a[j++];
	}else{
		while( i <= m)
			tmp[k++] = a[i++]; 
	} 
	for(int s = l; s <= r; s++)
		a[s] = tmp[s-l];
	
} 

void mergeSort(int a[], int l, int r)
{
	if( l >= r) 
		return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r); 
}

int a[maxn];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		mergeSort(a, 0, n - 1); 
		for(int i = 0; i < n; i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	
	return 0;
}

/*


*/
