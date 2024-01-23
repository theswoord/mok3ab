#include "cube3d.h"

// mlx_loop_hook()
// int* bound(t_cube *cube)
// {

// }



void boundaries(t_cube *cube)
{
    // printf("%f %f \n ",cube->player.x,cube->v3.deltax );
    cube->bound.frontx = (cube->player.x + 3* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.fronty = (cube->player.y + 3* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.backx = (cube->player.x - 3* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.backy = (cube->player.y - 3* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.righty = (cube->player.y + 3* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.rightx = (cube->player.x - 3* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.lefty = (cube->player.y - 3* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.leftx = (cube->player.x + 3* round(cube->v3.deltay)) / MINIBLOCK;
    // printf("fx %d fx %d bx %d by %d rx %d ry %d %d %d\n", cube->bound.frontx,cube->bound.fronty,cube->bound.backx,cube->bound.backy,cube->bound.righty,cube->bound.rightx,cube->bound.lefty,cube->bound.leftx);
}

void pressed(void *par)
{
    t_cube *cube = par;

    boundaries(cube);

    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
    {
        if (cube->map[cube->bound.fronty][cube->bound.frontx] != '1')
        {
            cube->player.y += round(cube->v3.deltay);
            cube->player.x += round(cube->v3.deltax);
        }
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_LEFT))
    {
        cube->v3.angle -= ROTSPEED;
        if (cube->v3.angle < 0)
        {
            cube->v3.angle += 2 * M_PI;
        }
        cube->v3.deltax = cos(cube->v3.angle) * 5.0; //x
        cube->v3.deltay = sin(cube->v3.angle) * 5.0; //y
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
    {
        if (cube->map[cube->bound.backy][cube->bound.backx] != '1')
        {
            cube->player.y -= round(cube->v3.deltay);
            cube->player.x -= round(cube->v3.deltax);
        }
        // mini_map_draw(cube);
    }

    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_RIGHT))
    {
        cube->v3.angle += ROTSPEED;
        if (cube->v3.angle >= 2 * M_PI)
        {
            cube->v3.angle -= 2 * M_PI;
        }
        cube->v3.deltax = cos(cube->v3.angle) * 5.0;
        cube->v3.deltay = sin(cube->v3.angle) * 5.0;
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
    {
        exit(0); // free
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
    {
        if (cube->map[cube->bound.righty][cube->bound.rightx] != '1')
        {
            cube->player.x -= round(cube->v3.deltay);
            cube->player.y += round(cube->v3.deltax);
        }
        // printf("%f %f\n", cube->v3.angle, sin(cube->v3.angle)*5);
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
    {
        // printf("x %d y %d\n",(int)(cube->player.x + sin(cube->v3.angle) * 5.0),(int)(cube->player.y - cos(cube->v3.angle) * 5.0));
        if (cube->map[cube->bound.lefty][cube->bound.leftx] != '1')
        {
            cube->player.x += round(cube->v3.deltay);
            cube->player.y -= round(cube->v3.deltax);
            /* code */
        }

        // mini_map_draw(cube);
    }
    // clea

    // draw_player(cube, 0);
    // cube->v3.angle += 0.0001;
    // cube->v3.rayangle += 0.0001;
    // cube->player.y+=0.100;
    
    // mini_map_draw(cube);
    cast_v3(cube);

    // printf("key is %d pressed = %d\n",cube->player.y, keydata.key);
}

void img_clear(mlx_image_t *img, int width, int height)
{
    int i = 0;
    int j = 0;
    while (j < height)
    {
        while (i < width)
        {
            /* code */
            mlx_put_pixel(img, i, j, 0x000000FF);
            i++;
        }
        i = 0;
        j++;
        /* code */
    }
}
