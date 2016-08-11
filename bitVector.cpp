/*
 * 位向量 
 *	b[0]二进制中的最低位代表0， 次低位代表1， 一次类推 
 *  
 */
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int bit[100000000];

void init()
{
	memset(bit, 0, 	sizeof(bit));
} 

int setBit(int n){
	
	int index = n >> 5;
	int offset = n & 31;
	int tmp = 1 << offset;
	bit[index] = tmp | bit[index];
} 

int clearBit(int n)
{
	int index = n >> 5;
	int offset = n & 31;
	int tmp = 1 << offset;
	tmp = ~tmp;
	bit[index] &= tmp;
}

int getBit(int n){
	
	int index = n >> 5;
	int offset = n & 31;
	int check = 1 << offset;
	return bit[index] & check;
}

int main()
{
	init();
	int x;
	while(scanf("%d",&x)!=EOF){
		if(getBit(x)){
			printf("%d 已经出现过了！\n", x);
			clearBit(x);
		}else{
			printf("%d 是第一次出现！\n", x);
			setBit(x);
		}
		
	}
	return 0;
 } 
