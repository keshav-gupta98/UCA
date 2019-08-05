//we have to swap adjacent bits of a given number

#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the number\n";
    int n;
    cin >> n;
    
    // our loop will terminate when i+1=7 because we have an intger 8 bits ( index starting from 0 )

    //we will check whether adjacent bits are different or not ,if they are then we will toggle them.
    for( int i = 0; i < 7; i = i + 2 )
    {
        if( ( n & ( 1 << ( i ) ) ) ^ ( n & ( 1 << ( i + 1 ) ) ) != 0 )			//checking whether adjacent bits are differnet ot not
        {										//the value of X-Or will be non-zero

            n = n ^ ( 1 << i );								//toggling bit at ith position 

            n = n ^ ( 1 << ( i + 1 ) );							//toggling bit at (i+1)th position
        }
    }
    
    cout << "The number after swapping adjacent bits is \n";
    cout << n << endl;
}
