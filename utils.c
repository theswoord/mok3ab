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
            mlx_put_pixel(cube->window->img, WIDTH - (x + x1), y + j, 0xEBD534FF);
            // mlx_put_pixel(cube->window->img, WIDTH - (x + x1), y + j, 0xFFFFFFFF);
            j++;
        }

        angle -= 0.0174533;
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
        mlx_put_pixel(cube->window->img, round(cube->dda.startx), Y, row[(height / MINIBLOCK) * colm + (height * rowm)]); // tswira (galia moncef height / MINIBLOX * colm)
        steps--;
    }
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

void txtured(t_cube *cube, mlx_image_t *img, unsigned long *tex)
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

                mlx_put_pixel(img, 50 + x * 2, 50 + y * 2, tex[i]);
                mlx_put_pixel(img, 50 + x * 2 + 2, 50 + y * 2, tex[i]);
                mlx_put_pixel(img, 50 + x * 2, 50 + y * 2 + 1, tex[i]);
                mlx_put_pixel(img, 50 + x * 2 + 1, 50 + y * 2 + 1, tex[i]);
                x++;
                i++;
            }
            x = 0;
            y++;
        }
    }
}

void txtv3(mlx_image_t *img, t_cube *cube, unsigned long *row, int fin, int y)
{
    static int i = 0;
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

        if (k == 1024)
        {
            k = 0;
        }
        steps--;
    }
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
int factor_finder(t_cube *cube, char *texture)
{
    return ((int)(cube->v3.wallheight / height_extract(cube, texture)));
}
// void dakh(mlx_image_t *img, t_cube *cube, unsigned long *texture, int textureWidth, int textureHeight, int factor) {
//     float disX = cube->dda.endx - cube->dda.startx;
//     float disY = cube->dda.endy - cube->dda.starty;
//     int steps = (fabs(disX) > fabs(disY)) ? fabs(disX) : fabs(disY);

//     float Xinc = disX / (float)steps;
//     float Yinc = disY / (float)steps;

//     float X = cube->dda.startx;
//     float Y = cube->dda.starty;

//     if (X > WIDTH || Y > HEIGHT || steps <= 0  || MINIBLOCK <= 0) {
//         return;
//     }

//     for (int i = 0; i < steps; i++) {
//         int texX = ((int)(X / MINIBLOCK)) % textureWidth;
//         int texY = ((int)(Y / (MINIBLOCK ))) % textureHeight;

//         unsigned long texColor = texture[texY * textureWidth + texX];
//         // printf("%d %d \n",texX,texY);
//         mlx_put_pixel(img, X, Y, texColor);

//         X += Xinc;
//         Y += Yinc;
//     }
// }
void dakh(mlx_image_t *img, t_cube *cube, unsigned long *texture, int textureWidth, int textureHeight, int factor)
{
    float disX = cube->dda.endx - cube->dda.startx;
    float disY = cube->dda.endy - cube->dda.starty;
    int steps = (fabs(disX) > fabs(disY)) ? fabs(disX) : fabs(disY);

    float Xinc = disX / (float)steps;
    float Yinc = disY / (float)steps;

    float X = cube->dda.startx;
    float Y = cube->dda.starty;

    if (X > WIDTH || Y > HEIGHT || steps <= 0 || MINIBLOCK <= 0)
    {
        return;
    }

    float texScaleX = (float)textureWidth / (float)MINIBLOCK;
    float texScaleY = (float)textureHeight / (float)MINIBLOCK;

    for (int i = 0; i < steps; i++)
    {
        int texX = ((int)(X * texScaleX)) % textureWidth;
        int texY = ((int)(Y * texScaleY)) % textureHeight;

        unsigned long texColor = texture[texY * textureWidth + texX];

        mlx_put_pixel(img, X, Y, texColor);

        X += Xinc;
        Y += Yinc;
    }
}

void tabta(mlx_image_t *img, t_cube *cube, unsigned long *row, int factor)
{
    int i = 0;
    int times = 0;
    int y = cube->dda.starty;

    // while (y <= cube->dda.endy)
    // {
    int x = cube->dda.startx;

    //     while (x <= cube->dda.endx)
    //     {
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+1, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+2, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+3, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+4, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+5, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+6, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+7, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+8,row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+9, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+10, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+11, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+12, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+13, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+14, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+15, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y+16, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    // mlx_put_pixel(img, x, y, row[(i % 32) * 32 + i / 32]);
    while (y <= cube->dda.endy)
    {
        // while (times <= factor)
        // {
        mlx_put_pixel(img, x, y + times, row[(i % 32) * 32 + i / 32]);
        times++;
        // }
        times = 0;
        i++;
        y++;
    }

    //         x++;
    //     }

    //     y++;
    // }
    // printf("%d \n", factor);
}
