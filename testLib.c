#include <time.h>
#include <stdio.h>

double testSortFunction(int *a, int n, void sort(int*, int), void generate(int*, int)) {
    generate(a, n);

    clock_t start_t = clock();

    sort(a, n);

    clock_t end_t = clock();

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return -1;
        }
    }

    return (double) (end_t - start_t) / CLOCKS_PER_SEC;
}