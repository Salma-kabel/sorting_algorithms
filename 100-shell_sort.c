#include "sort.h"

void shell_sort(int *array, size_t size)
{
    int h = 1;
    size_t i, j;
    int tmp;

    if (array == NULL || size < 2)
        return;

    /* Generate the Knuth sequence */
    while (h < (int)size/3)
        h = 3 * h + 1;

    /* Start with the largest gap and work down to a gap of 1 */
    while (h >= 1)
    {
        /* Do a gapped insertion sort for this gap size */
        for (i = h; i < size; i++)
        {
            /* Save array[i] in tmp and make a hole at position i */
            tmp = array[i];

            /* Shift earlier gap-sorted elements up until the correct location for array[i] is found */
            for (j = i; j >= h && array[j - h] > tmp; j -= h)
                array[j] = array[j - h];

            /* Put tmp (the original array[i]) in its correct location */
            array[j] = tmp;
        }

        print_array(array, size);
        h /= 3;
    }
}
