#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 1000;
char str[maxn];

int main()
{
	int n;
	
	while(scanf("%d", &n) != EOF){
		multiset<char> s;
		multiset<char> e;
		multiset<char> ss;
		multiset<char>::iterator it, deleteItem;
		for(int i = 0; i < n; i++){
			scanf("%s", str);
			int len = strlen(str);
			if(str[0] != str[len - 1]){
				s.insert(str[0]);
				e.insert(str[len - 1]);
			}else{
				ss.insert(str[0]);
			}
		}
		for(it = ss.begin(); it != ss.end(); )
		{
			if(s.count(*it)){
				deleteItem = it;
				it++;
				ss.erase(deleteItem);
			}else if(e.count(*it)){
				deleteItem = it;
				it++;
				ss.erase(deleteItem);
			}else{
				it++;
			}
			
		}
		for(it = s.begin(); it != s.end();){
			deleteItem = e.lower_bound(*it);
			if(deleteItem != e.end() && *deleteItem == *it){
				e.erase(deleteItem);
				deleteItem = it;
				it++;
				s.erase(deleteItem);
			}else{
				it++;
			}
		}
		if(ss.size() + s.size() + e.size() <= 2){
			printf("Yes\n");
		}else
			printf("No\n");
		
	} 
	return 0;	
} 
/*
3
abc
cge
egf

*/ 
