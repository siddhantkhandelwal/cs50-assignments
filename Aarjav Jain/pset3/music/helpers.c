// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[2] % 2 != 0)
    {
        printf("Error\n");
        return -1;
    }
    int number;
    number = (8 / atoi(&fraction[2])) * atoi(&fraction[0]);
    return number;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq = 440;
    double n = 0;
    switch (note[0])
    {
        case 'A': break;
        case 'B': n += 2;
                  break;
        case 'C': n -= 9;
                  break;
        case 'D': n -= 7;
                  break;
        case 'E': n -= 5;
                  break;
        case 'F': n -= 4;
                  break;
        case 'G': n -= 2;
                  break;
    }
    if (strlen(note) == 2)
    {
        n += (atoi(&note[1]) - 4) * 12;
    }
    else if (strlen(note) == 3)
    {
        n += (atoi(&note[2]) - 4) * 12;
        if (note[1] == '#')
        {
            n++;
        }
        else if (note[1] == 'b')
        {
            n--;
        }
    }
    double power = n / 12;
    freq = round(440 * pow(2.0, power));
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
