#include "cube3d.h"


void free_textures(t_cube * cube)
{
    free(cube->colors->NO);
    free(cube->colors->SO);
    free(cube->colors->EA);
    free(cube->colors->WE);

}
void img_destroy(t_cube * cube)
{

    mlx_delete_image(cube->window->mlx,cube->window->img);
    mlx_delete_image(cube->window->mlx,cube->mini_map);
    mlx_close_window(cube->window->mlx);
    
}
void free_stucts(t_cube * cube)
{
    free_tableau(cube->map);

    free(cube->window);
    free(cube->drawings);
    free(cube->colors);

    free(cube);
}
void free_all(t_cube*cube)
{
    free_textures(cube);
    img_destroy(cube);

    free_stucts(cube);
}