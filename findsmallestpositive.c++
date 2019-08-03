//we have an array of integers .we have to find the smallest positive intger missing
//e.g. {2,3,-7,6,8,-10,-6}  so output should be 1 as 1 missing.
// e.g. {-8,7,1,-10,3,2)  so output should be 4
#include <iostream>
#include<vector>



using namespace std;
int pos( int x )                                                          //function to return absolute value
{
    if( x < 0 )
    return -x;
    else
    return x;
}





int main()
{
    vector< int > v ;
    int size;
    cin >> size;
    for ( int i = 0; i < size; i++ ) 
    {
        int a;
        cin >> a;
        v.push_back( a );                                                    //scanning the elements 
    }



    int j = 0;
    for ( int i = 0; i < size; i++ ) 
    {
        if(v[ i ] < 0)
        {
            int temp = v[ i ];						    //removing the negative integers
            v[ i ] = v[ j ];
            v[ j ] = temp;
            j++;
        }
    }
    v.erase( v.begin(), v.begin() + j );


    for( int i = 0; i < v.size(); i++ )
    {
        if( pos( v[ i ] ) - 1 < size && v[ pos( v[ i ] ) - 1] > 0)
        {
            v[ pos(v[ i ]) - 1 ] =-v[ pos( v[ i ] ) - 1] ;	
        }
    }


    int flag = 0;
    for( int i = 0; i < v.size(); i++ )
    {								//checking whether still a positive intger exists
        if( v[ i ] > 0 )
        {
            cout << i + 1;
            flag = 1;
            break;
        }
    }


    if( flag == 0 )
    cout << size + 1;			//if all intgers are present then size+1 the next to greatest intger should be answer
    return 0;
}

