#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1000;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
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
