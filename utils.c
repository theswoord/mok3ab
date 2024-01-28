#include "cube3d.h"

void draw_sun(t_cube *cube)
{
    int x;
    x = 0;
    int y;
    y = 0;
    double angle = P2;

    double x1;
    double y1;

    while (angle > 0)
    {
        x1 = 150 * cos(angle);
        y1 = 150 * sin(angle);

        int j = 0;
        while (j < y1)
        {
            mlx_put_pixel(cube->window->img, WIDTH - (x + x1), y + j, 0xFFFFFFFF);
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
    }
}

void free_tableau(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char *copy_and_fill(char *str, int count, char c)
{
    int i = 0;
    char *new;
    new = ft_calloc(count + 1, 1);
    while (str[i] != '\0')
    {
        new[i] = str[i];
        i++;
    }
    while (i < count)
    {
        new[i] = c;
        i++;
    }

    free(str);
    return new;
}

void ddanalizer(mlx_image_t *img, t_cube *cube, int color)
{
    double disX = cube->dda.endx - cube->dda.startx;
    double disY = cube->dda.endy - cube->dda.starty;
    double steps = 0;

    if (fabs(disX) > fabs(disY))
    {
        steps = fabs(disX);
    }
    else
        steps = fabs(disY);

    double Xinc = disX / (double)steps;
    double Yinc = disY / (double)steps;

    double X = cube->dda.startx;
    double Y = cube->dda.starty;
    if (X > WIDTH || Y > HEIGHT)
        return;
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
    double steps;
    steps = fabs(cube->dda.endy - cube->dda.starty);
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
        if (rowm < 32)
        {
        mlx_put_pixel(cube->window->img, round(cube->dda.startx), Y, row[((height / MINIBLOCK) * colm + (height * rowm))]); // tswira (galia moncef height / MINIBLOX * colm)
        }
        
        steps--;
    }
}
void textured_inverted(t_cube *cube, unsigned long *row, int polarity, int height)
{
    int colm;
    int rowm;
    double steps;
    steps = fabs(cube->dda.endy - cube->dda.starty);
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
        if (rowm < 32 )
        mlx_put_pixel(cube->window->img, round(cube->dda.startx), Y, row[((height / MINIBLOCK) * 31-colm + (height * rowm))]); // tswira (galia moncef height / MINIBLOX * colm)
        
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



int	toupperv2(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 0;
	}
	if (c >= '0' && c <= '9')
	{
		c += 0;
	}
	return (c);
}

int element_count(char* str, char c)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i]==c)
        {
            count ++;
        }
        
        i++;
    }
    return count;
}