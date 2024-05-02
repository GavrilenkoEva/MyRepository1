#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void insertionSort(int arr[], int N) {
    int i, key, j;
    for (i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
	SetConsoleOutputCP(1251);
	
    int N, i;
    printf("Введіть розмір масиву N: ");
    scanf("%d", &N);

    int arr[N];
    srand(time(0));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }


    clock_t start = clock();
    insertionSort(arr, N);
    clock_t end = clock();
    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Час виконання (кращий випадок): %f секунди\n", elapsed_time);

    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    start = clock();
    insertionSort(arr, N);
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Час виконання (гірший випадок): %f секунди\n", elapsed_time);

    return 0;
}

