#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

int duration(string fraction)
{
    int num=fraction[0]-'0';  //Stores the neumerator
    int den=fraction[2]-'0';  //Stores the Denominator
    if(num!=0 && den!=0)
    {
         return ((num*8)/den);
    }
    return 0;
}

int frequency(string note)
{
    double freq=440.0;
    char Note = note[0];
    double Octave;
    if(note[1] == '#' || note[1] == 'b')
    {
        Octave = note[2];
    }
    else
    {
        Octave = note[1];
    }
    Octave -= '0';
    int power;
    freq = freq*( pow(2,Octave - 4.0));
    if(Note=='A')
    {
        power=0.0;
    }
    else if(Note=='B')
    {
        power=-2.0;
    }
    else if(Note=='C')
    {
        power=9.0;
    }
    else if(Note=='D')
    {
        power=7.0;
    }
    else if(Note=='E')
    {
        power=5.0;
    }
    else if(Note=='F')
    {
        power=4.0;
    }
    else if(Note=='G')
    {
        power=2.0;
    }
    else
    {
        return 1;
    }
    freq = 440.0 / (pow(2.0, (power / 12.0)));
    if(note[1] == 'b')
    {
        freq = freq/((pow(2.0, (1.0 / 12.0)))) ;
    }
    else if(note[1] == '#')
    {
        freq = freq*((pow(2.0, (1.0 / 12.0))));
    }
    return freq;
}

bool is_rest(string s)
{
    if (strncmp(s,"",1) == 0)
    {
        return true;
    }
    return false;
}