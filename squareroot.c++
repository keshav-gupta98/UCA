//we have to find square root of integer given

// if n=26 print 5( floor value of square root of non perfect square)

//using binary search

#include<iostream>
using namespace std;


int find_sqrt( int x )
{	
	if( x == 1)
	return 1;
	
	int i = 0;
	int j = x - 1, mid, sqrt;
	while( i <= j )
	{
		mid = ( i + j )/2;
		if( mid*mid == x )
		{
			return mid;
		}
		if( mid*mid < x )
		{
			sqrt = mid;					
			i = mid + 1;
		}
		else
		{
			j = mid - 1;
		}
	}
	return sqrt;
}


int main()
{
	cout << "Enter the number:\n";
	int n;
	cin >> n;							//scanning the number
	int sqrt = find_sqrt( n );					//calling function
	cout << "The square root of " << n << " is "<<sqrt;
	cout<<"\n";
}
