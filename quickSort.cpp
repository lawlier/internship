#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 9;

int partition(int a[], int l, int r){
	if( l >= r) return l;
	int tmp = a[l];
	int i = l;
	int j = r + 1;
	while( 1 ){
		while( ++i <= r && a[i] < a[l])
			;
		while( --j > l && a[j] > a[l] )
			;
		if( i >= j)
			break;		
		swap(a[i],a[j]);
	}
	swap(a[l], a[j]);
	return j;
}

void quickSort(int a[], int l, int r){
	if(l < r){
		int m = partition(a, l, r);
		quickSort(a, l, m);
		quickSort(a, m + 1, r); 
	}
}


int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void output(int a[], int l, int r, char msg[]){
	
	printf("%s\n", msg);
	for(int i = l; i <= r; i++)
		printf("%d ", a[i]);
	printf("\n");
} 

int main()
{
	
	char msg1[] = "ÅÅÐòÇ°:"; 
	char msg2[] = "ÅÅÐòºó:"; 
	output(b, 0, 9, msg1);
	quickSort(b, 0, 9);	
	output(b, 0, 9, msg2);
	return 0;
}
