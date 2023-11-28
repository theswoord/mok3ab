#include "cube3d.h"

// mlx_loop_hook()

void pressed(mlx_key_data_t keydata,void *par)
{
    // mlx_key_data_t *hh;
    // hh->key.
    t_cube *cube = par;
            // printf("x= %d, y= %d\n", cube->player.x, cube->player.y);

    if (keydata.key == W)
    {
        if (!is_wall(cube,cube->player.x, cube->player.y-SPEED))
        {
        cube->player.y+=cube->win.dirY*SPEED;
        cube->player.x+=cube->win.dirX*SPEED;
    mini_map_draw(cube);
            // ddanalizer(cube->mini_map,cube);

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
            // ddanalizer(cube->mini_map,cube);

        }
        /* code */
    }    
    if (keydata.key == S)
    {
                 if (!is_wall(cube,cube->player.x, cube->player.y+SPEED))
        {
                    cube->player.y-=cube->win.dirY*SPEED;
        cube->player.x-=cube->win.dirX*SPEED;
        // cube->player.y+=SPEED;
    mini_map_draw(cube);
            // ddanalizer(cube->mini_map,cube);

        }
        /* code */
    }   
     if (keydata.key == D)
    {
                 if (!is_wall(cube,cube->player.x+SPEED, cube->player.y))
        {
        cube->player.x+=SPEED;
        
    mini_map_draw(cube);
            // ddanalizer(cube->mini_map,cube);

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
    // mini_map_draw(cube);
           double oldDirX = cube->win.dirX;
      cube->win.dirX = cube->win.dirX * cos(ROTSPEED) - cube->win.dirY * sin(ROTSPEED);
      cube->win.dirY = oldDirX * sin(ROTSPEED) + cube->win.dirY * cos(ROTSPEED);
      double oldPlaneX = cube->win.planeX;
      cube->win.planeX = cube->win.planeX * cos(ROTSPEED) - cube->win.planeY * sin(ROTSPEED);
      cube->win.planeY = oldPlaneX * sin(ROTSPEED) + cube->win.planeY * cos(ROTSPEED);
    // performRotation(cube,0);
    mini_map_draw(cube);
        /* code */
    } 
       if (keydata.key ==ROTA_RIGHT)
    {

 double oldDirX = cube->win.dirX;
      cube->win.dirX = cube->win.dirX * cos(-ROTSPEED) - cube->win.dirY * sin(-ROTSPEED);
      cube->win.dirY = oldDirX * sin(-ROTSPEED) + cube->win.dirY * cos(-ROTSPEED);
      double oldPlaneX = cube->win.planeX;
      cube->win.planeX = cube->win.planeX * cos(-ROTSPEED) - cube->win.planeY * sin(-ROTSPEED);
      cube->win.planeY = oldPlaneX * sin(-ROTSPEED) + cube->win.planeY * cos(-ROTSPEED);
        // cube->player.angle-= 5; // counter clockwise rota;
    // performRotation(cube,1);

    mini_map_draw(cube);
            //    cube->player.angle+= 5;


        /* code */
    }
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

    draw_player(cube,0);
    // test_rota(cube);
    img_clear(cube->window->img,WIDTH,HEIGHT);
    castingv2(cube);
    // liner(cube,848,368);
    // mini_map_draw(cube);
    
    // printf("key is %d pressed = %d\n",cube->player.y, keydata.key);
    
}

void img_clear(mlx_image_t * img, int width, int height)
{
    int i = 0;
    int j = 0;
    while (j < height)
    {
        while (i < width)
        {
            /* code */
            mlx_put_pixel(img,i,j,0x000000FF);
            i++;
        }
        i=0;
        j++;
        /* code */
    }
    
}
