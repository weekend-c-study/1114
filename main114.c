#include<stdio.h>

typedef struct Atag 
{
	int v1;
	float v2;
}A;

int main()
{
	A a;
	a.v1 = 100;

	struct Atag b;
	A *ptr=&a;//����ü ��������
	struct Atag *pp=&b;
	//*(arr+i) == arr[i]
	// (*ptr).�������  == ptr->�������
	printf("%d %d %d\n", a.v1, (*ptr).v1, ptr->v1);

	int n = 10;
	int*p=&n;
	printf("%d\n", *p);

	return 0;
}

/*
#include<stdio.h>
typedef struct point 
{
	int x;
	int y;
}Point;

typedef struct 
{
	char name[20];
	int age;
}Person;

int main() 
{
	struct point p2;
	Point p;

	Person person;
	return 0;
}
//*/

/*
#include<stdio.h>
typedef unsigned int UINT;
struct point {
	int x;
	int y;
};
//����ü �ȿ� ����� ������ ����ü ������ �θ���.
typedef struct point Point;

int main()
{
	unsigned int a;//0~
	UINT b;

	struct point pos1;
	//����� ���ٿ����� .
	pos1.x = 10;
	pos1.y = 20;
	Point pos2;
	pos2.x = 100;
	pos2.y = 200;

	printf("%d\n", pos2.x);
	printf("%d\n", pos2.y);

	return 0;
}
//*/

/*
//����ü(struct) : ����(�⺻������,�����ͺ���, �迭����)���� ����ڰ� ���ϴ´�� ��Ƴ��� ����
//�迭 : ������ ������Ÿ���� ����
#include<stdio.h>
//���ο���� Ÿ���� ����ϴ�.

struct person {
	char name[20];//20
	int age;//4
	double height;//8
};


int main()
{
	struct person man1;
	printf("%d\n", sizeof(struct person));
	printf("%d\n", sizeof(man1));

	return 0;
}
//*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() 
{
	char str[] = "hello world!";
	puts(str);
	printf("%d\n", sizeof(str));//12+1('\0') �ι��������ؼ� ��13

	//���ڿ������Լ�
	//���ڿ��� ��������(���� ���ڼ�)�� ����
	int n=strlen(str);
	printf("length : %d\n", n);

	//���ڿ� ����
	char str1[] = "String!";
	char str2[10];
	char str3[10];
	//strcpy(str2, str1);
	strcpy_s(str2,sizeof(str2), str1);
	puts(str2);
	//���ϴ°�����ŭ�� ��������
	//������ ���ڿ�ǥ�� �������� ������ ���ڿ� ����� ������� �ʴ´�(�ι��� ������)
	//strncpy(str3, str1, sizeof(str3));
	strncpy_s(str3,sizeof(str3), str1, sizeof(str1));
	puts(str3);

	//���ڿ� �����̱�
	char str4[20] = "first";
	char str5[] = "second";
	strcat(str4, str5);//firstsecond\0 
	puts(str4);

	strncat(str4, str5, 3);//�����̴� �ִ���ڼ� ��������
	puts(str4);

	//���ڿ����ϱ�
	char str6[] = "the";
	char str7[] = "the";//116
	char str8[] = "uhe";//117
	char str9[] = "she";//115
	char str10[] = "rhe";//114
	printf("%d\n", strcmp(str6, str7) );//������ 0
	printf("%d\n", strcmp(str6, str8)); //�ٸ��� -1
	printf("%d\n", strcmp(str6, str9)); //�ٸ��� 1
	printf("%d\n", strcmp(str6, str10)); //�ٸ��� 1

	if ( strcmp(str6, str6) == 0) {
		puts("����");
	}
	else {
		puts("�ٸ��ϴ�.");
	}



	return 0;
}
//*/
/*
#include<stdio.h>
//2�����迭 ������ Ÿ������ �Ķ���ͺ���
// int* arr[3]: �����͹迭���� ---> int** ptr
// int (*ptr)[3] : type����, �����ͺ���, ������

// 2�����迭�� �������� : int(*ptr)[3] ---> int ptr[][3]
void disp(int ptr[][3], int rows)
{
	for (int i = 0; i < rows ; i++) {
		for (int j = 0; j < 3; j++) 
		{
			printf("%d ", ptr[i][j]);
		}
		puts("");
	}
	puts("");

}



int main()
{
	int arr1[2][3] = { {1,2,3},{4,5,6} };
	// 2�����迭={1�����迭, 1�����迭}
	//    arr1 ={ arr1[0], arr1[1] }      
	int arr2[3][3] = { 11,12,13,14,15,16,17,18,19 };
	//2�����迭�� ���� ����������  ������Ÿ���� ����.
	//int ptr1[][3]; �ʱ�ȭ����Ʈ����� ��������
	
	printf("arr1 : %d byte\n", sizeof(arr1));
	printf("arr1[0] : %d byte\n", sizeof(arr1[0]));
	printf("arr1[1] : %d byte\n", sizeof(arr1[1]));


	//disp(arr1, 2);
	//disp(arr2, 3);
	disp(arr1, sizeof(arr1)/sizeof(arr1[0]));//24/12
	disp(arr2, sizeof(arr2) / sizeof(arr2[0]));//24/12

	return 0;
}
//*/

/*
#include<stdio.h>
//3���� �迭 ����
int main()
{
	int ar[2][2][3] =
	{ 
		{ 
			{ 1,2,3 }, 
			{ 4,5,6} 
		}, 
		{ 
			{ 7,8,9 }, 
			{10,11,12} 
		} 
	};
	//{ar[0], ar[1]} : 2�����迭�̸�
	//{{ar[0][0], ar[0][1]}, {ar[1][0], ar[1][1]}}
	
	//{
	//	{
	//		{ ar[0][0][0], ar[0][0][1], ar[0][0][2] },
	//		{ ar[0][1][0], ar[0][1][1], ar[0][1][2] }
	//	},
	//	{
	//		{ ar[1][0][0], ar[1][0][1], ar[1][0][2] },
	//		{ ar[1][1][0], ar[1][1][1], ar[1][1][2] }
	//	}
	//}
	

	printf("%d\n", sizeof(ar));
	printf("%d\n", sizeof(ar[0]));
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int ar[] = { 10,20,30 };
	//int arr1[2][3] = { 1,2,3,4,5,6 };
	int arr[][4] = { 1,2,3,4,5,6 };//[2][3], [3][2]
	//2�����迭�� ����ǥ���� ���� �����Ұ�..
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[2][3];//������ ������ ����
	int arr1[2][3] = {1,2,3,4,5,6};
	int arr2[][3] = { {1,2,3},{4,5,6} };
	int arr3[][3] = { {1,2,3},{4,5} };//1,2,3, 4,5,0
	int arr4[][3] = { {1,2},{4,5} };//1,2,0, 4,5,0
	//2�����迭����� �������� �ʼ�(�����Ұ�)
	//arr[0][0], arr[0][1], arr[0][2]
	//arr[1][0], arr[1][1], arr[1][2]

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			//printf("%d ", arr[i][j]);// ������ ���� ���
			//printf("%d ", arr1[i][j]); //123 456
			//printf("%d ", arr2[i][j]); //123 456
			//printf("%d ", arr3[i][j]);//123 450
			printf("%d ", arr4[i][j]);//120 450
		}
		puts("");

	}


	return 0;
}
//*/
/*
#include<stdio.h>
// int* ptr --> int ptr[]
void arrDisplay(int ptr[], int size) {//�迭�� �����ּҸ� ������ �����ͺ���
	//int i;
	for (int i = 0; i < size ; i++) {
		//printf("%d ", *(ptr + i)); // *(ptr + i) == ptr[i]
		printf("%d ", ptr[i]);
	}
	puts("");
}

void arrDisplay2(int ptr[]) {//�迭�� �����ּҸ� ������ �����ͺ���
	//int i;
	for (int i = 0; i < 5; i++) {
		//printf("%d ", *(ptr + i)); // *(ptr + i) == ptr[i]
		printf("%d ", ptr[i]);
	}
	puts("");
}

//1�����迭�� ������������ ������ ������ ����..
//�ٸ��Լ��� �迭�� �ѱ涧, ������������ ���� �����ָ� ���� ��..

int main() {
	int arr[3] = { 10,20,30 };
	arrDisplay(arr, 3);//arr�������ϰ��ִ��Ŵ� ù��°�ּ�

	int a=100;
	int* p=&a;//������ �ּ������� �����ͺ���

	//arrDisplay(&a);

	int bbb[5] = { 100,200,300,400,500 };
	arrDisplay(arr, 5);
	//arrDisplay2(bbb);
	///
	/// 
	/// ������ 1�����迭 int** ptr; 
	/// //////////////////////////////


	return 0;
}
//*/

