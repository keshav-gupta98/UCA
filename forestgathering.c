/*
Chef is the head of commercial logging industry that recently bought a farm containing N trees. You are given initial height of the i-th tree by Hi and the rate of growth of height as Ri meters per month. For simplicity, you can assume that all the trees are perfect cylinders of equal radius. This allows us to consider only the height of trees when we talk about the amount of wood.

In Chef's country, laws don't allow one to cut a tree partially, so one has to cut the tree completely for gathering wood. Also, laws prohibit cutting trees of heights (strictly) lower than L meters.

Today Chef received an order of W meters (of height) of wood. Chef wants to deliver this order as soon as possible. Find out how minimum number of months he should wait after which he will able to fulfill the order. You can assume that Chef's company's sawing machines are very efficient and take negligible amount of time to cut the trees. */



#include<stdio.h>
#include<stdlib.h>


long func( long long n, long long w, long long l, long long *arr, long long *growth )
{
    long long left = 0;
    long long right = 1000000000000000000;		
    long long mid;
    long long sum = 0;
    while( left < right )
    {
        mid = ( left + right ) / 2;
        sum = 0;
        for( int i = 0; i < n; i++ )
        {
            if( arr[ i ] + ( growth[ i ] * mid ) >= l )
            {
                sum += arr[ i ] + (growth[ i ] * mid);
                if( sum >= w )
                    break;
            }
        }
        if( sum >= w )
        right = mid;
        else
        left= mid + 1;
    }
    return left;
}
int main()
{
    long long n;
    long long w;
    long long l;
    printf( "Enter the number of trees\n" );
    scanf( "%lld", &n );				
    printf( "Enter the wood required\n" );
    scanf( "%lld",&w );
    printf( "Enter the minimum height of tree to cut\n" );
    scanf( "%lld",&l );


    long long *arr = ( long long* )malloc( sizeof( long long ) * n );
    long long *growth = ( long long* )malloc( sizeof( long long ) * n );
    long long i;
    for( int i = 0; i < n; i++ )
    {
	printf( "Enter the initial height of tree\n" );
        scanf("%lld",&arr[i]);
	printf( "Enter the growth of tree per month\n" );	
        scanf( "%lld",&growth[ i ] );
    }


    long months = func( n, w, l, arr, growth );				//calling function which will calculte months required
    printf( "The month required are %ld\n",months );
}
