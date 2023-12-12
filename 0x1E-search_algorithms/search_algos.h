#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_array(int *array, size_t first, size_t last);
int binary_recursion(int *array, size_t first, size_t last, int value);

#endif /*SEARCH_ALGOS_H*/
