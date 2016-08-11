#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 100100;
int a[maxn];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		sort(a, a + n);
		int minCount = 0;
		int minAbs = 1 << 31 - 1;
		for(int i = 1; i < n; i++){
			if( a[i] - a[i - 1] < minAbs)
				minAbs = a[i] - a[i - 1];
		}
		if(minAbs == 0){
			
			int k = 1;
			while( k < n){
				int count = 1;
				while(k < n && a[k] == a[k-1]){
					count++;
					k++;
				}
				minCount += count * (count - 1) / 2;
				k++;
			}
			
		}else{
		
			for(int i = 1; i < n; i++){
				if(a[i] - a[i - 1] == minAbs)
					minCount ++;
			}
		
		}
		int maxCount;
		if( a[0] == a[n-1] )
			maxCount = minCount;
		else{
			int minNums = 1;
			int maxNums = 1;
			int i = 1;
			while( i < n && a[i] == a[i - 1]){
				minNums++;
				i++;
			}
			i = n - 2;
			while( i >= 0 && a[i] == a[i + 1]){
				maxNums++;
				i--;
			}
			
			maxCount = minNums * maxNums;
		}
		
		printf("%d %d\n", minCount, maxCount);
			
	} 
	return 0;
		
} 
