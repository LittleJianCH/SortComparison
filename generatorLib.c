#include <stdlib.h>

void generateRandomData(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
}

void generateAlmostSortedData(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    int m = rand() % 10 + 5;
    while (m--) {
        a[rand() % n] = rand() % n;
    }
}

void generateSortedData(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}