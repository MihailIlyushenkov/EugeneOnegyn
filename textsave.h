#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys\stat.h>

struct Text
{
    const char * FileName = NULL;
    size_t NumberOfLines = 0;
    char ** TextPivots = NULL;
    char * Buffer = NULL;
};

void ArrayOutp(Text* Text);

ssize_t MyGetline(char **lineptr, size_t *n, FILE *stream);
char *strdup(const char *str);

int comparator(const void* a, const void* b);
void ReadTextFromFile(Text* Text, const char * Nameoffile);
void ClearText(Text* Text);
int GetTextPivots(Text* Text, size_t nchar);

void Sort(void* Data, size_t VolumeSize, size_t ElementSize, int (*comparefunction) (const void *, const void *), Text* Text);
void swap(void* a, void* b, size_t size);
// void ArrayOutp(const char ** Data, size_t size);

