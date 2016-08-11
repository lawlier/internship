#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int a[51];

void add(set<int> &own, int x){
	if(own.count(x) == 1)
		return;
	set<int>::iterator it;
	for(it = own.begin(); it != own.end(); it++){
		add(own, *it ^ x);
	}
	own.insert(x);
	return;
}

int main()
{
	int n;
	
	while(~scanf("%d",&n)){
		set<int> buy;
		set<int> own;
		set<int>::iterator it;
		int x;
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
		for(int i = 0; i < n; i++){
			if( i == 0 ){
				buy.insert(a[i]);
				own.insert(a[i]);
			}else{
				if(own.count(a[i]) == 0){
					add(own, a[i]);
					buy.insert(a[i]);
				}else{
					continue;	
				}
					
			}
		}
		printf("%d\n", buy.size());
	}
	return 0;	
} 
