// Helper functions for music

#include <cs50.h>

#include "helpers.h"

#include <math.h>
#include <ctype.h>
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int a,b;
    a = fraction[0] - 48;
    b = fraction[2] - 48;
    return a*8/b;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int dig_index,dig,char_diff;
    float f,multiplier=0;
    if(strlen(note) == 2)
    {
        dig_index = 1;
    }
    else
    {
        dig_index = 2;
    }
    dig = note[dig_index] - 48;
    if(note[0]=='A' || note[0]=='B')
    {
        multiplier = multiplier + 12*(dig-4);
    }
    else
    {
        multiplier = multiplier + 12*(dig-5);
    }
    char_diff = note[0] - 65;
    if(char_diff<2)
    {
        multiplier = multiplier + char_diff*2;
    }
    else if(char_diff<5)
    {
        multiplier = multiplier + char_diff*2 - 1;
    }
    else
    {
        multiplier = multiplier + char_diff*2 - 2;
    }
    if(note[1]=='#')
    {
        multiplier++;
    }
    else if(note[1]=='b')
    {
        multiplier--;
    }
    f = round(440*pow(2,multiplier/12));
    return f;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    bool b=false;
    if(strcmp(s,"")==0)
    {
        b=true;
    }
    return b;
}
