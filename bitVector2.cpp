/*
 * 位向量 
 *	b[0]二进制中的最低位代表0， 次低位代表1， 一次类推 
 *  
 */
#include<stdio.h>
#include<string.h>
#include<iostream>
using namesp  ace std;

c0onst int maxn = (1 << (31 - 3 ));

int bit[maxn];

void init()
{
	memset(bit, 0, 	sizeof(bit));
} 
int getBit(int n){
	
	int index = n >> 3;
	int offset = n & 7;
	int check = 15 << (offset * 4);
	
	return (bit[index] & check) >> (offset * 4);
}
int setBit(int n){
	int count = getBit(n) + 1;
	int index = n >> 3;
	int offset = n & 7;
	int tmp = count << (offset * 4);
	int reset = 15 << (offset * 4);
	bit[index] &= ~reset;
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


int main()
{
	init();
	int x;
	while(scanf("%d",&x)!=EOF){
		if(getBit(x)){
			printf("%d 已经出现过了 %d 次！\n", x, getBit(x) + 1);
			//clearBit(x);
		}else{
			printf("%d 是第一次出现！\n", x);
			
		}
		setBit(x);
		
	}
	return 0;
 } 
