#include "mesinkar.h"
#include <stdio.h>

boolean EOP; // End Of Process
char CC;     // Current Character

static FILE *pitaChar;
static int retval;

void START()
{
    pitaChar = stdin;
    ADV();
}

void ADV()
{
    retval = fscanf(pitaChar, "%c", &CC);
    EOP = (CC == MARK);
    if (EOP)
    {
        fclose(pitaChar);
    }
}