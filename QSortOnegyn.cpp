#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "textsave.h"

int main(void)
{
    Text MyText = {};

    ReadTextFromFile(&MyText, "TextFileMk3.txt");

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
