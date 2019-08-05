//we have to find whether a number is of pattern 1010101 or 0101010 (usabble bits)

//usable bits that are minimum number of bits used in number representaion e.g 34 -> 00100010 usable bits=6

#include<stdio.h>
int main()
{
    int n;
    printf( "Enter the number to check\n" );
    scanf( "%d",&n );
    
    
    int count =  __builtin_clz( n );				// inbuilt function to count the number of non usable bits
    
    
    int x = n & 0xAAAAAAAA & ~( -1 << ( 32 - count ) );
    int y = n & 0x55555555 & ~( -1 << ( 32 - count ) );
    
    
    if( x == 0|| y == 0 )
    printf( "Yes\n" );
    
    else
    printf( "No\n" );
    
    return 0;
}
