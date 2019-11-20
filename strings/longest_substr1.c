/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void
func (char *c)
{
  int *arr = (int *) malloc (sizeof (int) * strlen (c));
  int i = 1;
  int left;
  int right;
  int count = 0;
  arr[0] = 1;
  for (i = 1; i < strlen (c) - 1; i++)
  {
  	if (strlen(c) % 2 == 0)
	{
	  	left = i;
	  	right = i + 1;
	  	while (c[left] == c[right] && left != -1 && right != strlen (c))
	    {
	      	left--;
	      	right++;
	    }
	  	arr[i] = right - left;
	}
    else
	{
	  	left = i - 1;
	  	right = i + 1;
	  	while (c[left] == c[right] && left != -1 && right != strlen (c))
	    {
	    	left--;
	  		right++;
    	}
		arr[i] = right - left - 1;
	}
  }
  arr[i] = 1;
  for (int j = 0; j <= i; j++)
  printf ("%d ", arr[j]);
}

int main ()
{
  func ("ebabcbacacabcbabe");
  return 0;
}