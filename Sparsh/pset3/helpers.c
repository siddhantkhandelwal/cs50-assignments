// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include <math.h>
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int a=fraction[2]-48;
    int b=fraction[0]-48;
    float x=(float)a;
    float y=(float)b;
    float c=0.0;
    c=y/x;
    float d=c*8;
    int e=(int)d;

    return e;


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char a=note[0];
    int i,n=0,x=0,f=0,g=0;
    if(note[1]=='b')
    {
        g=1; a=note[0];

    }
    else if(note[1]=='#')
    {
        g=1;
        if(a!='G') a++;
        else a='A';

    }
        switch(a)
            {
                case 'B':x=10;f=2;
                break;
                case 'C':x=9;f=3;
                break;
                case 'D':x=7;f=5;
                break;
                case 'E':x=5;f=7;
                break;
                case 'F':x=4;f=8;
                break;
                case 'G':x=2;f=10;
                break;
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
    if(g==1)n--;
    float k=(pow(2,((float)n/12)))*440;
    int fr=round(k);
    return fr;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"\0"))
    return false;
    else
    return true;
}
