#include "cube3d.h"


void draw_2dblock(mlx_image_t *img, int x , int y, int size, int color)
{
    int i = 0;
    int j = 0;

    while (i <= size)
    {
        while (j <= size)
        {
            mlx_put_pixel(img,x+i,y+j,color);
            j++;
        }
        j = 0;
        i++;
    }
    
}
void draw_player(t_cube * cube, int size)
{
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y+3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-1,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-1,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y+4,0xFF0000FF);



}