#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 2010;

struct process{
	int start, time;
}a[maxn];

int cmp(process a, process b)
{
	if( a.start == b.start)
		return a.time < b.time;
	return a.start < b.start;
	
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
			scanf("%d%d", &a[i].start, &a[i].time);
		sort(a, a + n, cmp);
		int currentTime = 0;
		
		double ans = 0, sum = 0;
		
		for(int i = 0; i < n; i++){
			int waitingTime = 0;
			if(currentTime > a[i].start)
				waitingTime = currentTime - a[i].start;
			else
				currentTime = a[i].start;
			
			ans += waitingTime;
			
			currentTime += a[i].time;
		}
		printf("%.4lf\n", ans / n);		
	} 
	return 0;	
} 
