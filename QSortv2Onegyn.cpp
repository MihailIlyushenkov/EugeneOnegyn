#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "textsave.h"

void ArrayOutp(Text* Text);

int comparator(const void* a, const void* b)
{
    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;
    return strcmp(s1, s2);
}

int main(void)
{
    Text MyText = {};

    ReadTextFromFile(&MyText, "EugeneOnegyn.txt");

    ArrayOutp(&MyText);
    printf("----Sorted Text----\n\n");

    qsort(MyText.TextPivots, MyText.NumberOfLines, sizeof(const char*), comparator);

    ArrayOutp(&MyText);
    ClearText(&MyText);
    return 0;
}

void ArrayOutp(Text* Text)
{
    for (int i = 0; i < Text->NumberOfLines; i++)
    {
        printf("%s\n", (Text->TextPivots)[i]);
    }
    printf("\n");
}
