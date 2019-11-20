// It will return the starting index of b in string if it b is a substring a
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int func(char *a, char *b)
{
    int m = strlen(a);
    int n = strlen(b);
    int i =0;
    while(  i < m )
    {
        int temp = i;
        int j =0;
        while( j < n )
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            if( j == n )
            {
                return i - j;
            }
            if( a[i] != b[j])
            {
                i = temp;
                i++;
                break;
            }
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
    printf("%d",c);
    return 0;
}
