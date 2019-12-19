#include "txtfind.h"
#include <stdio.h>
int main()
{
    char firstword[WORD];
    char c;
    int i = 0;
    while ((c = getc(stdin)) != '\t' && c != ' ' && c != '\n')//save first wort to check
    {
        firstword[i] = c;
        i++;
    }
    firstword[i] ='\0';
    char option;
    while ((c = getc(stdin)) != '\n') // save a or b option
    {
        if (c == 'a')
        {
            option = 'a';
        }
        if (c == 'b')
        {
            option = 'b';
        }
    }
    switch (option) 
    {
    case 'a':
        print_lines(firstword);
        break;
    case 'b':
        print_similar_words(firstword);
        break;
    default:
        printf("Error");
    }
    return 0;
}
