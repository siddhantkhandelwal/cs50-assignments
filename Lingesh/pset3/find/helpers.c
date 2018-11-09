/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

bool binary_search(int needle, int hay[], int n, int start, int end);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(binary_search(value, values, n, 0, n))
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool binary_search(int needle, int hay[], int n, int start, int end)
{
    if(start > end)
    {
        return false;
    }

    int mid = (start + end) / 2;

    if(needle == hay[mid])
    {
        return true;
    }
    else if(needle < hay[mid])
    {
        return binary_search(needle, hay, n, start, mid - 1);
    }
    else
    {
        return binary_search(needle, hay, n, mid + 1, end);
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(values[j] > values[j + 1])
            {
                int x = values[j];
                values[j] = values[j + 1];
                values[j + 1] = x;
            }
        }
    }
    return;
}
