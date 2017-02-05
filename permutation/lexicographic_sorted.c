#include<stdio.h>

#define DEFAULT_INDEX -1
#define DEFAULT_MIN_VALUE 10000

#define DEBUG 0

void swap(int* index1, int *index2)
{
	int tmp = *index1;
	*index1 = *index2;
	*index2 = tmp;
}

void reverse(int* list, int start, int end)
{
	while(start < end)
	{
#if DEBUG
	printf("start %d , end %d\n", start, end);
#endif
		list[start] ^= list[end];
		list[end] ^= list[start];
		list[start++] ^= list[end--];
	}
}

void print(int* list, int len)
{
	for(int i=0; i<len; i++)
		printf("%d,", list[i]);
	printf("\n");
}

/**
 *
 * 采用字典序生成排列.
 * 其实字段序取自数字中的进位原理; 引用数字进位的原理,根据序列的特征,生成序列的进位原理
 * 
 * 排列序列有如下特征: 
 * 原序列: 6745321
 * 新序列: 6751234
 * 1.永远在进位
 * 2.低位先进. 进4 不进6
 * 3.进位递增. 进4变5
 * 4.低位满位. 5321已满
 * 5.低位转置. 满数转置, 54321->12345
void lexicographic(int* list, int len)
{
	while(1)
	{
		int carry_index = DEFAULT_INDEX;
		int min_value = DEFAULT_MIN_VALUE;
		int swap_index = DEFAULT_INDEX;
		print(list, len);
		for(int i=len-1; i>0; i--)
		{
			if(list[i-1] < list[i])
			{
				carry_index = i - 1;
				break;
			}
		}
		if(carry_index == DEFAULT_INDEX)
		{
			break;
		}
		int i = carry_index + 1;
		min_value = list[i];
		swap_index = i;
		for(; i<len; i++)
		{
			if(list[i] > list[carry_index] && list[i] < min_value)
			{
				min_value = list[i];
				swap_index = i;
			}
		}
#if DEBUG
		printf("carry_index %d, swap_index %d\n", carry_index, swap_index);
#endif 
		swap(list+carry_index, list+swap_index);
		reverse(list, carry_index+1, len-1);
	}
}



int main(void)
{
	int list[] = {1, 2, 3, 4, 5};
	int len = 4;
	lexicographic(list, len);
}
