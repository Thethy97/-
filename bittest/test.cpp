#include<iostream>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<time.h>
using namespace std;
//打印100~200 之间的素数 n%i != 0&& n!=i
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	printf("count = %d\n", count);
//	system("pause");
//	return 0;
//}
//优化:c = a * b ,a和b肯定有一个小于sqrt（i）


//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	printf("count = %d\n", count);
//	system("pause");
//	return 0;
//

//输出乘法口诀表

void  PrintMul()
{
	int i = 0; 
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %2d ",i,j, i * j );
		}
		printf("\n");
	}

}
//判断1000年到2000年之间的闰年
//year%4 == 0&&year%100 != 0&& year%100 == 0
void IsLeapY()
{
	int year;
begin:printf( "请输入年份：\n");
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
	printf("是否继续 ：1\n");
	int i;
	cin >> i;
	if (i == 1)
	{
		goto begin;
	}
	else 
	{
		return;
	}
}
//给定两个整形变量的值，将两个值的内容进行交换。
void Swap(int *x, int *y)//改变x，y的值无法改变a，b的值，x，y叫形参，a,b叫实参，所以要传
							//a,b的地址
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y= tmp;
}
//不允许创建临时变量，交换两个数的内容（附加题）
void Swap1(int* x, int* y)//可能存在内存溢出
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}
void Swap2(int* x, int* y)//用异或的方法
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

//求10 个整数中最大值。
//int Max(int a[])里面，int a[]; 只是一个声明，编译器没有为a[]分配内存，
//只是为a分配了一个记录a[]首元素地址的指针(尽管a[]为空)。
//所以a是int *型的，所以sizeof(a) = 4
int Max(int a[])
{
	int i = 0;

//	//int size = sizeof(a) / sizeof(int);
//	//int Max(int a[])里面，int a[]; 只是一个声明，编译器没有为a[]分配内存，
//	//只是为a分配了一个记录a[]首元素地址的指针(尽管a[]为空)。
//	//所以a是int *型的，所以sizeof(a) = 4
	int max = a[0];
	for (i = 1; i < 10; i++)
	{
		if (max <= a[i])
		{
			max = a[i];
		}
		else
		{
			max = max;
		}
		
	}
	return max;
}
//将三个数按从大到小输出。
void Sort(int* a, int* b, int* c)//比较法
{
	if (*a >= *b)
	{
		if (*b >= *c)
		{
			//return *a, *b, *c;
		}
		else
		{
			/**b = *b^*c;
			*c = *b^*c;
			*b = *b^*c;*/
			Swap2(b,c);
		}
	}
	else
	{
		/**a = *b^*a;
		*b = *b^*a;
		*a = *b^*a;*/
		Swap2(a, b);
		if (*c >= *a)
		{
			Swap2(c, a);
		}
		if (*c >= *b)
		{
			Swap2(c, b);
		}
		//return *a, *b, *c;//函数只能有一个返回值
	}
}
//冒泡法：传一个三值的数组
//选择排序法
//假设需要对10个数进行排序，那么首先找出10个数里面的最小数，
//并和这个10个数的第一个（下标0）交换位置，
//剩下9个数（这9个数都比刚才选出来那个数大），再选出这9个数中的最小的数，
//和第二个位置的数（下标1）交换，于是还剩8个数（这8个数都比刚才选出来的大）..
//依次类推，当还剩两个数时，选出两个数的最小者放在第9个位置（下标8），于是就只剩下一个数了。这个数已经在最后一位（下标9），不用再选择了。所以10个数排序，一共需要选择9次（n个数排序就需要选择n - 1次）。


//求两个数的最大公约数。
int MaxCommon(int a, int b)
{
	int i = 0;
	int min = 0;
	int max = 0;
	if (a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	for (i = 1; i <= min; i++)
	{
		while (a%i == 0 && b%i == 0)
		{
			max = i;
			break;
		}
	}
	return max;
}
//1.将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void SwapArray(int *arr1,int *arr2,int lenth)
{
	int i = 0;
	assert(arr1 != NULL && arr2 != NULL);
	for (i = 0; i < lenth; i++)
	{
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
	return;
}
void PrintfArray(int *arr, int lenth)
{
	int i = 0;
	for (i = 0; i < lenth; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return ;
}
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
void Count()
{
	int i = 0;
	double count = 0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		count = count + (flag*1.0)/i;
		flag = -flag;
	}
	printf("%lf", count);

}
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
int Test()
{
	int count = 0;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	return count;
}
/*1.在屏幕上输出以下图案：
*
***
*****
*******
*********
***********
*************
***********
*********
*******
*****
***
*
*/
void PrintfStar()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 13; i += 2)
	{
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 11; i >= 1; i -= 2)
	{
		for (j = 1; j <=i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
//2.求出0～999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。

/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
是指一N位数，其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/
void NarcissisticNumber()
{
	int i = 0;
	int m = 0;
	int n = 0;
	int j = 0;
	for (i = 100; i <= 999; i++)
	{
		/*if (i / 100 != 0)
			N = 3;
		else if (i / 10 != 0)
			N = 2;
		else
			N = 1;*/
		m = i / 100;
		//n = (i / 10) - (m * 10);
		n = (i / 10) % 10;
		//j = i - (m * 100) - (n * 10);
		j = i % 10;
		if (i == m *m*m  + n *n*n + j *j*j)//double a = pow(3.14, 2);  // 计算3.14的平方
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}


//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
void SumSn(int a)
{
	int sn = 0;
	int i = 0;
	int sum = 0;
	for (i = 0; i < 5; i++)
	{
		sum = sum + a*pow(10,i);
		sn = sn + sum;
	}
	printf("%d\n", sn);
}
//4.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。
int test()
{
	int ch = 0;
	int count = 0;
	
	while ((ch = getchar()) != EOF)
	{

		//gerchar()函数
		//getchar从stdio流中读字符, getchar有一个int型的返回值.
		//当程序调用getchar时.程序就等着用户按键.用户输入的字符被存放在键盘缓冲区中.
		//直到用户按回车为止(回车字符也放在缓冲区中).当用户键入回车之后, 
		//getchar才开始从stdio流中每次读入一个字符.getchar函数的返回值是用户输入的第一个字符的ASCII码
		// 如出错返回 - 1, 且将用户输入的字符回显到屏幕.如用户在按回车之前输入了不止一个字符,
		//其他字符会保留在键盘缓存区中, 等待后续getchar调用读取.也就是说,
		//后续的getchar调用不会等待用户按键, 而直接读取缓冲区中的字符, 
		//直到缓冲区中的字符读完为后, 才等待用户按键。

		//EOF
		//在while循环中以EOF作为文件结束标志，这种以EOF作为文件结束标志的文件，
		//必须是文本文件。在文本文件中，数据都是以字符的ASCII代码值的形式存放。
		//我们知道，ASCII代码值的范围是0~255，不可能出现 - 1，因此可以用EOF作为文件结束标志。
		if (ch == '{')
		{
			count++;
		}
		else if ((ch == '}') && count != 0)
		{
			count--;
		}
		else if ((ch == '}') && count == 0)
		{
			printf("false\n");
			return 0;
		}
	}
	if (count == 0)
	{
		printf("true");
	}
	else
		printf("false\n");
	return 0;
}
//1.完成猜数字游戏。
void game()
{
	int random = 0;
	int input = 0;
	int i = 0;
	printf("****游戏开始****\n");
	srand((unsigned)time(NULL));//产生一个随机数
	random = rand() % 100;//是生成 0 到 100 之间的随机数。
	for(i=0;i<9;i++)
	{
		printf("你猜多少：\n");
		//scanf("%d",&input);
		std::cin >> input;
		if (input > random)
		{
			printf("你猜大了\n");
			continue;
		}
		else if (input < random)
		{
			printf("你猜小了\n");
			continue;
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
	if (i == 9)
		printf("游戏失败\n");
}
//int main()
//{
//	int choose = 0;
//	int i = 0;
//	printf("是否进入猜数游戏（输入1开始，0结束）\n");
//	//scanf("%d", &choose);
//	std::cin >> choose;
//	switch (choose)
//	{
//	case 1:game();
//		break;
//	case 0:exit(0);
//		break;
//	default:
//		printf("输错了\n");
//		break;
//	}
//L:system("pause");//按任意键
//	system("cls");//清屏
//	printf("是否继续游戏（1 继续  其他键 退出）\n");
//	//scanf("%d", &i);
//	std::cin >> i;
//	if (i == 1)
//		game();
//	else
//	{
//		exit(0);
//	}
//	goto L;
//	system("pause");
//	return 0;
//}
//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
//二分查找
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0;

	return 0;
}
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。

//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。

////int main()
//{
//	//PrintMul();
//	//IsLeapY();
//	//int a = 1, b = 2;
//	//Swap2(&a,&b);
//	/*int a[] = { 1,3,4,5,2,1,4,5,6,3 };
//	Max(a);*/
//	//Sort(&a, &b, &c);
//	/*int a = 9;
//	int b = 6;
//	int Max = MaxCommon(17, 7);*/
//	/*int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[] = { 9,8,7,6,5,4,3,2,1 };
//	int lenth = sizeof(arr1) / sizeof(int);
//	PrintfArray(arr1, lenth);
//	PrintfArray(arr2, lenth);
//	SwapArray(arr1, arr2, lenth);
//	PrintfArray(arr1, lenth);
//	PrintfArray(arr2, lenth);*/
//	//printf("最大公约数：%d\n",Max);
//	//PrintfStar()
//	//NarcissisticNumber();
//	//printf("%d\n", Test());
//	/*int a = 5;
//	SumSn(5)*/;
