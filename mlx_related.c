#include "cube3d.h"

void boundaries(t_cube *cube)
{
    cube->bound.frontx = (cube->player.x + 2* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.fronty = (cube->player.y + 2* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.backx = (cube->player.x - 2* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.backy = (cube->player.y - 2* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.righty = (cube->player.y + 2* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.rightx = (cube->player.x - 2* round(cube->v3.deltay)) / MINIBLOCK;
    cube->bound.lefty = (cube->player.y - 2* round(cube->v3.deltax)) / MINIBLOCK;
    cube->bound.leftx = (cube->player.x + 2* round(cube->v3.deltay)) / MINIBLOCK;
}

void pressed(void *par)
{
    t_cube *cube = par;

    boundaries(cube);

    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
    {
        if (cube->map[cube->bound.fronty][(int)cube->player.x / MINIBLOCK] != '1' && cube->map[(int)cube->player.y / MINIBLOCK][cube->bound.frontx] != '1')
        {
            // if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK || cube->player.x >= cube->map_stuff.max*MINIBLOCK)
            // {
            //     if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK)
            //     {
            //         cube->player.y -=  cube->map_stuff.lines*MINIBLOCK;
            //     }
            //     else
            //     {
            //         cube->player.x -=  cube->map_stuff.max*MINIBLOCK;
            //     }
            if (cube->map[cube->bound.fronty][cube->bound.frontx] != '1')
            {
                cube->player.y += round(cube->v3.deltay);
                cube->player.x += round(cube->v3.deltax);
                /* code */
            }
        }

        // }
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_LEFT))
    {
        cube->v3.angle -= ROTSPEED;
        if (cube->v3.angle < 0)
        {
            cube->v3.angle += 2 * M_PI;
        }
        cube->v3.deltax = cos(cube->v3.angle) * SPEED; // x
        cube->v3.deltay = sin(cube->v3.angle) * SPEED; // y
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
    {
        if (cube->map[cube->bound.backy][(int)cube->player.x / MINIBLOCK] != '1' && cube->map[(int)cube->player.y / MINIBLOCK][cube->bound.backx] != '1')
        {
            // if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK || cube->player.x >= cube->map_stuff.max*MINIBLOCK)
            // {
            //     if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK)
            //     {
            //         cube->player.y -=  cube->map_stuff.lines*MINIBLOCK;
            //     }
            //     else
            //     {
            //         cube->player.x -=  cube->map_stuff.max*MINIBLOCK;
            //     }
            if (cube->map[cube->bound.backy][cube->bound.backx] != '1')
            {
                cube->player.y -= round(cube->v3.deltay);
                cube->player.x -= round(cube->v3.deltax);
            }
        }
    }

    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_RIGHT))
    {
        cube->v3.angle += ROTSPEED;
        if (cube->v3.angle >= 2 * M_PI)
        {
            cube->v3.angle -= 2 * M_PI;
        }
        cube->v3.deltax = cos(cube->v3.angle) * SPEED;
        cube->v3.deltay = sin(cube->v3.angle) * SPEED;
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
    {
        free_all(cube);

        // while (1)
        // {
        //     /* code */
        // }

        exit(0); // free
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
    {
        if (cube->map[cube->bound.righty][(int)cube->player.x / MINIBLOCK] != '1' && cube->map[(int)cube->player.y / MINIBLOCK][cube->bound.rightx] != '1')
        {
            // if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK || cube->player.x >= cube->map_stuff.max*MINIBLOCK)
            // {
            //     if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK)
            //     {
            //         cube->player.y -=  cube->map_stuff.lines*MINIBLOCK;
            //     }
            //     else
            //     {
            //         cube->player.x -=  cube->map_stuff.max*MINIBLOCK;
            //     }
            if (cube->map[cube->bound.righty][cube->bound.rightx] != '1')
            {
                cube->player.x -= round(cube->v3.deltay);
                cube->player.y += round(cube->v3.deltax);
            }
        }
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
    {
        if (cube->map[cube->bound.lefty][(int)cube->player.x / MINIBLOCK] != '1' && cube->map[(int)cube->player.y / MINIBLOCK][cube->bound.leftx] != '1')
        {
            // if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK || cube->player.x >= cube->map_stuff.max*MINIBLOCK)
            // {
            //     if (cube->player.y >= cube->map_stuff.lines*MINIBLOCK)
            //     {
            //         cube->player.y -=  cube->map_stuff.lines*MINIBLOCK;
            //     }
            //     else
            //     {
            //         cube->player.x -=  cube->map_stuff.max*MINIBLOCK;
            //     }
            if (cube->map[cube->bound.lefty][cube->bound.leftx] != '1')
            {
                cube->player.x += round(cube->v3.deltay);
                cube->player.y -= round(cube->v3.deltax);
            }
        }
    }
    mini_map_draw(cube);
    cast_v3(cube);
}
