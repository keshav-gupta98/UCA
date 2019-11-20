#include<stdio.h>
#include<stdlib.h>

int strlength( char *c)
{
	int count=0;
	for( int i = 0; c[i]!='\0';i++)
	{
		count++;
	}
	return count;
}

char *strcopy(char *a, char *b)
{
	int i=0; 
	for(  i = 0; i<strlength(b); i++)
	{
		a[i]=b[i];
	}
	a[i]='\0';
	return a;
}

char *strconcat(char *a,char *b)
{
	int j=strlength(a)-1;
	for(int i=0;i<strlength(b);i++)
	{
		a[j]=b[i];
		j++;
	}
	a[j]='\0';
	return a;	
}

void strreverse(char *arr,int l)
{
	int j=(l/2)+1;
	for( int i = 0; i < j ;i++ )
	{
		char temp=arr[i];
		arr[i]=arr[strlength(arr)-1-i];
		arr[strlength(arr)-1-i]=temp;
	}
}

int strcomp( char *str1, char *str2)
{
	int i = 0;
	while( str1[ i ] != '\0' && str2[ i ] != '\0' )
	{
		if( str1[ i ] == str2[ i ] )
		{
			i++;
			continue;
		return str1[ i ] - str2[ i ];
	}
	if( str1[ i ] != '\0' )
	return 1;
		}
	if( str2[ i ] != '\0' )
	return -1;
	return 0;	
}

char * strstring(char *a, char *b)
{
	int l = strlength( a );
	int r = strlength( b );
	char *c;
	while( *a )
	{	
		char *c = b;
		int count=0;
		if( *a == *c )
		{
			char *d = a;
			while( *a == *c )
			{
				count++;
				c++;
				a++;
			}
			if( count == r )
			{
				return d;
			}
		}
		a++;
	}
	return NULL; 	
}



char * split( char * a )
{
	int start = 0;
	int end = 0;
	char *res = ( char *)malloc( sizeof( char ) * 100 );
	int c = 0;
	while(1)
	{
		while( a[ end ] != ' ' && a[ end ] != '\0' )
		{
			end++;
		}
		res[ c++ ] = a+start;
		if( a[ end ] == '\0' )
		break;
		a[ end ] = '\0';
		start = end + 1;
		end = start;
	}
	return res;
}
int main()
{
 char *a = "Keshav";
 char *b = "Gupta Kesh ava";
 char *c = (char *)malloc(sizeof(char)*100);
 c = split(b);
 while( c!= '\0')
 {
 	printf("%s\n",c);
 	c = split(NULL);
 }
 return 0;
}
