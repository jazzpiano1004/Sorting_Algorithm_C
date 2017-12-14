/**
  * sorting_bubbleSort.c - bubble sort implementation in C.
  *
  * Written in 2017 by Nattapong W. <https://github.com/jazzpiano1004>.
  *
  * To the extent possible under law, the author(s) have dedicated all
  * copyright and related and neighboring rights to this software to
  * the public domain worldwide. This software is distributed without
  * any warranty.
  *
  */

#include "sorting_bubbleSort.h"

/* static function prototyping for sorting_bubbleSort.c */
static void swap_dataType_int32(int32_t* a, int32_t* b);
static void swap_dataType_float32(float* a, float* b);

/**
  * @brief  sortingAlgorithm_bubbleSort_int32() : This function is used to sort a data array (int32_t type) by using bubble sort algorithm.
  * @param  sortData : data array which you want to sort.
  * @param  sizeOfSortData  : number of elements in sortData.
  * @param  sortDirection   : sort direction. Sort with a direction "from-less-to-most" by make sortDirection = SORT_DIRECTION_LESS_TO_MOST
  *                                           Sort with a direction "from-most-to-less" by make sortDirection = SORT_DIRECTION_MOST_TO_LESS
  * @retval None
  */
void sortingAlgorithm_bubbleSort_int32(int32_t *sortData, uint32_t sizeOfSortData, int8_t sortDirection)
{
    int32_t surfacePointer = sizeOfSortData-1;
    int32_t sortPointer = 0;
    int8_t sortDirectionDecision = 0;

    while(surfacePointer != 0)
    {
        for(sortPointer=0; sortPointer<surfacePointer; sortPointer++)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)        sortDirectionDecision = (sortData[sortPointer+1] < sortData[sortPointer]);
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)   sortDirectionDecision = (sortData[sortPointer+1] > sortData[sortPointer]);

            if(sortDirectionDecision)
            {
                swap_dataType_int32(&sortData[sortPointer+1], &sortData[sortPointer]);
            }
            else
            {
                // do nothing
            }
        }
        surfacePointer--;
    }
}

/**
  * @brief  sortingAlgorithm_bubbleSort_float32() : This function is used to sort a data array (float type) by using bubble sort algorithm.
  * @param  sortData : data array which you want to sort.
  * @param  sizeOfSortData  : number of elements in sortData.
  * @param  sortDirection   : sort direction. Sort with a direction "from-less-to-most" by make sortDirection = SORT_DIRECTION_LESS_TO_MOST
  *                                           Sort with a direction "from-most-to-less" by make sortDirection = SORT_DIRECTION_MOST_TO_LESS
  * @retval None
  */
void sortingAlgorithm_bubbleSort_float32(float *sortData, uint32_t sizeOfSortData, int8_t sortDirection)
{
    int32_t surfacePointer = sizeOfSortData-1;
    int32_t sortPointer = 0;
    int8_t sortDirectionDecision = 0;

    while(surfacePointer != 0)
    {
        for(sortPointer=0; sortPointer<surfacePointer; sortPointer++)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)        sortDirectionDecision = (sortData[sortPointer+1] < sortData[sortPointer]);
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)   sortDirectionDecision = (sortData[sortPointer+1] > sortData[sortPointer]);

            if(sortDirectionDecision)
            {
                swap_dataType_float32(&sortData[sortPointer+1], &sortData[sortPointer]);
            }
            else
            {
                // do nothing
            }
        }
        surfacePointer--;
    }
}

/* All static functions for sorting_bubbleSort.c */
static void swap_dataType_int32(int32_t* a, int32_t* b)
{
    int32_t tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
static void swap_dataType_float32(float* a, float* b)
{
    float tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
