//we are given two sorted arrays we have find their combined median without actually combining them.


//e.g. arr1={1,3,6,8,11,12,13,14}  arr2={2,4,5,7,8,10} output should be 7.5 


#include<iostream>
using namespace std;
int max( int a, int b )           //return greater number
{
    if( a >= b )
    return a;
    else 
    return b;
}
int min( int a, int b )
{
    if( a >= b )				//return smaller number
    return b;
    else 
    return a;
}



float find_med(int size_1, int *arr1, int size_2, int *arr2)
{

	int total =  ( size_1 + size_2 ) / 2 ;			//to calculate number of left indexes in combined array
    
    
    	int x, y;						//x is for array 1 and y is for array 2
    	if( size_1 > size_2 )
    	{
        	y = size_2 / 2;
        	x = total - y;					
    	}
    	else
    	{
        	x = size_1 / 2;
        	y = total - x;
    	}
    
    	float median;

	int flag=0;
    	while(true)
    	{
        	if( arr1[x-1] <= arr2[y] && arr1[x] >= arr2[y-1] )
        	{
            		if( ( size_1 + size_2 ) % 2 == 0 )			// if size is even then the median is avg. of 
                	{							// max and min elements lying on left of break 
                    		int a = max( arr1[x-1], arr2[y-1] );		// of arrays
                    		int b = min( arr1[x], arr2[y] );
                    		median = (float)(a + b) / 2 ;
				flag=1;
                    		break;
                	}
            		else
            		{							// if size is odd then median is min of   
                		int a = min( arr1[x], arr2[y] );		// element lying right of the break of the arrays	
                		median = (float)a;
				flag=1;
                		break;
            		}
        	}
        	if( arr1[x-1] < arr2[y] && arr1[x] < arr2[y-1] )		
        	{
            		y--;
            		x++;
        	}
        	if( arr1[x-1] > arr2[y] && arr1[x] > arr2[y-1] )
        	{
            		y++;
            		x--;
        	}
    	}
	if(flag==1)
    	return median;
	else									// in case if starting of one arrays 
	{									// is greater than the last element of other 
		if( ( size_1 + size_2 ) % 2 == 0 )				//e.g arr1={1,2,3} arr2={4,5,6}
		return (arr1[size_1-1]+arr2[0])/2;
		else
		{
			if( size_1 > size_2)
			{
				return arr1[size_1-1];
			}
			else
			return arr2[0];
		}
	}
}



int main()
{
	int size_1, size_2;


	cout << "Enter the size of first array(sorted)\n";				//scanning size for array 1
	cin >> size_1;
	
	int *arr1 = new int[ size_1 ];

    
    	cout << "Enter the elements\n";						//scanning elements for array1(sorted)
    	for( int i = 0; i < size_1; i++ )
    	{
        	cin >> arr1[i];
    	}

    
    	cout << "Enter the size of second array\n";
	cin >> size_2;								//scanning size for array2
	
	int *arr2 = new int[ size_2 ];
    
    	cout << "Enter the elements of second array(sorted)\n";		 //scanning elements for second array(sorted)
    	for( int i = 0; i < size_2; i++ )
    	{
        	cin >> arr2[i];
    	}

	
    	float median=find_med(size_1,arr1,size_2,arr2);
	cout<<"The median is "<<median;
}
