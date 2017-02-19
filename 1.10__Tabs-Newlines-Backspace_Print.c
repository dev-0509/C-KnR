#include<stdio.h>
int main(void)
{
    int c=0;
    while((c=getchar())!=EOF){
        if(c=='\t')
            printf("\\t");
        else if(c=='\b')
            printf("\\b");
        else if(c=='\n')
            printf("\\n\n");
        else if(c=='\\')
            printf("\\\\");
        else
            putchar(c);
    }
    putchar('\n');
    return 0;
}
01246128000