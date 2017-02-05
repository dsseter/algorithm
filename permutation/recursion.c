#include<stdio.h>


void swap(int *list, int index1, int index2)
{
	int tmp = list[index1];
	list[index1] = list[index2];
	list[index2] = tmp;
}

void print_list(int *list, int len)
{
	for(int i=0; i<len; i++)
		printf("%d,", list[i]);
	printf("\n");
}
/**
 * 利用递归方案，排序出来的结果不是顺序的
 */ 
void permutation(int *list, int start, int len)
{
	if(start == len)
	{
		print_list(list, len);
		return;
	}

	for(int i=start; i<len; i++)
	{
		swap(list, start, i);
		permutation(list, start+1, len);
		swap(list, i, start);
	}
}

int main(void)
{
	int list[] = {1,2,3};
	int len = 3;
	permutation(list, 0, len);
}
