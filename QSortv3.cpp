#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "textsave.h"

int comparator(const void* a, const void* b)
{

    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;
    int res = strcmp(s1, s2);

    return res;
}

void swap(void* a, void* b, size_t size)
{
    char* a_ptr = (char*) a;
    char* b_ptr = (char*) b;
    size_t i = 0;

    for (char tmp = 0; i < size; i++)
        {
            tmp = a_ptr[i];
            a_ptr[i] = b_ptr[i];
            b_ptr[i] = tmp;
        }
}

void Sort(void* Data, size_t VolumeSize, size_t ElementSize, int (*comparefunction) (const void *, const void *), Text* Text)
{
    if (VolumeSize == 1) return;

    size_t left = 0;
    size_t right = VolumeSize - 1;

    void* mid = (char*)Data + ElementSize * (VolumeSize / 2);

    void* Left_ptr = (char*) Data;
    void* Right_ptr = (char*) Data + right * ElementSize;

    while (left < right)
    {
        // assert(left < Text->NumberOfLines && right < Text->NumberOfLines);
        while (comparefunction(Left_ptr, mid) == -1)
        {
            Left_ptr += ElementSize;
            left++;
            assert(left < Text->NumberOfLines);
        }

        while (comparefunction(Right_ptr, mid) == 1 )
        {
            Right_ptr -= ElementSize;
            right--;
        }

        if (left <= right)
        {
            if (Left_ptr == mid)
            {
                mid = Right_ptr;
            }
            else if (Right_ptr == mid)
            {
                mid = Left_ptr;
            }

            swap(Left_ptr, Right_ptr, ElementSize);
            left++;
            right--;
            Left_ptr += ElementSize;
            Right_ptr -= ElementSize;
        }

    }

    if (right > 0)
    {
        Sort(Data, right + 1, ElementSize, comparator, Text);
    }

    if (left < VolumeSize)
    {
        Sort((char* )Data + left * ElementSize, VolumeSize - left, ElementSize, comparator, Text);
    }
}

char* GetPtr(void* Data, int Index, size_t ElementSize)
{
    return (char*) Data + Index*ElementSize;
}
