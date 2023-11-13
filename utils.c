#include "cube3d.h"

bool found_after_space(char *str, char c)
{
    int i;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '/t')
        {
            i++;
        }
        if (str[i] == c)
        {
            return true;
        }

        i++;
    }
    return false;
}