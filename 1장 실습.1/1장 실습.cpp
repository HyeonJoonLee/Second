#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int data[10];
int number[8], cnt = 0;

void seq_search()
{//�迭 �����ϰ�, �Է¹ް�, Ű���ް�, ã��, ���
	int i, key, count = 0;
	//�Է� : ������ 10��, Ű��
	printf("\n �˻� Ű�� �Է� : ");
	scanf("%d", &key);
	//�˻�
	for (i = 0; i < 10; i++)
	{
		count++;
		if (key == data[i])
			break;
	}
	if (i < 10) //ã�Ҵ�
		printf("\n %d�� %d��° ��ġ���� ã�� : ��Ƚ�� %d��", key, i+1, count);
	else //��ã�Ҵ�
		printf("\n %d�� ���� : ��Ƚ�� %d", key, count);
}

int largest(int low, int high)
{//�迭 number[0~7]���� �ݾ� �ɰ��� �ִ밪�� ���� ã�Ƽ� ���� ���� �� ����
	int left, right;
	int mid;
	if (high - low == 0) //������ ������ 1���� �Ǹ�
		return number[low];
	else //2�� �̻��̸�
	{
		cnt++;
		mid = (low + high) / 2;
		left = largest(low, mid); //���� ���̵忡�� �ִ밪 ����
		right = largest(mid+1, high); //������ ���̵忡�� �ִ밪 ����
		if (left > right)
			return left;
		else
			return right;
	}
}

void main()
{
	int i, menu;
	printf("\n �˻���� 10�� �Է� : ");
	for (i = 0; i < 10; i++)
		scanf("%d", &data[i]);
	while (1) //���ѷ���
	{
		printf("\n\n\n �޴� 1)����Ž�� 2)��ʸ�Ʈ 3)���� : ");
		scanf("%d", &menu);  
		if (menu == 3) break;
		switch (menu) {
		case 1: //�����͸� �迭�� �Է��ϰ� ���ϴ� Ű���� ã��
			seq_search();
			break;
		case 2:
			printf("\n �ִ밪 8�� �Է� : ");
			for (i = 0; i < 8; i++)
				scanf("%d", &number[i]);
			printf("\n �ִ밪= %d, ����Ƚ��=%d", largest(0, 7), cnt);
			break;
		case 3:
			break;
		default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
		}
	}
}