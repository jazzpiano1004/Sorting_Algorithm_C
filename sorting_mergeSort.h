/**
  * sorting_mergeSort.h - merge sort implementation in C.
  *
  * Written in 2017 by Nattapong W. <https://github.com/jazzpiano1004>.
  *
  * To the extent possible under law, the author(s) have dedicated all
  * copyright and related and neighboring rights to this software to
  * the public domain worldwide. This software is distributed without
  * any warranty.
  *
  */

#ifndef  SORTING_MERGESORT_H
#define  SORTING_MERGESORT_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Defines which are used in merge sort function */
#define SORT_DIRECTION_LESS_TO_MOST     1
#define SORT_DIRECTION_MOST_TO_LESS     -1


/* All merge sort's function */
void sortingAlgorithm_mergeSort_int32(int32_t *sortData, uint32_t sizeOfSortData, int8_t sortDirection);
void sortingAlgorithm_mergeSort_float32(float *sortData, uint32_t sizeOfSortData, int8_t sortDirection);

#endif
