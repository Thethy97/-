#include<iostream>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<time.h>
using namespace std;
//��ӡ100~200 ֮������� n%i != 0&& n!=i
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
//�Ż�:c = a * b ,a��b�϶���һ��С��sqrt��i��


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

//����˷��ھ���

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
//�ж�1000�굽2000��֮�������
//year%4 == 0&&year%100 != 0&& year%100 == 0
void IsLeapY()
{
	int year;
begin:printf( "��������ݣ�\n");
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
	printf("�Ƿ���� ��1\n");
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
//�����������α�����ֵ��������ֵ�����ݽ��н�����
void Swap(int *x, int *y)//�ı�x��y��ֵ�޷��ı�a��b��ֵ��x��y���βΣ�a,b��ʵ�Σ�����Ҫ��
							//a,b�ĵ�ַ
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y= tmp;
}
//����������ʱ���������������������ݣ������⣩
void Swap1(int* x, int* y)//���ܴ����ڴ����
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}
void Swap2(int* x, int* y)//�����ķ���
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

//��10 �����������ֵ��
//int Max(int a[])���棬int a[]; ֻ��һ��������������û��Ϊa[]�����ڴ棬
//ֻ��Ϊa������һ����¼a[]��Ԫ�ص�ַ��ָ��(����a[]Ϊ��)��
//����a��int *�͵ģ�����sizeof(a) = 4
int Max(int a[])
{
	int i = 0;

//	//int size = sizeof(a) / sizeof(int);
//	//int Max(int a[])���棬int a[]; ֻ��һ��������������û��Ϊa[]�����ڴ棬
//	//ֻ��Ϊa������һ����¼a[]��Ԫ�ص�ַ��ָ��(����a[]Ϊ��)��
//	//����a��int *�͵ģ�����sizeof(a) = 4
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
//�����������Ӵ�С�����
void Sort(int* a, int* b, int* c)//�ȽϷ�
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
		//return *a, *b, *c;//����ֻ����һ������ֵ
	}
}
//ð�ݷ�����һ����ֵ������
//ѡ������
//������Ҫ��10��������������ô�����ҳ�10�����������С����
//�������10�����ĵ�һ�����±�0������λ�ã�
//ʣ��9��������9�������ȸղ�ѡ�����Ǹ����󣩣���ѡ����9�����е���С������
//�͵ڶ���λ�õ������±�1�����������ǻ�ʣ8��������8�������ȸղ�ѡ�����Ĵ�..
//�������ƣ�����ʣ������ʱ��ѡ������������С�߷��ڵ�9��λ�ã��±�8�������Ǿ�ֻʣ��һ�����ˡ�������Ѿ������һλ���±�9����������ѡ���ˡ�����10��������һ����Ҫѡ��9�Σ�n�����������Ҫѡ��n - 1�Σ���


//�������������Լ����
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
//1.������A�е����ݺ�����B�е����ݽ��н�����������һ����
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
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
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
//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
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
/*1.����Ļ���������ͼ����
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
//2.���0��999֮������С�ˮ�ɻ��������������ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������

/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number����
��ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
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
		if (i == m *m*m  + n *n*n + j *j*j)//double a = pow(3.14, 2);  // ����3.14��ƽ��
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}


//3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2 + 22 + 222 + 2222 + 22222
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
//4.��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡�
int test()
{
	int ch = 0;
	int count = 0;
	
	while ((ch = getchar()) != EOF)
	{

		//gerchar()����
		//getchar��stdio���ж��ַ�, getchar��һ��int�͵ķ���ֵ.
		//���������getcharʱ.����͵����û�����.�û�������ַ�������ڼ��̻�������.
		//ֱ���û����س�Ϊֹ(�س��ַ�Ҳ���ڻ�������).���û�����س�֮��, 
		//getchar�ſ�ʼ��stdio����ÿ�ζ���һ���ַ�.getchar�����ķ���ֵ���û�����ĵ�һ���ַ���ASCII��
		// ������� - 1, �ҽ��û�������ַ����Ե���Ļ.���û��ڰ��س�֮ǰ�����˲�ֹһ���ַ�,
		//�����ַ��ᱣ���ڼ��̻�������, �ȴ�����getchar���ö�ȡ.Ҳ����˵,
		//������getchar���ò���ȴ��û�����, ��ֱ�Ӷ�ȡ�������е��ַ�, 
		//ֱ���������е��ַ�����Ϊ��, �ŵȴ��û�������

		//EOF
		//��whileѭ������EOF��Ϊ�ļ�������־��������EOF��Ϊ�ļ�������־���ļ���
		//�������ı��ļ������ı��ļ��У����ݶ������ַ���ASCII����ֵ����ʽ��š�
		//����֪����ASCII����ֵ�ķ�Χ��0~255�������ܳ��� - 1����˿�����EOF��Ϊ�ļ�������־��
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
//1.��ɲ�������Ϸ��
void game()
{
	int random = 0;
	int input = 0;
	int i = 0;
	printf("****��Ϸ��ʼ****\n");
	srand((unsigned)time(NULL));//����һ�������
	random = rand() % 100;//������ 0 �� 100 ֮����������
	for(i=0;i<9;i++)
	{
		printf("��¶��٣�\n");
		//scanf("%d",&input);
		std::cin >> input;
		if (input > random)
		{
			printf("��´���\n");
			continue;
		}
		else if (input < random)
		{
			printf("���С��\n");
			continue;
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
	if (i == 9)
		printf("��Ϸʧ��\n");
}
//int main()
//{
//	int choose = 0;
//	int i = 0;
//	printf("�Ƿ���������Ϸ������1��ʼ��0������\n");
//	//scanf("%d", &choose);
//	std::cin >> choose;
//	switch (choose)
//	{
//	case 1:game();
//		break;
//	case 0:exit(0);
//		break;
//	default:
//		printf("�����\n");
//		break;
//	}
//L:system("pause");//�������
//	system("cls");//����
//	printf("�Ƿ������Ϸ��1 ����  ������ �˳���\n");
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
//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
//���ֲ���
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0;

	return 0;
}
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����

//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������

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
//	//printf("���Լ����%d\n",Max);
//	//PrintfStar()
//	//NarcissisticNumber();
//	//printf("%d\n", Test());
//	/*int a = 5;
//	SumSn(5)*/;
