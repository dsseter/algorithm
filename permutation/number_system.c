#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0
void print(int *list, int len)
{
	for(int i=0; i<len; i++)
	{
		printf("%d,", list[i]);
	}
	printf("\n");
}

int calc(int n)
{
	int count = 1;
	for(int i=1; i<=n; i++)
	{
		count *= i;
	}
	return count;
}

void right_shift(int* list, int start, int len, int offset)
{
	for(; len > 0; len--)
	{
#if DEBUG
		printf("s %d, e %d\n",start+len-1, start+offset+len-1);
#endif
		list[start+offset+len-1] = list[start+len-1];
	}
}

/**
 * 我们首先从最基本的情况开始:假设我们有一个长度为nn的数列，首先取出第一个数字，然后取出第二个数字，此时第二个数字有两种放置的选择，可以放在第一个数字的左边或右边；
 * 接着取第三个数字，它将会有3种选择:左边、中间、右边；依次可以类推下去。多进制算法的精妙之处，是将这些可能的选择情况编码成为了一个数字:
 * 从左至右将可能放置的位置进行编号，从0开始。比如取出第三个数字时，它有左边、中间、右边三种选择情况，则着三种选择分别用0,1,20,1,2来表示。
 *
 * 我们可以设计一个数，比如是xyz，其中z是二进位的，y是三进位的，x是四进位的，分别代表第二个数字、第三个数字、第四个数字可以进行选择的情况
 * 这样设计的话，我们就可以将一种排列的状态转换为一个多进制的数，只要能给定一个这样的多进制数，我们就能计算出其相应的排列情况。
 * /
void perm(int *list, int len)
{
	int count = calc(len);
	int *list_perm = (int*) malloc(sizeof(int)*len);
	for(int i=0; i<count; i++)
	{
		int remainder = 0;
		int quotients = i;
		list_perm[0] = list[0];
		for(int j=2; j<=len; j++)
		{
			remainder = quotients % j;
#if DEBUG
			printf("tmp ");
			print(list_perm, len);
			printf("remainder %d, quotients %d\n", remainder, quotients);
#endif
			right_shift(list_perm, remainder, j-1-remainder, 1);
			list_perm[remainder] = list[j-1];
			quotients /= j;
		}
		print(list_perm, len);
	}
	free(list_perm);
}


int main(void)
{
	int list[] = {1, 2, 3, 4, 5};
	int len = 3;
	perm(list, len);
}
