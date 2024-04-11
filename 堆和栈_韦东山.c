/*
	堆模拟过程。堆是一块空闲内存，从内存中取出一部分出来用，用完后再释放回去。
*/

char heap_buf[1024];
int pos = 0;
g_cnt = 0;

void *my_malloc(int size)
{
	int old_pos = pos;
	pos + = size;
	return &heap_buf[old_pos];
}

void my_free(void *buf)
{
	/* erro */
}

void func_b(volatile int a)
{
	a + = 2;
	return a;
}
void func_c(volatile int a)
{
	a + = 3;
	return a;
}

void func_a (volatile int a)
{
	g_cnt = func_b(a);
	g_cnt = func_c(g_cnt);
	
}

int main(void)
{
	char ch = 65;
	volatile int i = 99;
	char *buf = my_malloc(100);
	unsigned char uch = 200;
	for (i = 0;i < 26;i ++)
		buf[i] = 'A' + i;
	
	func_a(i);
	
	return 0;
}
/*
	C函数调用其他子函数的本质为，BL指令：用于函数跳转，
	最终实现两个功能LR（在LR寄存器里面记录返回地址）和PC（要跳转函数的地址）
*/
/*
	在C入口：保存局部变量
			 保存LR进栈
			 划出自己的栈
	问：
	1.LR会被覆盖了吗？
	答：LR在覆盖之前会被保存PUSH（在C入口保存LR进栈里）
	2.局部变量在栈里面分配，是如何分配的？
	答：保存局部变量
	3.为何每个RTOS任务都有自己的栈？
	答：
*/


