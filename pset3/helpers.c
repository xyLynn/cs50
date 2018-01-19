// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int n = fraction[2] - '0';
    int m = fraction[0] - '0';
    int d = 8/n*m;
    return d;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char s1 = note[0];
    char s2 = note[1];
    char s3 = note[2];
    float l;
    int freq = 0;

    if (isalpha(s1))
    {
        switch (s1)
        {
            case 'A':
                l = 0;
                break;
            case 'B':
                l = 2;
                break;
            case 'C':
                l = -9;
                break;
            case 'D':
                l = -7;
                break;
            case 'E':
                l = -5;
                break;
            case 'F':
                l = -4;
                break;
            case 'G':
                l = -2;
                break;
        }
        //printf("%f\n", l);

        float k = 1.0/12.0;
        if (s2 == 'b')
        {
            float octave = s3 - '0';
            octave = octave - 4.0 + l/12.0 - k;
            freq = round(powf(2.0, octave) * 440);
        }
        else if (s2 == '#')
        {
            float octave = s3 - '0';
            octave = octave - 4.0 + l/12.0 + k;
            freq = round(powf(2.0, octave) * 440);
        }
        else
        {
            float octave = s2 - '0';
            octave = octave - 4.0 + l/12.0;
            freq = round(pow(2, octave) * 440);
        }
    }
    else
    {
        freq = 0;
    }
    //printf("%s %i\n", note, freq);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    int freq = frequency(s);
    if (freq == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}