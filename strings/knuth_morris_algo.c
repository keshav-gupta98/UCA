#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int func(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    int lps[m];
    int i = 0;
    int j = 1;
    lps[0] = 0;
    while( j < m )
    {
        if(b[i] == b[j])
        {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if( i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[ i - 1 ];
            }
        }
    }
    i = 0;
    j = 0;
    while( i < n )
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
        }
        if( j == m)
        {
            return i - j;
        }
        else if( i< n && a[i] != b[j] )
        {
            if( j == 0 )
            i = i+1;
            else
            j = lps[ j - 1 ];
        }
    }
    return -1;
}
int main()
{
    char *a =(char *)malloc(sizeof(char)*1000);
    char *b  = (char *)malloc(sizeof(char)*50);
    scanf("%s %s",a,b);
    int c = func(a,b);
    printf("%d\n",c);
    return 0;
}

