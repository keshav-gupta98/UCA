// It will return the starting index of b in string if it b is a substring a
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int * func( char *c )
{
    int left = 0;
    int right = 0;
    int *z = (int *)malloc(sizeof( int )*strlen( c ));
    int k = 1;
    for(  k = 1; k < strlen(c) ; k++ )
    {
        if( k > right )
        {
            left = right = k;
            while( right < strlen(c) && c[ right - left] == c[ right ] )
            right++;
            z[ k ] = right - left;
            right--;
        }
        else
        {
            int k1 = k -left;
            if( z[k1] < right -k +1 )
            {
                z[ k1 ] = z[ k ];
            }
            else
            {
                left = right = k;
                while( right < strlen(c) && c[ right - left] == c[ right ] )
                right++;
                z[ k ] = right - left;
                right--;
            }
        }
    }
    return z;
}
int main()
{
    char * a = (char *)malloc(sizeof(char)*200);
    scanf("%s",a);
    char * b = (char *)malloc(sizeof(char)*10);
    scanf("%s",b);
    int size = strlen(b);
    char *c = strcat(b,"$");
    c= strcat(b,a);
    int *arr = (int *)malloc(sizeof(int)*strlen(c));
    arr = func(c);
    int i  =0;
    for( i = 0; i < strlen(c);i++)
    {
        if( arr[i] == size )
        printf("%d ", i - size -1);
    }
    return 0;
}

