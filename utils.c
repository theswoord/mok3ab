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

    float disX = cube->dda.endx - cube->dda.startx;
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
void textured(mlx_image_t *img, t_cube *cube, unsigned long *row)
{
    // if (cube->dda.)
    // {
    //     /* code */
    // }
    int i = 0;

    float disX = cube->dda.endx - cube->dda.startx;
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

    
    while (steps > 0)
    {
        X += Xinc;
        Y += Yinc;
        // while (i < 1024)
        // {
        mlx_put_pixel(img, X, Y, row[(i % 32) * 32 + i / 32]);
        i++;
        /* code */
        // }

        steps--;
    }
    // i = 0;
}
double normalizeAngle(double angle)
{
    while (angle < 0)
    {
        angle += M_2_PI; // Add 2π until the angle is non-negative
    }
    while (angle >= M_2_PI)
    {
        angle -= M_2_PI; // Subtract 2π until the angle is within the desired range
    }
    return angle;
}
void performRotation(t_cube *cube, int clockwise)
{
    double rotation = clockwise ? ROTSPEED : -ROTSPEED; // Determine clockwise or counterclockwise rotation

    // double oldDirX = cube->win.dirX;
    // cube->win.dirX = cube->win.dirX * cos(rotation) - cube->win.dirY * sin(rotation);
    // cube->win.dirY = oldDirX * sin(rotation) + cube->win.dirY * cos(rotation);

    double oldPlaneX = cube->win.planeX;
    cube->win.planeX = cube->win.planeX * cos(rotation) - cube->win.planeY * sin(rotation);
    cube->win.planeY = oldPlaneX * sin(rotation) + cube->win.planeY * cos(rotation);

    // Normalize angles after rotation
    // cube->win.dirX = normalizeAngle(cube->win.dirX);
    // cube->win.dirY = normalizeAngle(cube->win.dirY);
    cube->win.planeX = normalizeAngle(cube->win.planeX);
    cube->win.planeY = normalizeAngle(cube->win.planeY);
}

float d2r(float deg)
{
    return (deg * M_PI / 180.0);
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

void txtured(t_cube *cube, mlx_image_t *img,unsigned long *tex )
{
    int i = 0;
    int y = 0;
    int x = 0;
    int factor = 2;

    while (i < 1024)
    {
        while (y < 32)
        {
            while (x < 32)
            {
            //      mlx_put_pixel(50+ x*factor,cube->v3.Hx + y*factor, tex[i]);
            //    mlx_put_pixel(img,cube->v3.rayx + x*factor + factor - 1, cube->v3.rayy+ y*factor, tex[i]);
            //    mlx_put_pixel(img,cube->v3.rayx + x*factor,cube->v3.rayy + y*factor + factor - 1, tex[i]);
            //    mlx_put_pixel(img,cube->v3.rayx + x*factor + factor - 1,cube->v3.rayy + y*factor + factor - 1, tex[i]);

                // mlx_put_pixel(img, 50 + x*2, 50 + y*2, tex[i]);
                // mlx_put_pixel(img, 50 + x*2 +2, 50 + y*2 , tex[i]);
                // mlx_put_pixel(img, 50 + x*2, 50 + y*2+1, tex[i]);
                // mlx_put_pixel(img, 50 + x*2 +1 , 50 + y * 2 + 1, tex[i]);
                // // mlx_put_pixel(img, 50 + x*2, 50 + y*2, tex[i]);
                // // mlx_put_pixel(img, 50 + x*2 +2, 50 + y*2 , tex[i]);
                // // mlx_put_pixel(img, 50 + x*2, 50 + y*2+2, tex[i]);
                // // mlx_put_pixel(img, 50 + x*2 + 2 , 50 + y * 2 + 2, tex[i]);
                // // ---------------------------------------------------------------------------- BLOCk
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +2, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+1, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +2 , 150 + y * 3 + 2, tex[i]);

                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +2, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+2, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 + 2 , 150 + y * 3 + 2, tex[i]);

                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +3, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 + 3 , 150 + y * 3 + 3, tex[i]);

                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +4, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+4, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 + 4 , 150 + y * 3 + 4, tex[i]);

                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +5, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+5, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 + 5 , 150 + y * 3 + 5, tex[i]);
                
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 +6, 150 + y*3 , tex[i]);
                // mlx_put_pixel(img, 150 + x*3, 150 + y*3+6, tex[i]);
                // mlx_put_pixel(img, 150 + x*3 + 6 , 150 + y * 3 + 6, tex[i]);
                x++;
                i++;
            }
            x = 0;
            y++;
        }
    }
}

void txtv3(mlx_image_t *img,t_cube *cube, unsigned long *row, int fin, int y)
{
        static int  i = 0;
       static int k = 0;
    int steps = 0;
    float disX = 0;
    float disY = 32;

        if (fabs(disX) > fabs(disY))
    {
        steps = fabs(disX);
        /* code */
    }
    else
        steps = fabs(disY);
    
    
    float X = fin;
    float Y = y;
    
    float Xinc = disX / (float)steps;
    float Yinc = disY / (float)steps;
    while (steps > 0)
    {
        X += Xinc;
        Y += Yinc;
        mlx_put_pixel(img, X, Y, row[(k % 32) * 32 + k / 32]);

        k++;
        
        if (k ==1024)
        {
           k = 0;
        }
        steps--;
    }
}