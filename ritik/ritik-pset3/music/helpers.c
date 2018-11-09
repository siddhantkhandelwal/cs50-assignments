// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    if(fraction[0] == '1')
    {
        if(fraction[2] == '8')
        {
            return 1;
        }
        else if(fraction[2] == '4')
        {
            return 2;
        }
        else if(fraction[2] == '2')
        {
            return 4;
        }
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else if(fraction[0] == '5' && fraction[2] == '8')
    {
        return 5;
    }
    else if(fraction[0] == '7' && fraction[2] == '8')
    {
        return 7;
    }
    if(fraction[0] == '3' && fraction[2] == '4')
    {
        return 6;
    }
    else
    {
        return 0;
    }
    return 0;
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    double freq;
    char NOTE = note[0];
    double OCTAVE;
    double sharp = 0;
    if(note[1] == '#' || note[1] == 'b')
    {
        sharp = 1;
        OCTAVE = note[2];
    }
    else OCTAVE = note[1];
    OCTAVE -= 48;
    switch(NOTE)
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }

    freq *= pow(2,OCTAVE - 4.0);
    if (sharp == 1)
    {
        if(note[1] == 'b')
        {
            freq /= (pow(2.0, (1.0 / 12.0)));
        }
        else if(note[1] == '#')
        {
            freq *= (pow(2.0, (1.0 / 12.0)));
        }
    }
    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strncmp(s,"",1) == 0)
    {
        return true;
    }
    else return false;
}
