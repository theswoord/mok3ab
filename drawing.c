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
            mlx_put_pixel(img,x+i,y+j,0xFFFF00CF);

            if (i == size/2 && j == size/2)
            {
            printf("x= %d, y= %d\n", x+i, y+j);
            cube->player.x = x+i;
            cube->player.y = y+i;

            mlx_put_pixel(img,x+i,y+j,0xFF0000FF);

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