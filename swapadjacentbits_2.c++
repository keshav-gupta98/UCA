//we have to swap adjacent bits of a given number

#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the number\n";
    int n;
    cin >> n;
    
    int x = ( n >> 1 ) & 0x55555555;
    int y = ( n << 1 ) & 0xAAAAAAAA;
    
    cout << ( x | y );
}
