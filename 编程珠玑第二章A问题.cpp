/*
 * @from 编程珠玑第二章A问题 
 * @question 给定一个最多包含40亿个随机排列的32位整数的顺序文件，
 * a. 找出一个不在文件中的32位。在具有足够内存的情况下如何解决该问题？
 * b. 如果有几个外部的“临时”文件可用，但是仅有几百字节的内存，又该
 * 如何解决问题。 
 * @author Terence(庄健春) 
 * @e-mail 570103680@qq.com 
 */

/*
 * 对于问题的理解：刚开始对问题不太理解，研究了一下，我是这样理解这个问题的
 * 给定的40亿个数不重复，随机的排列在一个顺序文件中，寻找没有出现过的整数，
 * 这里有可能缺失了超过一个的整数，问题只是要求其中的一个，如果要找出全部的话，
 * 其实也是可以的，这里我给出的解法就是找出所有缺失的数
 * 
 * 由于文件操作比较麻烦，这里改用vector来代替文件，并且用1000来代替40亿 
 * 
 */ 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map> 

using namespace std;
//数据规模 
const int maxn = 1024;

//原始文件
vector<int> v1;
vector<int> v2, v3;

//构造一个随机不重复的排列，并且缺失一个数 
struct rand_digit{
	int v, rand;
} arr[maxn]; 

int cmp(rand_digit a, rand_digit b){
	return a.rand < b.rand;
}

void init(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
	rand_digit x;
	int rand = 40;
	
	//缺失的整数集
	int s[] = {999};
	set<int> lostInt;
	
	for(int i = 0; i < sizeof(s) / 4; i++)
		lostInt.insert(s[i]);
	
	
	int k = 0;
	for(int i = 0; i < maxn; i++){
		if( lostInt.count(i) )
			continue;
		rand ++;
		rand  %= 50;
		x.rand = 50 - rand;
		x.v = i;
		arr[k++] = x;
	} 
	
	sort(arr, arr + k, cmp);
	
	v1.clear();
	
	for(int i = 0; i < k; i++){
		//printf("%d ", arr[i].v);
		v1.push_back(arr[i].v);
	}
	//printf("\n");
	
	v2.clear();
	v3.clear();
} 

void solve(vector<int> v1, vector<int> v2, vector<int> v3, int offset, set<int> &ans){
	v2.clear();
	v3.clear();
	if(v1.size() == 0){
		printf("000000000000000000\n");
	}
	if( v1.size() == 1){
		int checkCode = 1 << offset;
		if(v1[0] & checkCode)
			ans.insert(v1[0] | (~checkCode) );
		else
			ans.insert(v1[0] | checkCode);
		return;	
	}
	
	for(int i = 0; i < v1.size(); i++){
		int checkCode = 1 << offset;
		if(v1[i] & checkCode)
			v2.push_back(v1[i]);
		else
			v3.push_back(v1[i]);
	}
	if(v2.size() == 0){
		
	}	
	if(v3.size() == 0){
		
	}
	if(v2.size() != maxn >> (offset + 1)){
		solve(v2, v1, v3, offset + 1, ans);
	}
	if(v3.size() != maxn >> (offset + 1)){
		solve(v3, v1, v2, offset + 1, ans);
	}
}

int main()
{
	init(v1, v2, v3);
	set<int> ans; 
	set<int>::iterator it;
	solve(v1, v2, v3, 0, ans);
	for(it = ans.begin(); it != ans.end(); it++)
		printf("%d\n", *it);
		
	return 0;
}
 
