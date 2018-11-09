// Helper functions for music

#include <cs50.h>
#include<math.h>
#include "helpers.h"
#include<string.h>
#include<stdio.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num = atoi(&fraction[0]);
    int den = atoi(&fraction[2]);

    int res = (8./den)*num;
    return(res);


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n=0;
    int octave;
    if(strlen(note)==3) {
        octave = atoi(&note[2]);
        if(note[1]=='#')
            n++;
        else if(note[1]=='b')
            n--;
    }
    else {
        octave = atoi(&note[1]);
    }
    if(note[0]=='A')
        n-=0;
    else if(note[0]=='B')
        n+=2;
    else if(note[0]=='C')
        n-=9;
    else if(note[0]=='D')
        n-=7;
    else if(note[0]=='E')
        n-=5;
    else if(note[0]=='F')
        n-=4;
    else if(note[0]=='G')
        n-=2;


    n += (octave-4) * 12;


    float exp;
    exp = n/12.;

    return(round(pow(2, exp)*440));




}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"")==0)
        return(true);
    else
        return(false);

}
