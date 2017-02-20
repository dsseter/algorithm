#include<stdio.h>
/**
 * .c file
 * gcc
 * 题目描述:输入一个正数n，输出所有和为n连续正数序列。例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。 
 * 要求:给出尽可能高效的算法思想， 提交可执行的标准C代码， 分析时间，空间复杂度。 
 *
 */

#define DEBUG 0
int sum(int start, int end)
{
	int count = (start + end) * (end -start + 1) / 2;
#if DEBUG
	printf("%d %d sum %d\n",start, end, count);
#endif
	return count;
}

void print(int start, int end, int n)
{
	if(start > end)
	{
		printf("start > end\n");
		return;
	}
	while(start < end)
	{
		printf("%d+", start);
		start++;
	}
	printf("%d=%d\n", end, n);
}

int get_seriesof_num(int n)
{
	int half_n = (n+1)/2;
	int start = half_n, end = half_n;
	int count = 0;
	
	int step = 0;
	while(start > 0)
	{
		count = sum(start, end);
		if(n == count)
		{
			print(start, end, n);
			end--;
			start--;
		}else if( n > count)
		{
			start--;
		}else{
			end--;
		}
#if DEBUG
	if(step++ == 4)
		return 0;
#endif
	}
	return 0;
}


int main(void)
{
	int n = 15;
	get_seriesof_num(n);
}
