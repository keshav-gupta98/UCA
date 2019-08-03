//we have a sorted array

// we have to reverse array in groups of given size

// e.g. {1,2,3,4,5,6,7,8,9,10,11}  if k=3  { 3, 2, 1, 6, 5, 4,}

//we will apply 2 pointer technique
#include <iostream>
using namespace std;


void reverse(int *arr, int n, int k) 
{ 
    for (int i = 0; i < n; i += k) 
    { 
        int l = i; 
        int r = min( i + k - 1, n - 1); 							
        while ( l < r ) 
        {
		int temp = arr[ l ];
		arr[ l ] = arr[ r ];
		arr[ r ] = temp;
		l++;
		r--;
	} 
  
    } 
} 
int main()
{
  	int size;
	cout << "Enter the size\n";										//scanning size of array
    	cin >> size;
    	int *arr = new int[ size ];
	cout << "Enter the elements of array\n";
    	for( int i = 0; i < size; i++ )
    	{
        	cin >> arr[ i ];							//scanning elements of array
    	}
    	int k;
		cout << "Enter the size of group\n";
        cin >> k;

        reverse( arr, size, k );


	cout << "Array after reversing groups is:\n";
	cout << "{";
        for ( int i = 0; i <= size-2; i++ )								//printing array 
        cout << " " << arr[i] << ",";
	cout << " " << arr[ size -1 ] << " }"; 
	cout<<"\n";
    	return 0;
}

