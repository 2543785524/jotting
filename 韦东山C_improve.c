//局部变量的分配与初始化
#include<main.h>
int main(void)
{
	char*name1 = "wlh";
	int age1 = 20;
	char*name2 = "syb";
	int age2 = 22;
	printf("%d，%d",age1,age2);
	return 0;
}
struct person
{
	char *name;
	int age;
};
//定义的结构体不是变量，不会占空间，只有变量才会分配内存
struct person w ={"wanglihua",210};//这句话才分配空间
//结构体-->赋值
char
int
struct 
//结构体指针
struct student
{
	char *name;
	int age;
	struct student *classmate;
}student, *pstudent;

struct student zhangsan ={'zhangsan', 20 ,NULL};
struct student lili ={'lili' ,29 ,NULL};

zhangsan.classmate = &lili;
lili.classmate = &zhangsan;

printf("zhangsan's classmate is : %s/r/n",zhangsan.classmate->name);

void (*play ball) (void);//函数名字和取址函数是一样的

//产品支持两种屏幕，通过宏使用LCD
void draw_logo_lcda(void)
{
	printf("display logo on lcd a\r\n");
}

void draw_logo_lcdb(void)
{
	printf("display logo on lcd b\r\n");
}

int main (void)
{
	#ifdef LCD_TYPE_A  //更换屏幕就要修改代码，麻烦
		draw_logo_lcda();
	#else 
		draw_logo_lcdb();
	#endif
	
}
/*使用LCD通过EEPROM读取屏幕型号*/
int read_eeprom()
{
	/*
		0: lcd a
		1: lcd b
	*/
	return 0;
}

int get_lcd_type(void)
{
	return read_eeprom();
}

int main(void)
{
	int type = get_lcd_type();
	
	if(type == 0)
	{
		draw_logo_lcda();
	}
	else if(type == 1)
	{
		draw_logo_lcdb();
	}
}
//缺点在于，屏幕太多的时候就无法定义这么多的屏幕了

//为什么要用函数指针？

struct lcd_operation{
	int type;
	void (*draw_logo)(void);
};

lcd_operation xxx_com_lcds[]={
	{0,draw_logo_lcda},{1,draw_logo_lcdb},
};

int main(void)
{
	xxx_com_lcds[type].draw_logo();
}

//结构体，结构体指针，函数指针
/*
Q1：使用结构体可以节省硬件资源？
	节省硬件资源可能是程序写的比较好而已，节省了许多if语句，节省了硬件资源
*/

/*
Q2：在一个结构体初始化中这样写{.type = xx ,.test = yy}
	
*/
typedef 	//定义变量类型的别名
#define A 1
int i = A;
typedef 	//类型定义，用来创建类型的
	typedef int A;	//用A来表示类型int
	A i;			//定义类型为A的变量i

typedef struct lcd_operation * D;
//用D来表示struct lcd_operation *(结构体指针)类型

typedef int (*add_type)(int,int);
add_type f1;
add_type f2;

//结构体类型
//结构体指针类型

//结构体数组
int a;
int b[2];

//解释一下get_lcd函数

/*
	定义两种类型的别名
	lcd_operation 结构体类型别名
	p_lcd_operation 结构体指针类型别名
*/
typedef struct lcd_operation{
	int type;
	void (*draw_logo)(void);
}lcd_operation,*p_lcd_operation;

/*
	定义类型为lcd_operation 的结构体数组
*/
lcd_operation xxx_com_lcds[]={
	{0,draw_logo_lcda},
	{1,draw_logo_lcdb},
};


/*
	定义p_lcd_operation 类型的函数get_lcd
*/
p_lcd_operation get_lcd(void)
{
	int type = get_lcd_type();
	return &xxx_com_lcds[type];
}
//函数把结构体数组指针的知识揉到一起了，需多读
