#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int SetMoney[4] = { 0, };
int MonthArray[12] = { 0, };
int MonthPrice[12] = { 0, };
int TotalMinMoney = 0;

void minPrice(int month, int cost);

int main()
{
	int Tcount;
	printf("T�� ���� �Է��ϼ���");
	scanf_s("%d", &Tcount);
	printf("%d\n", Tcount);

	for (int i = 0; i < Tcount; i++)
	{
		printf("���� 4��\n");
		for (int j = 0; j < 4; j++)//�� �� �� 3�� 1�� �������� ���� ���ϱ�
		{

			scanf_s("%d", &SetMoney[j]);
		}
		for (int j = 0; j < 4; j++)//�� �� �� 3�� 1�� �������� ���� ���ϱ�
		{

			printf("%d", SetMoney[j]);
		}
		printf("�޺� ��� 12��\n");
		for (int j = 0; j < 12; j++)
		{

			scanf_s("%d", &MonthArray[j]);
			if (SetMoney[0] * MonthArray[j] >= SetMoney[1])// 1�ϱǰ� �Ѵޱ� �� ���
			{
				MonthPrice[j] = SetMoney[1];
			}
			else
			{
				MonthPrice[j] = SetMoney[0] * MonthArray[j];
			}

		}
		TotalMinMoney = SetMoney[3];
		minPrice(0, 0);
		printf("#%d %d", i + 1, TotalMinMoney);
		TotalMinMoney = 0;

	}

	return 0;

}

void minPrice(int month, int cost)
{
	if (month >= 12) //���� ���� 12���� �ʰ��Ǹ� return���� ������.
	{
		if (TotalMinMoney > cost)
		{
			TotalMinMoney = cost;
		}
		return;
	}

	if (MonthArray[month] == 0) //�ش���� ����� ���� �� ������ �� �Ѿ
	{
		minPrice(month + 1, cost);
	}

	minPrice(month + 3, cost + SetMoney[2]); // 3�ޱ��� �߰�
	minPrice(month + 1, cost + MonthPrice[month]);//�Ϸ�ǰ� �Ѵޱ��� �������� ����� �迭 ��


}