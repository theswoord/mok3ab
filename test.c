#include "cube3d.h"


int main()
{
    int *hh = malloc(100);
    for (int i = 0; i < 100; i++)
    {
        hh[i]=i;
        /* code */
    }
    
    for (int i = 0; i < 100; i++)
    {

        printf("%d\n",hh[i%25]);
        /* code */
    }
    
}