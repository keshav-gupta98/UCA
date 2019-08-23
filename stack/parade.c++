#include <iostream>
#include<stack>
#include<vector>
using namespace std;


int main()
{
    int n;
    cout << "Enter the number of trucks\n";
    cin >> n;
    
    if(n==1||n==2)
    {
    	cout << "yes";
    }
    
    else
    {
    	stack< int >s1;
    	stack< int >s2;
    	int *arr = new int[ n ];
    	for( int i = 0; i < n; i++ )
    	{
    		cin >> arr[ i ];
    	}    
    	int i = 0;
    	int curr = 1;
    	while( curr != n + 1 )
    	{
        	if( arr[ i ] == curr )
        	{
            		s1.push( curr );
            		curr++;
            		i++;
        	}
        	else 
        	{		
            		if( !s2.empty() && curr == s2.top() )
            		{
                		s2.pop();
                		s1.push( curr );
                		i++;
                		curr++;
            		}
            		else 
            		{
                		if( !s2.empty() && i < n )
                		{
                    			s2.push( arr[ i ] );
                    			i++;
                		}
                		else if( s2.empty() && i < n )
                		{
                    			s2.push( arr[ i ] );
                    			i++;
                		}
                		else
                		{
                    			curr++;
                		}
            		}
        	}
    	}
    	int top = n;
    	int count = 0;
   	while( !s1.empty() )
    	{
        	if( top == s1.top() )
        	{
            		count++;
        	}
        	s1.pop();
        	top--;
    	}
    	if( count == n )
    	cout << "yes";
    	else
   	cout << "no";
    }
    return 0;
}

