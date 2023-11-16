#include "cube3d.h"


void draw_2dblock(mlx_image_t *img, int x , int y, int size, int color)
{
    int i = 0;
    int j = 0;

    while (i <= size)
    {
        while (j <= size)
        {
            // printf("%d %d\n",i , j);
            mlx_put_pixel(img,x+i,y+j,color);
            j++;
            /* code */
        }
        j = 0;
        i++;
        /* code */
    }
    
}
void draw_player(t_cube * cube , mlx_image_t *img, int x, int y, int size)
{
    int i = 0;
    int j = 0;

    while (i <= size)
    {
        while (j <= size)
        {
            // printf("%d %d\n",i , j);
            // mlx_put_pixel(img,x+i,y+j,0xFFFF00CF);

            if (i == size/2 && j == size/2)
            {
            cube->player.x = x+i;
            cube->player.y = y+j;
            // printf("x= %d, y= %d\n", cube->player.x, cube->player.y);

            // mlx_put_pixel(img,x+i,y+j,0xFF0000FF);

                /* code */
            }
            
            j++;
            
            /* code */
        }
        j = 0;
        i++;
        /* code */
    }
    
}

void draw_line(mlx_image_t *img,int start , int end , int lenght)
{
    int i = 0;

    while (i < lenght)
    {
        /* code */
        // mlx_put_pixel(image,start,)
        i++;
    }
    
}

void liner(t_cube *cube , int ex, int ey)
{
    int i =0;
    int disX = ex - cube->player.x ; //special dda
    int disY = ey - cube->player.y ;
    // printf("%d %d \n",disX,disY);
    int steps = 0;


    // steps = 
    if (abs(disX) > abs(disY))
    {
        steps = abs(disX);
        /* code */
    }
    else
        steps = abs(disY);
    
    float Xinc = disX / (float)steps; 
    float Yinc = disY / (float)steps; 

    float X = cube->player.x; 
    float Y = cube->player.y; 
    while (i <= steps){ 
        // printf("bda %d, ghadi %d steps %d\n",X,Y,steps);
        mlx_put_pixel(cube->mini_map,round(X),round(Y),0x0000FFFF); 
        X += Xinc; 
        Y += Yinc;
        i++;
    } 
}