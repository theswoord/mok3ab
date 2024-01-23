#include "cube3d.h"

void draw_sun(t_cube *cube)
{
    int x;
    x = 0;
    int y;
    y = 0;

    // static const double PI = 3.1415926535;
    double angle = P2;

    double x1;
    double y1;

    while (angle > 0)
    {
        x1 = 150 * cos(angle); // 50
        y1 = 150 * sin(angle); // 50

        int j = 0;
        while (j < y1)
        {
            mlx_put_pixel(cube->window->img, WIDTH - (x + x1), y + j, 0xFFFFFFFF);
            // mlx_put_pixel(cube->window->img, WIDTH - (x + x1), y + j, 0xFFFFFFFF);
            j++;
        }

        angle -= 0.00174533;
    }
}

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

void print_tableau(char **tableau)
{
    int i = 0;

    while (tableau[i])
    {
        printf("%s\n", tableau[i]);
        i++;
        /* code */
    }
}

void free_tableau(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
        /* code */
    }
    free(tab);
}

char *copy_and_fill(char *str, int count, char c)
{
    int i = 0;
    char *new;
    new = ft_calloc(count + 1, 1);
    // printf("%d\n",count);
    while (str[i] != '\0')
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

    free(str);
    return new;
}

void ddanalizer(mlx_image_t *img, t_cube *cube, int color)
{
    // if (cube->dda.)
    // {
    //     /* code */
    // }

    double disX = cube->dda.endx - cube->dda.startx;
    double disY = cube->dda.endy - cube->dda.starty;
    double steps = 0;

    if (fabs(disX) > fabs(disY))
    {
        steps = fabs(disX);
        /* code */
    }
    else
        steps = fabs(disY);

    double Xinc = disX / (double)steps;
    double Yinc = disY / (double)steps;

    double X = cube->dda.startx;
    double Y = cube->dda.starty;
    // printf("%d")
    if (X > WIDTH || Y > HEIGHT)
    {
        printf("%f %f \n", X, Y);
        return;
        /* code */
    }
    // printf("X %f  Y %f \n",disX,disY);
    // printf("%f %f\n",cube->dda.endx,cube->dda.endy);
    while (steps >= 0)
    {
        X += Xinc;
        Y += Yinc;
        mlx_put_pixel(img, round(X), round(Y), color);

        steps--;
    }
}
void textured(t_cube *cube, unsigned long *row, int polarity, int height)
{
    int colm;
    int rowm;
    double disY;
    disY = cube->dda.endy - cube->dda.starty;
    double steps;
    steps = fabs(disY);
    double Y = cube->dda.starty;
    if (cube->dda.startx > WIDTH || Y > HEIGHT)
        return;
    while (steps > 0)
    {
        Y += 1;
        if (polarity == 0)
            colm = (int)(cube->v3.Hx + 0.0002) % MINIBLOCK; //
        else if (polarity == 1)
            colm = (int)(cube->v3.Vy + 0.0002) % MINIBLOCK;
        rowm = (int)((Y - cube->dda.savestarty) / cube->v3.savewallheight * height); // tswira
        mlx_put_pixel(cube->window->img, round(cube->dda.startx-1), Y, row[(height / MINIBLOCK) * colm + (height * rowm)]); // tswira (galia moncef height / MINIBLOX * colm)
        steps--;
    }
}

int fixangle(int a)
{
    if (a > 359)
    {
        a -= 360;
    }
    if (a < 0)
    {
        a += 360;
    }
    return a;
}


int height_extract(t_cube *cube, char *texture)
{
    if (!ft_strncmp(texture, "EA", 3))
        return (cube->colors->dim[0]);
    if (!ft_strncmp(texture, "NO", 3))
        return (cube->colors->dim[2]);
    if (!ft_strncmp(texture, "WE", 3))
        return (cube->colors->dim[4]);
    if (!ft_strncmp(texture, "SO", 3))
        return (cube->colors->dim[6]);

    return 0;
}



