#include "cube3d.h"

// mlx_loop_hook()

void pressed(mlx_key_data_t keydata,void *par)
{
    // mlx_key_data_t *hh;
    // hh->key.
    t_cube *cube = par;
            printf("x= %d, y= %d\n", cube->player.x, cube->player.y);

    if (keydata.key == W)
    {
        cube->player.y-=5;
    mini_map_draw(cube);

        /* code */
    }
    if (keydata.key == A)
    {
        cube->player.x-=5;
    mini_map_draw(cube);

        /* code */
    }    
    if (keydata.key == S)
    {
        cube->player.y+=5;
    mini_map_draw(cube);

        /* code */
    }   
     if (keydata.key == D)
    {
        cube->player.x+=5;
        
    mini_map_draw(cube);

        /* code */
    }
    // mini_map_draw(&cube);
    
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y,0xFF0000FF);
    liner(cube,50,50);
    // mini_map_draw(cube);
    
    // printf("key is %d pressed = %d\n",cube->player.y, keydata.key);
    
}
