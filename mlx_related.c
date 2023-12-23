#include "cube3d.h"

// mlx_loop_hook()

void pressed(void *par)
{
    t_cube *cube = par;
    int testx = (cube->player.x + cube->v3.deltax) / MINIBLOCK;
    int testy = (cube->player.y + cube->v3.deltay) / MINIBLOCK;
    int backx = (cube->player.x - cube->v3.deltax) / MINIBLOCK;
    int backy = (cube->player.y - cube->v3.deltay) / MINIBLOCK;
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
    {
        if (cube->map[testy][testx] != '1')
        {
            cube->player.y += cube->v3.deltay;
            cube->player.x += cube->v3.deltax;
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
        cube->v3.deltax = cos(cube->v3.angle) * 5;
        cube->v3.deltay = sin(cube->v3.angle) * 5;
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
    {
        if (cube->map[backy][backx] != '1')
        {
            cube->player.y -= cube->v3.deltay;
            cube->player.x -= cube->v3.deltax;
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
        cube->v3.deltax = cos(cube->v3.angle) * 5;
        cube->v3.deltay = sin(cube->v3.angle) * 5;
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
    {
        exit(0); // free
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
    {
        // cube->player.y -= cube->v3.deltay;
        // cube->player.x -= cube->v3.deltax;
        // mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
    {
        // mini_map_draw(cube);
    }

    // draw_player(cube, 0);
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
