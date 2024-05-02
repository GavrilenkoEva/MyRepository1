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
        printf("Введіть %d елементів:\n", N);
        for (i = 0; i < N; i++) 
		{
            scanf("%d", &arr[i]);
        }
    }
    else 
	{
        printf("Випадкове генерування %d елементів:\n", N);
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
    printf("Введіть новий елемент: ");
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
    printf("Введіть кількість елементів для додавання: ");
    scanf("%d", &M);
    printf("Введіть початковий індекс: ");
    scanf("%d", &start);
    printf("Введіть кінцевий індекс: ");
    scanf("%d", &end);

    (*N) += M;
    *arr = (int*)realloc(*arr, (*N) * sizeof(int));

    for (i = *N - 1; i >= end + M; i--) 
	{
        (*arr)[i] = (*arr)[i - M];
    }

    for (i = start; i <= end && i < *N - M; i++) 
	{
        printf("Введіть елемент для вставки: ");
        scanf("%d", &((*arr)[i]));
    }
}

void deleteElements(int** arr, int* N) 
{
    int M, start, end;
    int i;
    printf("Введіть кількість елементів для видалення: ");
    scanf("%d", &M);
    printf("Введіть початковий індекс: ");
    scanf("%d", &start);
    printf("Введіть кінцевий індекс: ");
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
    printf("Масив: [ ");
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
    printf("Введіть розмір масиву:");
    scanf("%d", &N);
    int *arr = createArray(N);

    int l;
    printf("Як створити масив?\n");
    printf("1.Самостійно\n");
    printf("2.Випадково\n");
    scanf("%d", &l);

    fillArray(arr, N, l);

    while (1) 
    {
        int choice;
        printf("\nВиберіть операцію:\n");
        printf("1. Додати елемент\n");
        printf("2. Видалити елемент\n");
        printf("3. Додати кілька елементів\n");
        printf("4. Видалити кілька елементів\n");
        printf("5. Вийти\n");

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
                printf("Невірний вибір\n");
        }
    }
}
