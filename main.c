#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generatorLib.h"
#include "sortLib.h"
#include "testLib.h"

#define N 30000005

int a[N];

const void (*sortFuncs[])(int*, int) = {stdSort, bubbleSort, selectionSort, insertionSort, mergeSort, quickSort, radixSort};

const char sortFuncNames[][15] = {" stdSort", "bubbleSort", "selectionSort", "insertionSort", "mergeSort", "quickSort", "radixSort"};

const int sortFuncNameLens[] = {7, 10, 13, 13, 9, 9, 9};

const void (*generateFuncs[])(int*, int) = {generateRandomData, generateAlmostSortedData, generateSortedData};

const char generateFuncNames[][25] = {"RandomData:", "AlmostSortedData:", "SortedData:"};

const int dataSize[] = {100, 1000, 10000, 100000};

const int largeDataFuncIds[] = {0, 4, 5, 6};

const int largeDataSize = 3e7;

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

    puts("LargeData:");

    puts("+----------+----------+-----------+-----------+-----------+");

    printf("| dataSize |");
    for (int k = 0; k < 4; k++) {
        int i = largeDataFuncIds[k];
        printf(" %s |", sortFuncNames[i]);
    }
    puts("");

    printf("| %8d |", largeDataSize);

    for (int k = 0; k < 4; k++) {
        int i = largeDataFuncIds[k];
        printf(" %*lf |", sortFuncNameLens[i], testSortFunction(a, largeDataSize, sortFuncs[i], generateRandomData));
    }
    puts("");

    puts("+----------+----------+-----------+-----------+-----------+");

    return 0;
}