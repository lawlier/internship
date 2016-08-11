/*
 * @from �������ڶ���A���� 
 * @question ����һ��������40�ڸ�������е�32λ������˳���ļ���
 * a. �ҳ�һ�������ļ��е�32λ���ھ����㹻�ڴ���������ν�������⣿
 * b. ����м����ⲿ�ġ���ʱ���ļ����ã����ǽ��м����ֽڵ��ڴ棬�ָ�
 * ��ν�����⡣ 
 * @author Terence(ׯ����) 
 * @e-mail 570103680@qq.com 
 */

/*
 * �����������⣺�տ�ʼ�����ⲻ̫��⣬�о���һ�£��������������������
 * ������40�ڸ������ظ��������������һ��˳���ļ��У�Ѱ��û�г��ֹ���������
 * �����п���ȱʧ�˳���һ��������������ֻ��Ҫ�����е�һ�������Ҫ�ҳ�ȫ���Ļ���
 * ��ʵҲ�ǿ��Եģ������Ҹ����Ľⷨ�����ҳ�����ȱʧ����
 * 
 * �����ļ������Ƚ��鷳���������vector�������ļ���������1000������40�� 
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
//���ݹ�ģ 
const int maxn = 1024;

//ԭʼ�ļ�
vector<int> v1;
vector<int> v2, v3;

//����һ��������ظ������У�����ȱʧһ���� 
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
	
	//ȱʧ��������
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
 
