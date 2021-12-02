#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generatorLib.h"
#include "sortLib.h"
#include "testLib.h"

#define N 1000005

int a[N];

void (*sortFuncs[])(int*, int) = {stdSort, bubbleSort, selectionSort, insertionSort, mergeSort, quickSort, radixSort};

char sortFuncNames[][15] = {" stdSort", "bubbleSort", "selectionSort", "insertionSort", "mergeSort", "quickSort", "radixSort"};

int sortFuncNameLens[] = {7, 10, 13, 13, 9, 9, 9};

void (*generateFuncs[])(int*, int) = {generateRandomData, generateAlmostSortedData, generateSortedData};

char generateFuncNames[][25] = {"RandomData:", "AlmostSortedData:", "SortedData:"};

int dataSize[] = {100, 1000, 10000, 100000};

int main() {

    srand(time(0));

    for (int i = 0; i < 3; i++) {
        puts(generateFuncNames[i]);

        puts("+----------+----------+------------+---------------+---------------+-----------+-----------+-----------+");

        printf("| dataSize |");
        for (int k = 0; k < 7; k++) {
            printf(" %s |", sortFuncNames[k]);
        }
        puts("");

        for (int j = 0; j < 4; j++) {
            printf("| %8d |", dataSize[j]);
            for (int k = 0; k < 7; k++) {
                printf(" %*lf |", sortFuncNameLens[k], testSortFunction(a, dataSize[j], sortFuncs[k], generateFuncs[i]));
            }
            puts("");
        }
        
        puts("+----------+----------+------------+---------------+---------------+-----------+-----------+-----------+");

        puts("");
    }
    return 0;
}