/**
  * sorting_mergeSort.c - merge sort implementation in C.
  *
  * Written in 2017 by Nattapong W. <https://github.com/jazzpiano1004>.
  *
  * To the extent possible under law, the author(s) have dedicated all
  * copyright and related and neighboring rights to this software to
  * the public domain worldwide. This software is distributed without
  * any warranty.
  *
  */

#include "sorting_mergeSort.h"

/* static function prototyping for sorting_mergeSort.c */
static void merge_int32(int32_t *mergedData, int32_t *L, int32_t *R, int32_t l_size, int32_t r_size, int8_t sortDirection);
static void merge_float32(float *mergedData, float *L, float *R, int32_t l_size, int32_t r_size, int8_t sortDirection);

/**
  * @brief  sortingAlgorithm_mergeSort_int32() : This function is used to sort a data array (int32_t type) by using merge sort algorithm.
  * @param  sortData : data array which you want to sort.
  * @param  sizeOfSortData  : number of elements in sortData.
  * @param  sortDirection   : sort direction. Sort with a direction "from-less-to-most" by make sortDirection = SORT_DIRECTION_LESS_TO_MOST
  *                                           Sort with a direction "from-most-to-less" by make sortDirection = SORT_DIRECTION_MOST_TO_LESS
  * @retval None
  */
void sortingAlgorithm_mergeSort_int32(int32_t *sortData, uint32_t sizeOfSortData, int8_t sortDirection)
{
    int32_t mid;
    int32_t l_size;     // size of "Left" sub-array
    int32_t r_size;     // size of "Right" sub-array
    int32_t *R;
    int32_t *L;

    if(sizeOfSortData > 1)
    {
        /* Calculate a position of the middle of input data array which we want to sort */
        mid = sizeOfSortData/2;

        /* Calculate a size of "Left" and "Right" section for sub-array in merge algorithm */
        l_size = mid;
        r_size = sizeOfSortData - l_size;

        /* Declare a sub-array for "Left" and "Right" array with a size equal to l_size and r_size by using "heap" */
        R = (int32_t *)(calloc(r_size, sizeof(int32_t)));
        L = (int32_t *)(calloc(l_size, sizeof(int32_t)));

         /* Copy a data from input data array into a "Left" and "Right" array by using memcpy() function */
        memcpy(L, sortData      , sizeof(int32_t)*l_size);
        memcpy(R, sortData + mid, sizeof(int32_t)*r_size);

        /* Sort both sub-arrays (Left & Right) by using "recursive" call */
        sortingAlgorithm_mergeSort_int32(L, l_size, sortDirection);
        sortingAlgorithm_mergeSort_int32(R, r_size, sortDirection);

        /* Merge 2 sorted sub-arrays together as the result of sort algorithm */
        merge_int32(sortData, L, R, l_size, r_size, sortDirection);

        /* Clear heap */
        free(R);
        free(L);
        R = NULL;
        L = NULL;
    }
    else
    {
        // base condition. when size < 2, do nothing.
    }
}

/**
  * @brief  sortingAlgorithm_mergeSort_float32() : This function is used to sort a data array (float32 type) by using merge sort algorithm.
  * @param  sortData : data array which you want to sort.
  * @param  sizeOfSortData  : number of elements in sortData.
  * @param  sortDirection   : sort direction. Sort with a direction "from-less-to-most" by make sortDirection = SORT_DIRECTION_LESS_TO_MOST
  *                                           Sort with a direction "from-most-to-less" by make sortDirection = SORT_DIRECTION_MOST_TO_LESS
  * @retval None
  */
void sortingAlgorithm_mergeSort_float32(float *sortData, uint32_t sizeOfSortData, int8_t sortDirection)
{
    int32_t mid;
    int32_t l_size;     // size of "Left" sub-array
    int32_t r_size;     // size of "Right" sub-array
    float *R;
    float *L;

    if(sizeOfSortData > 1)
    {
        /* Calculate a position of the middle of input data array which we want to sort */
        mid = sizeOfSortData/2;

        /* Calculate a size of "Left" and "Right" section for sub-array in merge algorithm */
        l_size = mid;
        r_size = sizeOfSortData - l_size;

        /* Declare a sub-array for "Left" and "Right" array with a size equal to l_size and r_size by using "heap" */
        R = (float *)(calloc(r_size, sizeof(float)));
        L = (float *)(calloc(l_size, sizeof(float)));

         /* Copy a data from input data array into a "Left" and "Right" array by using memcpy() function */
        memcpy(L, sortData      , sizeof(float)*l_size);
        memcpy(R, sortData + mid, sizeof(float)*r_size);

        /* Sort both sub-arrays (Left & Right) by using "recursive" call */
        sortingAlgorithm_mergeSort_float32(L, l_size, sortDirection);
        sortingAlgorithm_mergeSort_float32(R, r_size, sortDirection);

        /* Merge 2 sorted sub-arrays together as the result of sort algorithm */
        merge_float32(sortData, L, R, l_size, r_size, sortDirection);

        /* Clear heap */
        free(R);
        free(L);
        R = NULL;
        L = NULL;
    }
    else
    {
        // base condition. when size < 2, do nothing.
    }
}

/* All static functions for sorting_mergeSort.c */
static void merge_int32(int32_t *mergedData, int32_t *L, int32_t *R, int32_t l_size, int32_t r_size, int8_t sortDirection)
{
    int32_t finger_L = 0;   // finger pointer of "Left" sub-array in a previous call
    int32_t finger_R = 0;   // finger pointer of "Right" sub-array in a previous call
    int32_t i=0;

    /* when both finger pointers have not exceeded the size of each its array yet */
    while((finger_L < l_size) && (finger_R < r_size))
    {
        if(L[finger_L] < R[finger_R])  //if element at left finger is less than an element at right (L < R)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)
            {
                mergedData[i] = L[finger_L];
                finger_L++;
            }
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)
            {
                mergedData[i] = R[finger_R];
                finger_R++;
            }
            i++;
        }
        else   //if element at left finger is greater than or equal to an element at right (L >= R)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)
            {
                mergedData[i] = R[finger_R];
                finger_R++;
            }
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)
            {
                mergedData[i] = L[finger_L];
                finger_L++;
            }
            i++;
        }
    }

    /* when some finger pointer has already exceeded the size of its array */
    while(finger_L < l_size)
    {
        mergedData[i] = L[finger_L];
        i++;
        finger_L++;
    }
    while(finger_R < r_size)
    {
        mergedData[i] = R[finger_R];
        i++;
        finger_R++;
    }
}

static void merge_float32(float *mergedData, float *L, float *R, int32_t l_size, int32_t r_size, int8_t sortDirection)
{
    int32_t finger_L = 0;   // finger pointer of "Left" sub-array in a previous call
    int32_t finger_R = 0;   // finger pointer of "Right" sub-array in a previous call
    int32_t i=0;

    /* when both finger pointers have not exceeded the size of each its array yet */
    while((finger_L < l_size) && (finger_R < r_size))
    {
        if(L[finger_L] < R[finger_R])  //if element at left finger is less than an element at right (L < R)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)
            {
                mergedData[i] = L[finger_L];
                finger_L++;
            }
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)
            {
                mergedData[i] = R[finger_R];
                finger_R++;
            }
            i++;
        }
        else   //if element at left finger is greater than or equal to an element at right (L >= R)
        {
            if(sortDirection == SORT_DIRECTION_LESS_TO_MOST)
            {
                mergedData[i] = R[finger_R];
                finger_R++;
            }
            else if(sortDirection == SORT_DIRECTION_MOST_TO_LESS)
            {
                mergedData[i] = L[finger_L];
                finger_L++;
            }
            i++;
        }
    }

    /* when some finger pointer has already exceeded the size of its array */
    while(finger_L < l_size)
    {
        mergedData[i] = L[finger_L];
        i++;
        finger_L++;
    }
    while(finger_R < r_size)
    {
        mergedData[i] = R[finger_R];
        i++;
        finger_R++;
    }
}

