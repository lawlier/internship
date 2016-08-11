#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<queue>
#include<set>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d%d",&n, &m)!=EOF){
		queue<int> que;
		set<int> s;
		int ans = 0;
		for(int i = 0; i < m; i++){
			int x; 
			scanf("%d", &x);
			
			if(s.count(x) == 0){
				if(s.size() == n){
					int top = que.front();
					que.pop();
					s.erase(top);
					que.push(x);
					s.insert(x);
				}else{
					s.insert(x);
					que.push(x);
				}
				ans ++;
			}
		}
		printf("%d\n", ans);
	}
} 
