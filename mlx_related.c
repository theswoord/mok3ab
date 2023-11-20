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
        if (!is_wall(cube,cube->player.x, cube->player.y-SPEED))
        {
        cube->player.y-=SPEED;
    mini_map_draw(cube);
            /* code */
        }
        

        /* code */
    }
    if (keydata.key == A)
    {
         if (!is_wall(cube,cube->player.x-SPEED, cube->player.y))
        {
        cube->player.x-=SPEED;
    mini_map_draw(cube);
        }
        /* code */
    }    
    if (keydata.key == S)
    {
                 if (!is_wall(cube,cube->player.x, cube->player.y+SPEED))
        {
        cube->player.y+=SPEED;
    mini_map_draw(cube);
        }
        /* code */
    }   
     if (keydata.key == D)
    {
                 if (!is_wall(cube,cube->player.x+SPEED, cube->player.y))
        {
        cube->player.x+=SPEED;
        
    mini_map_draw(cube);
        }
        /* code */
    }
    if (keydata.key == 256)
    {
        exit(0);

        /* code */
    }
        if (keydata.key == ROTA_LEFT)
    {
        // exit(0);
    mini_map_draw(cube);

        cube->player.angle-= 5; // counter clockwise rota;
        /* code */
    } 
       if (keydata.key ==ROTA_RIGHT)
    {
    mini_map_draw(cube);

               cube->player.angle+= 5;


        /* code */
    }
    // mini_map_draw(&cube);
    // cube->angle = 33.0;

    test_rota(cube);
    // mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y,0xFF0000FF);
    // is_wall(cube,cube->player.x, cube->player.y);
    // cast_v1(cube);

    draw_player(cube,0);

    // liner(cube,848,368);
    // mini_map_draw(cube);
    
    // printf("key is %d pressed = %d\n",cube->player.y, keydata.key);
    
}

