#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int data[10];
int number[8], cnt = 0;

void seq_search()
{//배열 선언하고, 입력받고, 키값받고, 찾고, 출력
	int i, key, count = 0;
	//입력 : 데이터 10개, 키값
	printf("\n 검색 키값 입력 : ");
	scanf("%d", &key);
	//검색
	for (i = 0; i < 10; i++)
	{
		count++;
		if (key == data[i])
			break;
	}
	if (i < 10) //찾았다
		printf("\n %d을 %d번째 위치에서 찾음 : 비교횟수 %d번", key, i+1, count);
	else //못찾았다
		printf("\n %d가 없음 : 비교횟수 %d", key, count);
}

int largest(int low, int high)
{//배열 number[0~7]에서 반씩 쪼개서 최대값을 각각 찾아서 최종 비교한 후 리턴
	int left, right;
	int mid;
	if (high - low == 0) //분할한 갯수가 1개가 되면
		return number[low];
	else //2개 이상이면
	{
		cnt++;
		mid = (low + high) / 2;
		left = largest(low, mid); //왼쪽 사이드에서 최대값 결정
		right = largest(mid+1, high); //오른쪽 사이드에서 최대값 결정
		if (left > right)
			return left;
		else
			return right;
	}
}

void main()
{
	int i, menu;
	printf("\n 검색대상값 10개 입력 : ");
	for (i = 0; i < 10; i++)
		scanf("%d", &data[i]);
	while (1) //무한루프
	{
		printf("\n\n\n 메뉴 1)순차탐색 2)토너먼트 3)종료 : ");
		scanf("%d", &menu);  
		if (menu == 3) break;
		switch (menu) {
		case 1: //데이터를 배열에 입력하고 원하는 키값을 찾기
			seq_search();
			break;
		case 2:
			printf("\n 최대값 8개 입력 : ");
			for (i = 0; i < 8; i++)
				scanf("%d", &number[i]);
			printf("\n 최대값= %d, 실행횟수=%d", largest(0, 7), cnt);
			break;
		case 3:
			break;
		default: printf("\n 메뉴선택 오류. 다시 선택하시오...\n\n");
		}
	}
}