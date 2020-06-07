#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void ispis(int a[]);
void bubbleSort(int a[]);
void heapSort(int a[], int n);
void fill(int a[]);
int size = 160000;
int main(void) {
    int t1, t2;
    int* a1 = (int*)malloc(size * sizeof(int));
    int* a2 = (int*)malloc(size * sizeof(int));
    fill(a1);
    fill(a2);
    t1 = clock();
    heapSort(a2, size);
    t2 = clock();
    printf("Vrijeme heapsort: %dms\n", t2 - t1);
    free(a2);
    t1 = clock();
    bubbleSort(a1);
    t2 = clock();
    printf("Vrijeme bubble sort: %dms\n", t2 - t1);
    free(a1);
    return 0;
}
void uhrpi(int a[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[max])
        max = l;
    if (r < n && a[r] > a[max])
        max = r;
    if (max != i)
    {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        uhrpi(a, n, max);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        uhrpi(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        uhrpi(a, i, 0);
    }
}
void ispis(int a[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
void bubbleSort(int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {

            if (a[j + 1] < a[j]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void fill(int a[]) {

    float DG = 5;
    float GG = 500;

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {

        a[i] = DG + (float)rand() / RAND_MAX * (GG - DG);
    }
}
