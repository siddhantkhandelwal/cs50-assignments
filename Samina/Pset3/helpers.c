// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int Y=fraction[2]-48;
    int X=fraction[0]-48;
    while(Y!=8)
    {
        if(Y>8)
        {
            Y/=2;
            X/=2;
        }
        else
        {
            Y*=2;
            X*=2;
        }
    }
    return X;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char a=note[0];
    int i,n=0,b=0,f=0,fl=0;
    if(note[1]=='b'){fl=1; a=note[0];}
    else if(note[1]=='#'){ fl=1;if(a!='G') a++; else a='A';}
        switch(a)
            {
                case 'B':b=10;f=2;break;
                case 'C':b=9;f=3;break;
                case 'D':b=7;f=5;break;
                case 'E':b=5;f=7;break;
                case 'F':b=4;f=8;break;
                case 'G':b=2;f=10;break;
            }
    if(strlen(note)==2)
    {
        i=note[1]-48;
    }
    else
    {
        i=note[2]-48;
    }
        if(i<=4&&(a!='B'))
        {
            n=n-(12*(4-i))-b;
        }
        else if(i>4&&(a!='B'))
        {
             n=+(12*(i-4-1))+f;
        }
        else if(a=='B')
        {
            if(i<4)
            n=n-(12*(3-i))-b;
            else
            n=n+(12*(i-4))+f;
        }
    if(fl==1)n--;
    float k=(pow(2,((float)n/12)))*440;
    int r=round(k);
    return r;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"\0")==0)
    return 1;
    else return 0;
}
