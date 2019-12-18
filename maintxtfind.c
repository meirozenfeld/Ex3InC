#include "txtfind.h"
#include <stdio.h>
int main()
{
    // printf("entered to prog\n");
    // char line[LINE];
    // for(int i = 0; i < 5; i++)
    // {
    //     getLine(line);
    //     printf("%s",line);

    // }
    // char txt;
    // while (txt = getc(stdin))
    // {
    //     getword();
    // }
    char str[WORD];
    getword(str);
    char func[WORD];
    getword(func);
    char line[1];
    getLine(line);
    if(func[0]=='a')
    {
        // printf("entered to a\n");
        print_lines(str);
    }
    else if(func[0]=='b')
    {
        // printf("entered to b\n");
        print_similar_words(str);
    }
    
    return 0;
}
