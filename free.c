#include "cube3d.h"

void free_struct(t_cube *cube)
{


}

// void free_tab(char **tab)
// {
//     int i;
//     i=0;
//     while (tab[i])
//     {
//         free(tab[i]);
//         i++;
//         /* code */
//     }
//     free(tab);
// }
void img_destroy(t_cube * cube)
{

    mlx_delete_image(cube->window->mlx,cube->window->img);
    mlx_delete_image(cube->window->mlx,cube->mini_map);
    mlx_close_window(cube->window->mlx);
    
}
void free_stucts(t_cube * cube)
{

    free_tableau(cube->textures);
    free_tableau(cube->background);
    free_tableau(cube->map);

    free(cube->window);
    free(cube->drawings);
    free(cube->colors);
    // free(cube->window);

    free(cube); // hh
}
void free_all(t_cube*cube)
{
    img_destroy(cube);
    free_struct(cube);
}