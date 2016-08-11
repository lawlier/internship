#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

void reverse(char s[], int l, int r){
	for(int i = l; i < (l + r) / 2; i++)
	{
		int tmp = s[i];
		s[i] = s[r - i];
		s[r - i] = tmp;
	}
}

void solve(char s[], int i, int n){
	reverse(s, 0, i - 1);
	reverse(s, i, n - 1);
	reverse(s, 0, n - 1); 
}

int main()
{
	char s[] = {"abcdefgh"};
	solve(s, 3, 8);
	printf("%s\n", s);
} 
