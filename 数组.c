//数组
type arrayName [ arraySize ];
//举例
char heap_a [1024];
double banlance [5];
//初始化数组（可以逐个初始化数组，也可以使用一个初始化语句）
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
//如果省略掉了数组的大小，数组的大小则为初始化时元素的个数
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
//数组中某个元素赋值（把数组中第五个元素的值赋为 50.0）
balance[4] = {50.0};

/*
	数组应用实例
*/
#include<stdio.h>

int main ()
{
	int n[10];
	int i,j;
	//初始化数组元素
	for (i = 0;i < 10;i ++)
	{
		n[i] = i + 100;
	}
	
	//输出数组中每个元素的值
	for (j = 0;j < 10;j ++)
	{
		printf("n[%d]=%d"\r\n,j,n[j]);
	}
}


int main ()
{
	int n[10];
	int a,b;
	for (a = 0;a < 10;a ++)
	{
		n[a]=a + 1000;
	}
	for (b = 0;b < 10;b ++)
	{
		printf("n[%d] = %d\r\n",b,n[b]);
	}
}
