#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}
void stdSort(int *a, int n) {
    qsort(a, n, sizeof(int), cmp);
}

static void swap(int *a, int *b) {
    static int t;
    t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                flag = 1;
                swap(&a[j], &a[j - 1]);
            }
        }
        if (flag == 0) break;
    }
}

void selectionSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(&a[k], &a[i]);
    }
}

void insertionSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int k = i, tmp = a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                k = j;
                break;
            }
        }

        for (int j = i; j > k; j--) {
            a[j] = a[j - 1];
        }
        a[k] = tmp;
    }
}

#define N 1000005

void mergeSort(int *a, int n) {
    static int tmp[N];
    if (n == 1) return;
    int m = n / 2;
    mergeSort(a, m); mergeSort(a + m, n - m);

    int *p = a, *q = a + m, *t = tmp;
    while (p != a + m && q != a + n) {
        if (*p < *q) {
            *t++ = *p++;
        } else {
            *t++ = *q++;
        }
    }
    while (p != a + m) *t++ = *p++;
    while (q != a + n) *t++ = *q++;

    p = a; t = tmp;
    while (p != a + n) *p++ = *t++;
}

void quickSort(int *a, int n) {
    if (n <= 1) return;
    int pvt = a[n - 1], pos = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= pvt) {
            swap(&a[pos], &a[i]);
            pos++;
        }
    }

    swap(&a[n - 1], &a[pos]);

    quickSort(a, pos);
    quickSort(a + pos + 1, n - pos - 1);
}