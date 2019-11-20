// A string is called a panagram if it containsa all alphabets[a-z] in it
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d",&n); // NUMBER OF TEST CASes
    for(int j = 0 ; j < n+1 ; j++)
    {
        char s[100000];             // input string
        fgets(s,100000,stdin);
        int a[26];
        for(int i = 0 ; i < 26 ; i++)
        {
            a[i] = 0;
        }
        for(int i = 0 ; i < strlen(s) ; i++)
        {
            if(s[i]>=90&&s[i]<=122)
            {
                a[(int)s[i]-97] = 1;
            }
        }
        int count = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(a[i] == 1)
            count++;
        }
        if(j!=0)
        {
        if(count==26)                   // if string is panagram
        printf("1");
        else  {                         // if string is not panagram
        printf("0");
        }
        }
    }
    return 0;
}