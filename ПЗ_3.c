#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int N) 
{
    int *arr = (int*)malloc(N * sizeof(int));
    return arr;
}

void fillArray(int *arr, int N, int l) 
{
	int i;
    if (l == 1) 
	{
        printf("������ %d ��������:\n", N);
        for (i = 0; i < N; i++) 
		{
            scanf("%d", &arr[i]);
        }
    }
    else 
	{
        printf("��������� ����������� %d ��������:\n", N);
        srand(time(NULL));
        for (i = 0; i < N; i++) 
		{
            arr[i] = rand()%(9-0+1) + 0;
        }
       	for(i=0; i<N; i++)
    	{
		    printf("arr[%d] = %d\n", i, arr[i]);
    	}
    }
}

void addElement(int **arr, int *N) 
{
    (*N)++;
    *arr = (int*)realloc(*arr, (*N) * sizeof(int));
    printf("������ ����� �������: ");
    scanf("%d", &((*arr)[*N - 1]));
}

void deleteElement(int **arr, int *N) 
{
    (*N)--;
    *arr = (int*)realloc(*arr, (*N) * sizeof(int));
}

void addElements(int **arr, int *N) 
{
    int M, start, end;
    int i;
    printf("������ ������� �������� ��� ���������: ");
    scanf("%d", &M);
    printf("������ ���������� ������: ");
    scanf("%d", &start);
    printf("������ ������� ������: ");
    scanf("%d", &end);

    (*N) += M;
    *arr = (int*)realloc(*arr, (*N) * sizeof(int));

    for (i = *N - 1; i >= end + M; i--) 
	{
        (*arr)[i] = (*arr)[i - M];
    }

    for (i = start; i <= end && i < *N - M; i++) 
	{
        printf("������ ������� ��� �������: ");
        scanf("%d", &((*arr)[i]));
    }
}

void deleteElements(int** arr, int* N) 
{
    int M, start, end;
    int i;
    printf("������ ������� �������� ��� ���������: ");
    scanf("%d", &M);
    printf("������ ���������� ������: ");
    scanf("%d", &start);
    printf("������ ������� ������: ");
    scanf("%d", &end);

    for (i = start; i <= end && i + M < *N; i++) 
	{
        (*arr)[i] = (*arr)[i + M];
    }

    (*N) -= M;
    *arr = (int*)realloc(*arr, (*N) * sizeof(int));
}

void printArray(int *arr, int N) 
{
	int i;
    printf("�����: [ ");
    for (i = 0; i < N; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() 
{
	system("chcp 1251");
    int N;
    printf("������ ����� ������:");
    scanf("%d", &N);
    int *arr = createArray(N);

    int l;
    printf("�� �������� �����?\n");
    printf("1.���������\n");
    printf("2.���������\n");
    scanf("%d", &l);

    fillArray(arr, N, l);

    while (1) 
    {
        int choice;
        printf("\n������� ��������:\n");
        printf("1. ������ �������\n");
        printf("2. �������� �������\n");
        printf("3. ������ ����� ��������\n");
        printf("4. �������� ����� ��������\n");
        printf("5. �����\n");

        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                addElement(&arr, &N);
                printArray(arr, N);
                break;
            case 2:
                deleteElement(&arr, &N);
                printArray(arr, N);
                break;
            case 3:
                addElements(&arr, &N);
                printArray(arr, N);
                break;
            case 4:
                deleteElements(&arr, &N);
                printArray(arr, N);
                break;
            case 5:
                free(arr);
                return 0;
            default:
                printf("������� ����\n");
        }
    }
}
