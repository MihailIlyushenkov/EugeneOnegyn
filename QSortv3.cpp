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
    printf("im comparing strings %s and %s    ", s1, s2);
    int res = strcmp(s1, s2);
    if (res == -1)
    {
        res = 0;
    }
    printf("result is %d\n", res);

    return res;
}

void swap(void* a, void* b, size_t size)
{
    // printf("i want to swap pointers: %p - string %s and %p - string %s\n", a, b , *((char**) a), *((char**) b));
    printf("i want to swap strings %s and %s\n", *( (char**) a), *( (char**) b));
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

/*
int main(void)
{
    const char* Data[5] = { "aba",  "daa", "caa", "aaa", "ggggg"};

    size_t size = 5;

    // for (int i = 0; i < size; i++)
    // {
    //     printf("Data[%d] is %p, it points on string %p what is %s\n", i, Data + i, *(Data + i), Data[i]);
    // }

    ArrayOutp(Data, size);

    Sort(Data, size, sizeof(char*), comparator);

    ArrayOutp(Data, size);
}
*/

void Sort(void* Data, size_t VolumeSize, size_t ElementSize, int (*comparefunction) (const void *, const void *), Text* Text)
{
    printf("\n\n\n---NEW SORT ITERATION---\n");

    size_t left = 0;
    size_t right = ElementSize*(VolumeSize-1);

    // printf("Data start is %p\n", Data);

    size_t mid = (size_t) Data + ElementSize*(VolumeSize/2); // проблема вот тут
    (void*) midEL_ptr = calloc(
    // printf("mid is %p\n", mid);

    // ArrayOutp( (const char**) Data, VolumeSize);

    do
    {
        while ( comparefunction((void*) mid, Data + left) )
        {
            left += ElementSize;
            // printf("forward\n");
        }
        // printf("another side\n");

        while ( comparefunction(Data + right, (void*) mid) )
        {
            right -= ElementSize;
            // printf("back\n");
        }
        // printf("swapif\n");
        if (left <=right)
        {
            swap((Data + left), (Data + right), ElementSize);
            left += ElementSize;
            right -= ElementSize;
            ArrayOutp(Text);
        }

    } while(left <= right);

    // ArrayOutp( (const char**) Data, VolumeSize);
    // ArrayOutp(Text);
    if (right > 0)
    {
        Sort(Data, (right/ElementSize) + 1, ElementSize, comparator, Text);
    }

    if (left < VolumeSize)
    {
        Sort(Data + left, VolumeSize - (left/ElementSize), ElementSize, comparator, Text);
    }
}

/*
void ArrayOutp(const char** Data, size_t size)
{
    printf("printig Array with size %zu\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("%s ", Data[i]);
    }
    printf("\n");
}
*/
