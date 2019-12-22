#ifndef _txtfind_h_
#define _txtfind_h_
// int getLine(char s[]);
int getword(char w[]);
int substring(char* str1, char* str2);
int similar_one (char *s, char *t);
void print_lines(char *str);
void print_similar_words(char* str);
#define LINE 256
#define WORD 30
#endif