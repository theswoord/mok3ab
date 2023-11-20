#include "cube3d.h"


void draw_2dblock(mlx_image_t *img, int x , int y, int size, int color)
{
    int i = 0;
    int j = 0;

    while (i <= size)
    {
        while (j <= size)
        {
            // printf("%d %d\n",i , j);
            mlx_put_pixel(img,x+i,y+j,color);
            j++;
            /* code */
        }
        j = 0;
        i++;
        /* code */
    }
    
}
void draw_player(t_cube * cube, int size)
{
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y+3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y-3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-1,cube->player.y-4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y-1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+1,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+2,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-2,cube->player.y+3,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x-1,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+1,cube->player.y+4,0xFF0000FF);
    mlx_put_pixel(cube->mini_map,cube->player.x+2,cube->player.y+4,0xFF0000FF);



}

void draw_line(mlx_image_t *img,int start , int end , int lenght)
{
    int i = 0;

    while (i < lenght)
    {
        /* code */
        // mlx_put_pixel(image,start,)
        i++;
    }
    
}
void rotatePoint(float *x, float *y, float centerX, float centerY, float angle) {
    float s = sin(angle);
    float c = cos(angle);

    // Translate the point to the origin
    *x -= centerX;
    *y -= centerY;

    // Rotate the point
    float xNew = (*x * c) - (*y * s);
    float yNew = (*x * s) + (*y * c);

    // Translate the point back
    *x = xNew + centerX;
    *y = yNew + centerY;
}


void liner(t_cube *cube , int ex, int ey)
{
    int i =0;
    int disX = ex - cube->player.x ; //special dda
    int disY = ey - cube->player.y ;
    // printf("%d %d \n",disX,disY);
    int steps = 0;


    // steps = 
    if (abs(disX) > abs(disY))
    {
        steps = abs(disX);
        /* code */
    }
    else
        steps = abs(disY);
    
    float Xinc = disX / (float)steps; 
    float Yinc = disY / (float)steps; 

    float X = cube->player.x; 
    float Y = cube->player.y; 
    // rotatePoint(&X, &Y, cube->player.x, cube->player.y, 66);
    while (i <= steps){ 
        // printf("bda %d, ghadi %d steps %d\n",X,Y,steps);
        mlx_put_pixel(cube->mini_map,round(X),round(Y),0x0000FFFF); 
        X += Xinc; 
        Y += Yinc;
        i++;
    } 
}
// void generic_liner(t_cube * cube,)


// void cast(t_cube * cube)
// {
//     int i = 0;
//     cube->player.dirx = -1; // hado aytbdlo 3la 7sab starting position dial player
//     cube->player.diry = 0;
//     float planex = 0;
//     float planey = 0.66; // drna 0.66 bach ndiro 66 degrees FOV

//     while (/* condition */)
//     {
//         /* code */
//     }
    
// }

int is_wall(t_cube *cube , int x , int y )
{
    int i = 0;
    // float posX = (trunc((x)/ (cube->map_stuff.max*32*MINISCALE))); //blast width o height khassni size dial map 7it kayakhod dial map kamla
    if (cube->map[(int)y/32][(int)x/32]=='1')
    {
        return 1;
        /* code */
    }
    
    // float posY = (trunc((y)/(cube->map_stuff.lines*32*MINISCALE)));
    // int totalsteps = (cube->map_stuff.max*32*MINISCALE) / cube->map_stuff.max;
    // int mapX = (int)posX;
    // int mapY = (int)posY;
    // printf("max x = %d, max y= %d\n",cube->map_stuff.max*MINIBLOCK,cube->map_stuff.lines*MINIBLOCK);
    // // printf("%f , %f \n", posX, posY);
    // printf("x=%d y=%d    %d  POSX=%f POSY=%f     %d , %d [%c] \n",x,y,totalsteps,posX,posY, mapX, mapY,cube->map[mapY][mapX]);
    // printf("[%c]\n", cube->map[(int)y/32][(int)x/32]);
    return 0;
}

void cast_v1(t_cube *cube)
{
    int i = 0;
    float x = cube->player.x; 
    float y = cube->player.y; 


    while (!is_wall(cube,x,y))
    {
        // while (i < 5)
        // {
        //     /* code */
        //     i++;
        // }

        
        liner(cube,x++,y);
        // y += atan(x);
        // rotatePoint(&x,&y,x,y,15);
        // liner(cube,x,y);
        // liner(cube,x,y--);
        // liner(cube,x--,y);

        // x--;
        // liner(cube,x,y++);
        // liner(cube,x,y++);
        // liner(cube,x,y++);
        // liner(cube,x--,y++);
        // liner(cube,x--,y++);
        // liner(cube,x++,y++);
        // liner(cube,x++,y++);
        // liner(cube,x++,y++);
        // liner(cube,x,y++);
        // liner(cube,x,y++);

        // y++;
        /* code */
    }
    
}

void test_rota(t_cube *cube)
{
    int range = 0;
   float startx=cube->player.x;
   float starty=cube->player.y;
    float end_x = startx;
    float end_y = starty-100;

//  int angle = 0;
    // float angle = 33.0f;
    while (range < 30)
    {
     float radangle = (cube->player.angle + range) * (M_PI / 180);
    // int range =
     float distx =end_x - startx; // hado anbdl fihom 
     float disty = end_y - starty;
    float rotated_x = startx + (distx * cos(radangle) - disty * sin(radangle));
    float rotated_y = starty + (distx * sin(radangle) + disty * cos(radangle));
    // printf("sx %f sy %f disx %f disy %f rotatedx %f rotatedy %f \n",startx,starty,distx,disty, rotated_x, rotated_y);
    // if (!is_wall(cube,rotated_x,rotated_y))
    // {
    liner(cube,rotated_x,rotated_y);
        /* code */
    // }
    
    range++;
        /* code */
    }
    
}
//ln 25 col 28


// void rotate(t_cube *cube , )