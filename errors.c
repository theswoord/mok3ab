#include "cube3d.h"

void print_error(char *str)
{
    int i;
    i=0;
    while (str[i])
    {
        write(2,&str[i],1);
        i++;
    }
    
}

// void errors_general(t_cube *cube,int errno)
// {
//     // if (errno = )
//     // {
//     //     /* code */
//     // }
    
// }