// Helper functions for music

#include <cs50.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int a=atoi(fraction);
    int b=atoi(fraction +2);
    float c= 1.0 * a / b;
    return(round(c/0.125));
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    float arr4[12];
    for(int i=0;i<12;i++)
    {
        arr4[i]=440*pow(2.0,(i-9.0)/12.0);
    }
    if(strlen(note)==3)
    {
        if(note[1]=='#' || (note[1]=='b'))
        {
            if((note[0]=='C' && note[1]=='#') || (note[0]=='D' && note[1]=='b' ))
            {
                return(round(arr4[1]*pow(2.0,(note[2]-'0')-4)));
            }
            if((note[0]=='D' && note[1]=='#') || (note[0]=='E' && note[1]=='b'))
            {
                return(round(arr4[3]*pow(2.0,(note[2]-'0')-4)));
            }
            if((note[0]=='F' && note[1]=='#') || (note[0]=='G' && note[1]=='b'))
            {
                return(round(arr4[6]*pow(2.0,(note[2]-'0')-4)));
            }
            if((note[0]=='G' && note[1]=='#') || (note[0]=='A' && note[1]=='b'))
            {
                return(round(arr4[8]*pow(2.0,(note[2]-'0')-4)));
            }
            if((note[0]=='A' && note[1]=='#') ||(note[0]=='B' && note[1]=='b'))
            {
                return(round(arr4[10]*pow(2.0,(note[2]-'0')-4)));
            }
        }
    }
    else if(strlen(note)==2)
    {
        if(note[0]=='C')
        {
            return(round(arr4[0]*pow(2.0,(note[1] -'0')-4)));
        }
        if(note[0]=='D')
        {
            return(round(arr4[2]*pow(2.0,(note[1]-'0')-4)));
        }
            if(note[0]=='E')
        {
            return(round(arr4[4]*pow(2.0,(note[1]-'0')-4)));
        }
        if(note[0]=='F')
        {
            return(round(arr4[5]*pow(2.0,(note[1]-'0')-4)));
        }
        if(note[0]=='G')
        {
            return(round(arr4[7]*pow(2.0,(note[1]-'0')-4)));
        }
        if(note[0]=='A')
        {
            return(round(arr4[9]*pow(2.0,(note[1]-'0')-4)));
        }
        if(note[0]=='B')
        {
            return(round(arr4[11]*pow(2.0,(note[1]-'0')-4)));
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,""))
        return false;
    else
        return true;
}
