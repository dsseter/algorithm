#include<stdio.h>

/**
 * .c file
 * gcc
 * 将一个字符串循环左移k位{0<k<n}. 如 123456 左移3位得 456123
 */

int reverse(char* str, int start, int end)
{
	char tmp;
	while(start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		end--;
		start++;
	}
}


int right_shift(char *str, int len, int k)
{
	if(!str || len <= 0 || k < 0 || k > len)
	{
		printf("params are error\n");
		return 1;
	}
	reverse(str, 0, len-k-1);
	reverse(str, len-k, len-1);
	reverse(str, 0, len-1);
	return 0;
}

int main(void)
{
	int len = 7;
	char str[] = "abcdefg";
	for(int i=-len; i<len+len; i++)
	{
		printf("shift %d\n", i);
		right_shift(str, len, i);
		printf("%s\n", str);
	}
	return 0;
}
