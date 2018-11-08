// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num, den;
    num = fraction[0] - '0';
    den = fraction[2] - '0';
    int result = 1;
    result *= num;
    result *= (8 / den);
    return result;
}

//Calculates frequency (in Hz) of a note
int frequency(string notei)
{
    double frequency;
    int num;
    string temp;
    char note[3];
    for(int i = 0; i < strlen(notei); i++)
    {
        //printf("%d",i);
        if(!((notei[i] >= '0') && (notei[i] <= '9'))) note[i] = notei[i];
        else
        {
            num = notei[i] - '0';
        }
    }
    string values[12][2] = {{"C ", "  "}, {"C#", "Db"}, {"D ", "  "}, {"D#", "Eb"}, {"E ", "  "}, {"F ", "  "}, {"F#", "Gb"}, {"G ", "  "}, {"G#", "Ab"}, {"A ", "  "}, {"A#", "Bb"}, {"B ", "  "}};
    if(strlen(note) == 1) temp = strcat(note, " ");
    else temp = note;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(!(strcmp(temp, values[i][j])))
            {
                frequency = pow(2.0, ((((float) i) - 9) / 12.0));
            }
        }
    }
    frequency *= (440.0 * pow(2.0, ((float) num) - 4.0));
    return (int) round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"")) return false;
    return true;
}