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
	A *ptr=&a;//구조체 포인터형
	struct Atag *pp=&b;
	//*(arr+i) == arr[i]
	// (*ptr).멤버변수  == ptr->멤버변수
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
//구조체 안에 선언된 변수를 구조체 멤버라고 부른다.
typedef struct point Point;

int main()
{
	unsigned int a;//0~
	UINT b;

	struct point pos1;
	//멤버에 접근연산자 .
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
//구조체(struct) : 변수(기본형변수,포인터변수, 배열변수)들을 사용자가 원하는대로 모아놓은 집합
//배열 : 동일한 데이터타입의 집합
#include<stdio.h>
//새로운데이터 타입을 만듭니다.

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
	printf("%d\n", sizeof(str));//12+1('\0') 널문자포함해서 총13

	//문자열관련함수
	//문자열의 길이정보(실제 글자수)를 리턴
	int n=strlen(str);
	printf("length : %d\n", n);

	//문자열 복사
	char str1[] = "String!";
	char str2[10];
	char str3[10];
	//strcpy(str2, str1);
	strcpy_s(str2,sizeof(str2), str1);
	puts(str2);
	//원하는개수만큼만 복사진행
	//개수가 문자열표현 범위보다 작으면 문자열 제대로 적용되지 않는다(널문자 미포함)
	//strncpy(str3, str1, sizeof(str3));
	strncpy_s(str3,sizeof(str3), str1, sizeof(str1));
	puts(str3);

	//문자열 덧붙이기
	char str4[20] = "first";
	char str5[] = "second";
	strcat(str4, str5);//firstsecond\0 
	puts(str4);

	strncat(str4, str5, 3);//덧붙이는 최대글자수 지정가능
	puts(str4);

	//문자열비교하기
	char str6[] = "the";
	char str7[] = "the";//116
	char str8[] = "uhe";//117
	char str9[] = "she";//115
	char str10[] = "rhe";//114
	printf("%d\n", strcmp(str6, str7) );//같으면 0
	printf("%d\n", strcmp(str6, str8)); //다르면 -1
	printf("%d\n", strcmp(str6, str9)); //다르면 1
	printf("%d\n", strcmp(str6, str10)); //다르면 1

	if ( strcmp(str6, str6) == 0) {
		puts("같다");
	}
	else {
		puts("다릅니다.");
	}



	return 0;
}
//*/
/*
#include<stdio.h>
//2차원배열 포인터 타입으로 파라미터변수
// int* arr[3]: 포인터배열선언 ---> int** ptr
// int (*ptr)[3] : type정보, 포인터변수, 열정보

// 2차원배열의 포인터형 : int(*ptr)[3] ---> int ptr[][3]
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
	// 2차원배열={1차원배열, 1차원배열}
	//    arr1 ={ arr1[0], arr1[1] }      
	int arr2[3][3] = { 11,12,13,14,15,16,17,18,19 };
	//2차원배열의 열의 정보같으면  포인터타입이 같다.
	//int ptr1[][3]; 초기화리스트적용시 생략가능
	
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
//3차원 배열 구조
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
	//{ar[0], ar[1]} : 2차원배열이름
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
	//2차원배열으 생략표현은 행은 생략불가..
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[2][3];//저장할 공간만 생성
	int arr1[2][3] = {1,2,3,4,5,6};
	int arr2[][3] = { {1,2,3},{4,5,6} };
	int arr3[][3] = { {1,2,3},{4,5} };//1,2,3, 4,5,0
	int arr4[][3] = { {1,2},{4,5} };//1,2,0, 4,5,0
	//2차원배열선언시 열정보는 필수(생략불가)
	//arr[0][0], arr[0][1], arr[0][2]
	//arr[1][0], arr[1][1], arr[1][2]

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			//printf("%d ", arr[i][j]);// 쓰레기 값이 출력
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
void arrDisplay(int ptr[], int size) {//배열의 시작주소를 저장한 포인터변수
	//int i;
	for (int i = 0; i < size ; i++) {
		//printf("%d ", *(ptr + i)); // *(ptr + i) == ptr[i]
		printf("%d ", ptr[i]);
	}
	puts("");
}

void arrDisplay2(int ptr[]) {//배열의 시작주소를 저장한 포인터변수
	//int i;
	for (int i = 0; i < 5; i++) {
		//printf("%d ", *(ptr + i)); // *(ptr + i) == ptr[i]
		printf("%d ", ptr[i]);
	}
	puts("");
}

//1차원배열의 포인터형에는 사이즈 정보는 없다..
//다른함수에 배열을 넘길때, 사이즈정보도 같이 보내주면 좀더 편리..

int main() {
	int arr[3] = { 10,20,30 };
	arrDisplay(arr, 3);//arr이저장하고있느거는 첫번째주소

	int a=100;
	int* p=&a;//변수의 주소저장한 포인터변수

	//arrDisplay(&a);

	int bbb[5] = { 100,200,300,400,500 };
	arrDisplay(arr, 5);
	//arrDisplay2(bbb);
	///
	/// 
	/// 포인터 1차원배열 int** ptr; 
	/// //////////////////////////////


	return 0;
}
//*/

