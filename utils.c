#include "cube3d.h"

bool found_after_space(char *str, char c)
{
    int i;
    i = 0;
    while (str[i])
    {
        while ((str[i] == ' ') || (str[i] == '\t'))
        {
            i++;
        }
        if (str[i] == c)
        {
            return true;
        }
        else
            return false;
        i++;
    }
    return false;
}

void print_tableau(char ** tableau)
{
    int i = 0;

    while (tableau[i])
    {
        printf("%s\n",tableau[i]);
        i++;
        /* code */
    }
    
}