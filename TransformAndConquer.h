#ifndef TRANSFORMANDCONQUIER_H
#define TRANSFORMANDCONQUIER_h
#include "SortAlgorithms.h"

class TransformAndConquier
{
public:
    /**
     * @brief
     * The Sorted Unique Elements that specify the elements of an array are unique or not
     * has the efficiency of  O(nlogn)
     */
    static bool SortedUniqueElements(int A[], const int size)
    {
        SortAlgorithms::MergeSort(A, size);
        for (int i = 0; i < size - 1; i++)
        {
            if (A[i] == A[i + 1])
            {
                return false;
            }
            return true;
        }
    }

    /**
     * @brief
     * It is an algorithm that calculate the mode of an array and the efficiency of it is O(n)
     */

    static int SortedMode(int A[], const int size)
    {

        SortAlgorithms::MergeSort(A, size);
        int index = 0;
        int modeFrequency = 0;
        int modeValue = A[0];
        while (index < size)
        {
            int runLength = 1;
            int runValue = A[index];
            while (((index + runLength) < size) && A[(index + runLength)] == runValue)
            {
                runLength++;
                if (runLength > modeFrequency)
                {
                    modeFrequency = runLength;
                    modeValue = runValue;
                }
            }
            index += runLength;
        }
        return modeValue;
    }
};

#endif