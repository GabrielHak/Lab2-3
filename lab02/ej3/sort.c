#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
    unsigned int piv = izq;
    int i = izq+1;
    int j = der;
    while(i <= j){
        printf("I: %d J: %d\n",i,j);
        if(goes_before(a[i], a[piv])) i++;
        if(!goes_before(a[j], a[piv]) || a[j] == a[piv]) j--;
        if((!goes_before(a[i], a[piv]) || a[i] == a[piv] ) && goes_before(a[j], a[piv]) && i <= j){
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, piv, j);
    piv = j;

    return piv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /*needs implementation */

    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */
    if(der > izq){
        unsigned int piv = partition(a, izq, der);
        
        quick_sort_rec(a, izq, piv);
        quick_sort_rec(a, piv+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

