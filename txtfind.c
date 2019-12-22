#include "txtfind.h"
#include <stdio.h>
#include <string.h>

// if str2 is contained in str1, 0=false 1=true
int substring(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    if (strlen(str1) < strlen(str2))
        return 0;   //end case
    while (str1[i]) //loop for str1
    {
        if (str1[i] == str2[0]) // start char to compare
        {
            while (str2[j] && str1[i + j] && str2[j] == str1[i + j]) //loop for str2
            {
                j++;
            }
            if (j == strlen(str2))
                return 1;
        }
        i++;
    }
    return 0;
}

//get 2 strings, checks if possible to reach from string s to string t by deletion 1 letter-
//for my program its enough to check with 1 letter
int similar_one(char *s, char *t)
{
    int i = 0;
    int j = 0;
    int ispromoted = 0; // 0=deletion 1 letter, 1=not deletion
    if (strlen(s) > strlen(t)+1)return 0; // end case
    while (s[i] || t[j])
    {
        if (s[i] != t[j] && ispromoted == 1)
            return 0; // if the letters is defferent and we deletion 1 letter already
        if (s[i] != t[j])
        {
            i += 1;
            ispromoted = 1;
        }
        else
        {
            i++;
            j++;
        }
    }
    return 1;
}

//get string and print the lines wherever she appears
void print_lines(char *str)
{
    char x;
    char line[LINE];
    int i = 0;
    while ((x = getc(stdin)) != EOF)
    {
        if(i<LINE) line[i] = x;
        else{printf("Line length is too large");}
        if (line[i] == '\n')
        {
            if (substring(line, str))
                printf("%s", line);
            line[i] = '\0';
            i = -1;
        }
        i++;
    }
}

//get string and print the words wherever she appears (even by deletion 1 letter)
void print_similar_words(char *str)
{
       char x;
    char word[WORD];
    int i = 0;
    while ((x = getc(stdin)) != EOF)
    {
        if(i<WORD)word[i] = x;
        else{printf("Word length is too large");}
        if (word[i] == '\n'||word[i] == '\t'||word[i] == ' ')
        {
            word[i] = '\0';
            if (similar_one(word, str)) printf("%s ", word);
            i = -1;
        }
        i++;
    }
}
