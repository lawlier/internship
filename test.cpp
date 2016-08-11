#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100;
int a[maxn];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n;i++)
			scanf("%d",&a[i]);
		int max = INT_MIN;
		int min = INT_MAX;
		
		for(int i = 0; i < n;i++){
			if(a[i] > max)
				max = a[i];
			if(a[i] < min)
				min = a[i];
				
		}
		cout << max - min << endl;
			 
	}	 
	return 0;	
} 
