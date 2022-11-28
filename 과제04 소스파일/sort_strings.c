#include <stdio.h>

void sort_strings(char *s[], int size)
{
    char *temp[] = {};
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(strcmp(s[j], s[j+1]) > 0)
            {
                temp[0] = s[j];
                s[j] = s[j+1];
                s[j+1] = temp[0];
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%s\n", s[i]);
    }
}

int main()
{
    char *strings[] = {
        "mycopy",
        "src",
        "dst",
    };

    int size = sizeof(strings)/sizeof(strings[0]);

    sort_strings(strings, size);

    return 0;
}