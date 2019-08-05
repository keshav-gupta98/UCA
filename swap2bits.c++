// in a given number we have to swap 2 bits at specified position


#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the number\n";
    int n;
    cin >> n;

    cout << "Enter the position of two bits to swap\n";
    int i,j;
    cin >> i;
    cin >> j;


    //swapping bits only when the bits at sspecified position are differnt
    //checking whether the value of bits at specified positions are different or not

    if( ( ( n & ( 1 << ( i - 1 ) ) )  ^ ( n & ( 1 << ( j - 1 ) ) ) )!= 0 )	//the value of exor will be not equal to zero if two bits are	
    {										// differnt
	
        n = n ^ (1 << ( i - 1) );						// toggling bit at position i-1 as index starts from 0


        n = n ^ (1 << ( j - 1) );						// toggling bit at position j-1 as index starts from 0
    }

    cout << "The new number after swapping bits is\n";
    cout << n << endl;
    return 0;
}

