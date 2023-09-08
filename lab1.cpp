#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void zad1_3() {
	int* arr;
	int n = 0;
	int tempA = -200, tempB = 200;
	printf("������� ������ �������: ");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;

		printf("%d\t", arr[i]);

		if (arr[i] > tempA)
			tempA = arr[i];
		else if (arr[i] < tempB)
			tempB = arr[i];
	}
	printf("\n\n������������: %d\n�����������: %d\n����. - ���. = %d\n", tempA, tempB, tempA - tempB);
}

void zad4() {
	int a,n = 0, m = 0;
	int sum = 0;
	printf("������� ������ �������: ");
	scanf("%d", &a);
	scanf("%d", &m);
	int** arr = (int**)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		arr[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < m; k++) {
			arr[i][k] = rand() % 10;
			printf("%d\t", arr[i][k]);
		}
		printf("\n");
	}
	printf("\n1 - �������, 2 - ������: ");
	scanf("%d", &n);

	if (n == 1) {
		printf("������� ����� �������: ");
		scanf("%d", &n);
		n--;
		for (int i = 0; i < a; i++)
			sum += arr[i][n];
	}
	else {
		printf("������� ����� ������:  ");
		scanf("%d", &n);
		n--;
		for (int i = 0; i < m; i++)
			sum += arr[n][i];
	}
	printf("\n�����: %d\n",sum);
	for (int i = 0; i < a; i++) {
		free(arr[i]);
	}
	free(arr);
}

void zad5() {
	int num = 0, count = 0;
	char search[20] = {0};
	struct student
	{
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	};
	struct student stud[4];
	stud[0] = {"������","������","���", 1};
	stud[1] = { "�������","�����","���", 2 };
	stud[2] = { "������","�����","����", 3 };

	for (int i = 0; i < 3; i++)
	{
		printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[i].famil, stud[i].name,
			stud[i].facult, stud[i].Nomzach);
	}

	printf("\n\n����� ��: 1-�����, 2-�������, 3-����������, 4-�������\n");
	scanf("%d",&num);
	switch (num) {
	case 1:
		printf("������� ��� �������� \n"); scanf("%20s", stud[4].name);
		for (int k = 0; k < 3; k++)
		{
			if (strcmp(stud[4].name, stud[k].name) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[k].famil, stud[k].name,
					stud[k].facult, stud[k].Nomzach);
				count++;
			}
		}
		break;
	case 2:
		printf("������� ������� ��������\n"); scanf("%20s", stud[4].famil);
		for (int k = 0; k < 3; k++)
		{
			if (strcmp(stud[4].famil, stud[k].famil) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[k].famil, stud[k].name,
					stud[k].facult, stud[k].Nomzach);
				count++;
			}
		}
		break;
	case 3:
		printf("������� �������� ���������� ��������\n"); scanf("%20s", stud[4].facult);
		for (int k = 0; k < 3; k++)
		{
			if (strcmp(stud[4].facult, stud[k].facult) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[k].famil, stud[k].name,
					stud[k].facult, stud[k].Nomzach);
				count++;
			}
		}
		break;
	case 4:
		printf("������� ����� �������� ������ �������� \n"); scanf("%d", &stud[4].Nomzach);
		for (int k = 0; k < 3; k++)
		{
			if (stud[k].Nomzach == stud[4].Nomzach) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[k].famil, stud[k].name,
					stud[k].facult, stud[k].Nomzach);
				count++;
			}
		}
		break;
	}
	if (count == 0)
	printf("\n������ �� �������\n");
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int c = -1;
	bool close = false;
	while (!close) {
		do {
			printf("[1]������� 1-3.\n[2]������� 4.\n[3]������� 5.\n\n\n[0]�����.\n");
			scanf("%d", &c);
			system("cls");
		} while (c < 0 || c > 3);
		
		switch (c) {
		case 1:
			zad1_3();
			system("pause");
			system("cls");
			break;
		case 2: 
			zad4();
			system("pause");
			system("cls");
			break;
		case 3:
			zad5();
			system("pause");
			system("cls");
			break;
		case 0:
			close = true;
			break;
		}
	}
	return 0;
}
