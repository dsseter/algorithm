#include<stdio.h>
#include<stdlib.h>

#define LEFT -1
#define RIGHT 1

#define DEBUG 0


void print(int *list, int len)
{
	for(int i=0; i<len; i++)
		printf("%d,", list[i]);
	printf("\n");
}

void swap(int *list, int* tags, int index)
{
	int tmp;
	tmp = list[index];
	list[index] = list[index+tags[index]];
	list[index+tags[index]] = tmp;

	tmp = tags[index];
	tags[index] = tags[index+tmp];
	tags[index+tmp] = tmp;
}
/**
 * event算法 又称Steinhaus-Johnson-Trotter算法。是基于相邻节点的关系生成的全排列算法。
 * 
 *          123   1234
 *     12   132   1243
 * 1-> 21-> 312-> 1423
 *          213   4123
 *          231    .
 *          321    .
 *                 .
 *                 3214
 *                 3241
 *                 3421
 *                 4321
 * 每个排列都可以是子排列，通过在不同位置插入获得。
 * 实现方案:
 * 该算法需要一个方向数组， 用来执行下标表示的值的前进方向。
 * 1. max{k|A[k] > A[k+tags[K]], 0<k<n} 找到最大值k
 * 2. A[k] <-> A[k+tags[k]]  互换k 和k+tags[k]的内容和tags
 * 3. reverse{A[i]>A[k]} 转置所有大于A[k]的值
 *
 * 特征： 1. 最大值总是从最左移动到最右，次值类推。
 *        2. 生成排列总是"递推"完成， 从1 到N
 */
void even(int *list, int len)
{
	int *tags = (int*) malloc(len * sizeof(int));
	for(int i=0; i<len; i++)
		tags[i] = LEFT;
#if DEBUG
	int ret = 0;
#endif
	while(1)
	{
		int max = -1;
		int index = -1;
		print(list, len);
		for(int i=0; i<len; i++)
		{
			if(tags[i] == LEFT && i > 0 && list[i-1] < list[i])
			{
				if(max < list[i])
				{
					max = list[i];
					index = i;
				}
			}
			if(tags[i] == RIGHT && i < len-1 && list[i] > list[i+1])
			{
				if(max < list[i])
				{
					max = list[i];
					index = i;
				}
			}
		}
#if DEBUG
		printf("%d\n", max);
		print(tags, len);
#endif 
		if(max == -1)
		{
			break;
		}else{
			swap(list, tags, index);
		}
		for(int i = 0; i<len; i++)
		{
			if(list[i] > max)
			{
				tags[i] = tags[i] == RIGHT? LEFT: RIGHT;
			}
		}
#if DEBUG
		if(ret == 20)
			break;
		ret++;
#endif
	}
	free(tags);
}


int main(void)
{
	int len = 4;
	int list[] = {1, 2, 3, 4};
	even(list,len);
	return 0;
}
