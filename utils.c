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

void free_tableau(char ** tab)
{
    int i = 0 ;
    while (tab[i])
    {
        free(tab[i]);
        i++;
        /* code */
    }
    free(tab);
}

char* copy_and_fill(char *str, int count , char c)
{
    int i = 0;
    char *new;
    new = ft_calloc(count+1,1);
    // printf("%d\n",count);
    while (str[i]!= '\0')
    {
        new[i] = str[i];
        i++;
        /* code */
    }
    while (i < count)
    {
        new[i] = c;
        i++;
        /* code */
    }
    // printf("%p %p\n",new, str);
    
    // free(str);
    return new;
}

void ddanalizer(mlx_image_t *img , t_cube *cube)
{   
    // if (cube->dda.)
    // {
    //     /* code */
    // }
    

    float disX = cube->dda.endx - cube->dda.startx ; 
    float disY = cube->dda.endy - cube->dda.starty;
    int steps = 0;

    if (fabs(disX) > fabs(disY))
    {
        steps = fabs(disX);
        /* code */
    }
    else
        steps = fabs(disY);
    
    float Xinc = disX / (float)steps; 
    float Yinc = disY / (float)steps; 

    float X = cube->dda.startx; 
    float Y = cube->dda.starty; 
    if (X > WIDTH || Y > HEIGHT)
    {
        return;
        /* code */
    }
    
    while (steps > 0) {
        X += Xinc;
        Y += Yinc;
        mlx_put_pixel(img, round(X), round(Y), 0x0000FFFF);
        steps--;
    }
}