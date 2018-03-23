/**
  * sorting_bubbleSort.h - bubble sort implementation in C.
  *
  * Written in 2017 by Nattapong W. <https://github.com/jazzpiano1004>.
  *
  * To the extent possible under law, the author(s) have dedicated all
  * copyright and related and neighboring rights to this software to
  * the public domain worldwide. This software is distributed without
  * any warranty.
  *
  */

#ifndef  SORTING_BUBBLESORT_H
#define  SORTING_BUBBLESORT_H

#include <stdint.h>

/* Defines which are used in bubble sort function */
#define SORT_DIRECTION_LESS_TO_MOST     1
#define SORT_DIRECTION_MOST_TO_LESS     -1


/* All bubble sort's function */
void sortingAlgorithm_bubbleSort_int32(int32_t *sortData, uint32_t sizeOfSortData, int8_t sortDirection);
void sortingAlgorithm_bubbleSort_float32(float *sortData, uint32_t sizeOfSortData, int8_t sortDirection);
<<<<<<< HEAD
=======

>>>>>>> 657581f6c233fc84cdb6cc7bcf4c43f868c13a54
#endif
