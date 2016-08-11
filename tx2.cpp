#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1010;

struct str{
	char c;
	int i;
}a[maxn];
int cmp(str a, str b)
{
	return a.i < b.i;
}
int main()
{
	char str[maxn];
	while(scanf("%s",str)!=EOF)
	{
		int len = strlen(str);
		for(int i = 0; i < len; i++)
		{
			a[i].c = str[i];
			a[i].i = i;
			if(str[i] >= 'A' && str[i] <= 'Z')
				a[i].i += 1000;
		}
		sort(a, a + len, cmp);
		for(int i = 0; i < len; i++)
			printf("%c", a[i].c);
		printf("\n"); 
	}
	return 0;	
} 
