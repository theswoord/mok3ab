#include "cube3d.h"

void mini_map_draw(t_cube *cube)
{

    int x = 0;
    int y = 0;
    double step = 32;
    static int save = 0;
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
                cube->player.x = (x*step)+MINIBLOCK/2;
                cube->player.y = (y*step)+MINIBLOCK/2;
                draw_player(cube);
                if(cube->map[y][x] == 'S')
                cube->v3.angle = P2;
                if(cube->map[y][x] == 'N')
                cube->v3.angle = P3;
                if(cube->map[y][x] == 'E')
                cube->v3.angle = 0.0;
                if(cube->map[y][x] == 'W')
                cube->v3.angle = M_PI;
            }
            
            x++;
        }
        x=0;
        y++;
    }
    
}

void fill_map(t_cube *cube)
{
    int i = 0;
    int j = 0;
    while (cube->map[j])
    {
    cube->map_stuff.max = fmax(cube->map_stuff.max, ft_strlengnl(cube->map[j+1]));
        j++; 
    }
    cube->map_stuff.lines = j;
    while (cube->map[i])
    {
        cube->map[i] = copy_and_fill(cube->map[i],cube->map_stuff.max,' ');
        i++;
    }
    
}