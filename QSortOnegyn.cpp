#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "textsave.h"

int main(void)
{
    Text MyText = {};

    ReadTextFromFile(&MyText, "EugeneOnegyn.txt");

    ArrayOutp(&MyText);

    Sort(MyText.TextPivots, MyText.NumberOfLines, sizeof(const char*), comparator, &MyText);

    printf("----Sorted Text----\n\n");
    ArrayOutp(&MyText);
    ClearText(&MyText);
    return 0;
}

void ArrayOutp(Text* Text)
{
    for (size_t i = 0; i < Text->NumberOfLines; i++)
    {
        printf("%s\n", (Text->TextPivots)[i]);
    }
    printf("\n");
}

int MyStrcmp(const void* a_ptr,const void* b_ptr)
{
    const char* a = *((const char**) a_ptr);
    const char* b = *((const char**) b_ptr);
    size_t i = 0;
    size_t j = 0;
    printf("comparing strings %s %s\n", a, b);

    while (a[i] != 0)
    {
        i++;
    }

    while (b[j] != 0)
    {
        j++;
    }

    printf("lenghts are %d and %d\n", i, j);

    while ((i > 0) && (j > 0))
    {
        if (a[i] > b[j])
        {
            printf("1\n");
            return 1;
        }

        if (a[i] < b[j])
        {
            printf("-1\n");
            return -1;
        }
        i--;
        j--;
    }

    if ( (i == 0) && (j == 0))
    {
        printf("0\n");
        return 0;
    }

    if (i == 0)
    {
        printf("1\n");
        return 1;
    }
    printf("-1\n");
    return -1;
}
