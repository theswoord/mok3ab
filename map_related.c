#include "cube3d.h"

void mini_map_draw(t_cube *cube)
{

    int x = 0;
    int y = 0;
    float step = 32 * MINISCALE;
    static int save = 0;
    // print_tableau(cube->map);
    while (y < cube->map_stuff.lines)
    {
        while (x < cube->map_stuff.max)
        {
            if (cube->map[y][x] == ' ')
                draw_2dblock(cube->mini_map,x*step,y*step,step,0x000000CF);
            if (cube->map[y][x] == '0' || cube->map[y][x] == 'S' || cube->map[y][x] == 'N'|| cube->map[y][x] == 'E'|| cube->map[y][x] == 'W')
                draw_2dblock(cube->mini_map,x*step,y*step,step,0xFFC0CBCF);
            if (cube->map[y][x] == '1')
                draw_2dblock(cube->mini_map,x*step,y*step,step,0x00A36CCF);
            if ((cube->map[y][x] == 'S' || cube->map[y][x] == 'N'|| cube->map[y][x] == 'E'|| cube->map[y][x] == 'W') && save == 0)
            {
                save = 1;
                cube->player.x = (x*step)+(int)MINIBLOCK/2;
                cube->player.y = (y*step)+(int)MINIBLOCK/2;
                draw_player(cube,MINIBLOCK);
                if(cube->map[y][x] == 'S')
                {
                cube->win.planeX = -0.66;
                cube->win.planeY = 0.0;
                cube->win.dirX = 0.0;
                cube->win.dirY = 1.0;
                cube->v3.angle = 3.0*M_PI/2.0;
                }
                if(cube->map[y][x] == 'N')
                {
                cube->win.planeX = 0.66;
                cube->win.planeY = 0.0;
                cube->win.dirX = 0.0;
                cube->win.dirY = -1.0;
                cube->v3.angle = M_PI/2.0;

                }
                if(cube->map[y][x] == 'E')
                {
                cube->win.planeX = 0;
                cube->win.planeY = -0.66;
                cube->win.dirX = -1.0;
                cube->win.dirY = 0.0;
                cube->v3.angle = 0;

                }
                if(cube->map[y][x] == 'W')
                {
                cube->win.dirX = 1.0;
                cube->win.dirY = 0.0;
                cube->win.planeX = 0.0;
                cube->win.planeY = 0.66;
                cube->v3.angle = M_PI;

                }
                // draw_player(cube,cube->mini_map,x*step,y*step,step);
            }
            
            x++;
        }
        x=0;
        y++;
    }
    // is_wall(cube,1,34);
    
}

void fill_map(t_cube *cube)
{
    int i = 0;
    int max = 0;
    int j = 0;
    while (cube->map[j])
    {
    cube->map_stuff.max = fmax(cube->map_stuff.max, ft_strlengnl(cube->map[j+1]));
    // printf()
        j++; // here
        /* code */
    }
    cube->map_stuff.lines = j;
    // printf("%d %d\n",cube->map_stuff.max,cube->map_stuff.lines);
    while (cube->map[i])
    {
        cube->map[i] = copy_and_fill(cube->map[i],cube->map_stuff.max,' ');
        i++; // here
        /* code */
    }
    
}