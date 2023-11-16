#include "cube3d.h"

// mlx_loop_hook()

void pressed(mlx_key_data_t keydata,void *par)
{
    // mlx_key_data_t *hh;
    // hh->key.
    t_cube *cube = par;

    if (keydata.key == W)
    {
        cube->player.y-=5;
        /* code */
    }
    if (keydata.key == A)
    {
        cube->player.x-=5;
        /* code */
    }    
    if (keydata.key == S)
    {
        cube->player.y+=5;
        /* code */
    }   
     if (keydata.key == D)
    {
        cube->player.x+=5;
        /* code */
    }
    mini_map_draw(&cube);

    // printf("key is %d pressed = %d\n",cube->player.y, keydata.key);
    
}