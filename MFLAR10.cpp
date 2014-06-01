#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
    char str[2500];
    while(gets(str)&&str[0]!='*')
    {
        char *p=strtok(str," ");
        char letter=tolower(str[0]);
        while(p!=NULL)
        {
            if(tolower(*p)!=letter)
                break;
            p=strtok(NULL," ");
        }
        if(p==NULL)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
