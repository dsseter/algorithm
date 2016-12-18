#include<stdio.h>

/**
 *利用字符重复的次数，编写一个函数，实现基本的字符串压缩功能
 *
 */
void compress(char* str)
{
	if(!str)
	{	
		printf("string is NULL\n");
		return;
	}
	char *first = str, *second = str;
	int count = 1;
	while(*second)
	{
		if(*second == *(second+1))
		{
			count++;
		}else{
			if(count !=1)
			{
				*(first++) = *second;
				sprintf(first, "%d", count);
				while(*first)
					first++;
				count = 1;
			}else{
				*(first++) = *second;
			}
		}
		second++;
	}
	*first = *second;
}

int main(void)
{
	char str[] = "aaaaaaaaaaaaaaabbbcccd";
	printf("%s\n", str);
	compress(str);
	printf("%s\n", str);
	char str1[] = "abcdefg";
	printf("%s\n", str1);
	compress(str);
	printf("%s\n", str1);
}
