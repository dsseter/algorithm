#include<stdio.h>
#include<assert.h>


/**
 * .c file
 * gcc
 * 输入一个整形数组，数组里有正数也有负数。
 * 数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
 */
int max_sublist(int *list, int len, int *result)
{
	if(!list || len <1)
	{
		printf(" list is NULL or len < 1\n");
		return 1;
	}
	int count = list[0];
	int max = list[0];
	for(int i=1; i<len; i++)
	{
		if(count > 0)
		{
			count += list[i];
		}else{
			count = list[i];
		}
		if(max < count)
		{
			max = count;
		}
	}
	*result = max;
	return 0;
}


int main(void)
{
	int list[] = {-6, -2, -4, -4, -2, -3, -5, -1, -3};
	int len = 9;
	int max = 0;
	int result = max_sublist(list, len, &max);
	if(result)
	{
		printf("error\n");
		return 0;
	}
	printf("%d\n", max);
	return 0;
}
