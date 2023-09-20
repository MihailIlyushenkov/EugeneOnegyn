#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


void Sort(void* Data, size_t VolumeSize, size_t ElementSize, int (*comparefunction) (const void *, const void *));

void swap(void* a, void* b, size_t size);
void ArrayOutp(const char ** Data, size_t size);

// void qsort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));



int comparator(const void* a, const void* b)
{
    // if (*(int*)a > *(int*)b)
    // printf("%p %p\n"); // &Data[i]

    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;

    return strcmp(s1, s2);
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

void MyFunction(void* Data, size_t ElementSize)
{
    printf("\nIN FUNCTION\n");
    printf("(void) Data value in function is %p\n", Data);
    // ElementSize
    printf("2nd Element of data position is %p\n", Data + ElementSize);
    printf("2nd Element of data is %s\n", *( (char**) Data + ElementSize));
    printf("lol");
}

int main(void)
{
    printf("%zu %zu %zu\n", sizeof(char), sizeof(char*), sizeof(double));
    char* a = "eeagnpige";
    printf("a is %p\n", a);
    char* b = "eigjqwegqi";
    printf("b is %p\n", b);
    char* c = "eginegj";
    printf("c is %p\n", c);
    char* d = "qpegiegiq";
    printf("d is %p\n", d);
    const char* Data[4] = {0};

    Data[0] = a;
    Data[1] = b;
    Data[2] = c;
    Data[3] = d;

    printf("Datas values poniters: ");
    printf("%p\n", Data);
    printf("%p\n", Data+1);
    printf("%p\n", Data+2);
    printf("%p\n", Data+3);



    for (int i = 0; i < 4; i++)
    {
        printf("pointer to Data[%d] = %p\n", i, *(Data+i));
    }

    printf("Data position is %p\n", Data);
    printf("2nd Element of data position is %p\n", Data + sizeof(char*));
    printf("2nd Element of data is %s\n", *(Data + 1));
    MyFunction(Data, sizeof(char*));

    size_t size = 4;

// ArrayOutp(Data, size);
    // char * string1 = "rwjhgowrhgo";
    // char * string2 = "abcdefgijkl";
    // int a = 1583;
    // int b = 31083;

    // swap(&string1, &string2, sizeof(char*));
// Sort(Data, size, sizeof(char*), comparator);
    // printf("a is %s, b is %s", string1, string2);
    // qsort(Data, size, sizeof(const char*), comparator);

// ArrayOutp(Data, size);
}
/*
void Sort(void* Data, size_t VolumeSize, size_t ElementSize, int (*comparefunction) (const void *, const void *))
{
    printf("---NEW SORT ITERATION---\n");

    int left = 0;
    int right = ElementSize*(VolumeSize-1);
    char* Data_start_position = (char*) Data;

    int mid = (int) Data + (ElementSize*VolumeSize)/2;

    printf("mid value is %d, mid pos is %d\n", *((int) Data + VolumeSize/2), VolumeSize/2);
    // ArrayOutp(Data, VolumeSize);

    do
    {
        while comparefunction(mid, Data[left]) //(Data[left] < mid)
        {
            left += ElementSize;
        }

        while comparefunction(Data[right], mid)
        {
            right -= ElementSize;
        }
        if (left <=right)
        {
            swap(&(Data + left), &(Data + right), ElementSize);
            left += ElementSize;
            right -= ElementSize;
        }

    } while(left <= right);

    ArrayOutp(Data, VolumeSize);

    if (right > 0)
    {
        Sort(Data, right + 1, sizeof(char*), comparator);
    }

    if (left < VolumeSize)
    {
        Sort(&Data[left], VolumeSize - left, sizeof(char*), comparator);
    }
}

void ArrayOutp(const char** Data, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s ", Data[i]);
    }
    printf("\n");
}
*/
