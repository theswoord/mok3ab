#include "cube3d.h"

// mlx_loop_hook()

void pressed(void *par)
{
    // mlx_key_data_t *hh;
    // hh->key.
    // mlx_key_d
    t_cube *cube = par;
    // printf("x= %d, y= %d\n", cube->player.x, cube->player.y);

    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
    {
            // int minix = 1 - 2* signbit(cube->win.dirX);
            // int miniy = 1 - 2* signbit(cube->win.dirY);
            // if(cube->win.dirY >= 1)
            // else 
            // cube->player.y += miniy;
            // if(cube->win.dirX >= 1)
            // cube->player.x += cube->win.dirX * SPEED;
            // else 
            // cube->player.x += minix;

            // cube->player.y += cube->win.dirY * SPEED;
            // cube->player.x += cube->win.dirX * SPEED;
            cube->player.y += cube->v3.deltay;
            cube->player.x += cube->v3.deltax;


            mini_map_draw(cube);
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_LEFT))
    {
        // if (!is_wall(cube, cube->player.x - SPEED, cube->player.y))
        // {
            cube->v3.angle -= 0.01;
            // cube->v3.angle = fixangle(cube->v3.angle);
            if (cube->v3.angle < 0)
            {
                cube->v3.angle+= 2* M_PI;
            }
            cube->v3.deltax=cos(cube->v3.angle)*5;
            cube->v3.deltay=sin(cube->v3.angle)*5;


            
            // cube->player.x -= SPEED;
            mini_map_draw(cube);
        //     // ddanalizer(cube->mini_map,cube);
        // }
        /* code */
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
    {
            // cube->player.x -= cube->win.dirX * SPEED;
            // cube->player.y -= cube->win.dirY * SPEED;
            // printf("%f \n", cube->win.dirY * SPEED);
            cube->player.y -= cube->v3.deltay;
            cube->player.x -= cube->v3.deltax;
            // cube->player.y += SPEED;

            mini_map_draw(cube);
    }
    
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_RIGHT))
    {
        // if (!is_wall(cube, cube->player.x + SPEED, cube->player.y))
        // {
            // cube->player.x += SPEED;
            cube->v3.angle += 0.01;
                        if (cube->v3.angle > 2*M_PI)
            {
                cube->v3.angle -= 2* M_PI;
            }
            // cube->v3.angle = fixangle(cube->v3.angle);
            cube->v3.deltax=cos(cube->v3.angle)*5;
            cube->v3.deltay=sin(cube->v3.angle)*5;
            mini_map_draw(cube);
            // ddanalizer(cube->mini_map,cube);
        // }
        /* code */
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
    {
        exit(0);

        /* code */
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
    {
        // exit(0);
        // mini_map_draw(cube);
        // double oldDirX = cube->win.dirX;
        // cube->win.dirX = cube->win.dirX * cos(ROTSPEED) - cube->win.dirY * sin(ROTSPEED);
        // cube->win.dirY = oldDirX * sin(ROTSPEED) + cube->win.dirY * cos(ROTSPEED);
        // double oldPlaneX = cube->win.planeX;
        // cube->win.planeX = cube->win.planeX * cos(ROTSPEED) - cube->win.planeY * sin(ROTSPEED);
        // cube->win.planeY = oldPlaneX * sin(ROTSPEED) + cube->win.planeY * cos(ROTSPEED);
        // // performRotation(cube,0);
        mini_map_draw(cube);
        /* code */
    }
    if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
    {

        // double oldDirX = cube->win.dirX;
        // cube->win.dirX = cube->win.dirX * cos(-ROTSPEED) - cube->win.dirY * sin(-ROTSPEED);
        // cube->win.dirY = oldDirX * sin(-ROTSPEED) + cube->win.dirY * cos(-ROTSPEED);

        // // if (fabs(cube->win.dirX) == 1.0 && fabs(cube->win.dirY) != 0.0)
        // // {
        // //     cube->win.dirY=round(cube->win.dirY);
        // // }
        // // else if (fabs(cube->win.dirY) == 1.0 && fabs(cube->win.dirX) != 0.0)
        // // {
        // //     cube->win.dirX=round(cube->win.dirX);
        // // } 
        // double oldPlaneX = cube->win.planeX;
        // cube->win.planeX = cube->win.planeX * cos(-ROTSPEED) - cube->win.planeY * sin(-ROTSPEED);
        // cube->win.planeY = oldPlaneX * sin(-ROTSPEED) + cube->win.planeY * cos(-ROTSPEED);
        // // cube->player.angle-= 5; // counter clockwise rota;
        // performRotation(cube,1);

        mini_map_draw(cube);
        //    cube->player.angle+= 5;

        /* code */
    }
    // if (mlx_is_key_down(cube->window->mlx, MLX_KEY_UP))
    // {
    // cube->win.planeY +=0.05 ;
    // // mlx_put_string(cube->window->mlx,ft_itoa(cube->win.planeY),1500,800);
    // printf("plane y =%f\n",cube->win.planeY);
    //     // cube->player.angle-= 5; // counter clockwise rota;
    // // performRotation(cube,1);

    // // mini_map_draw(cube);
    //         //    cube->player.angle+= 5;


    //     /* code */
    // }
    //  if (mlx_is_key_down(cube->window->mlx, MLX_KEY_DOWN))
    // {
    // cube->win.planeY -=0.05 ;
    // printf("plane y =%f\n",cube->win.planeY);

    // // mlx_put_string(cube->window->mlx,ft_itoa(cube->win.planeY),1500,800);

    //     // cube->player.angle-= 5; // counter clockwise rota;
    // // performRotation(cube,1);

    // // mini_map_draw(cube);
    //         //    cube->player.angle+= 5;


    //     /* code */
    // }
    // mini_map_draw(&cube);
    // cube->angle = 33.0;
    // printf("%f\n", cube->player.angle);
    // test_rota(cube);
    // draw_rec(cube,10,10, 40);
    // draw_rec(cube,50,10, 40);
    // draw_rec(cube,90,10, 40);
    // draw_rec(cube,130,10, 40);
    // draw_rec(cube,170,10, 40);
    // draw_rec(cube,210,10, 40);

    // mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y,0xFF0000FF);
    // is_wall(cube,cube->player.x, cube->player.y);
    // cast_v1(cube);

    draw_player(cube, 0);
    // test_rota(cube);
            mini_map_draw(cube);
    // castingv2(cube);
    cast_v3(cube);
    // liner(cube,848,368);
    // mini_map_draw(cube);

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
