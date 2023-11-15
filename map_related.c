#include "cube3d.h"

void mini_map_draw(t_cube *cube)
{

    int x = 0;
    int y = 0;
    int step = 32;
    // print_tableau(cube->map);
    while (y < cube->map_stuff.lines)
    {
        while (x < cube->map_stuff.max)
        {
            if (cube->map[y][x] == ' ')
            {
                // printf("%d %d\n" , y , x);
                draw_2dblock(cube->mini_map,x*step,y*step,MINIBLOCK,0x000000FF);

                /* code */
            }
            if (cube->map[y][x] == '0')
            {
                draw_2dblock(cube->mini_map,x*step,y*step,MINIBLOCK,0xFFC0CBFF);

                /* code */
            }
            if (cube->map[y][x] == '1')
            {
                draw_2dblock(cube->mini_map,x*step,y*step,MINIBLOCK,0x00A36CFF);

                /* code */
            }
            if (cube->map[y][x] == 'S' || cube->map[y][x] == 'N'|| cube->map[y][x] == 'E'|| cube->map[y][x] == 'W')
            {
                draw_2dblock(cube->mini_map,x*step,y*step,MINIBLOCK,0xFFFF00FF);

                /* code */
            }
            
            x++;

            /* code */
        }
        x=0;
        y++;
        /* code */
    }
    



    // draw_2dblock(cube->mini_map,64,64,MINIBLOCK,0x000000FF);

}

void fill_map(t_cube *cube)
{
    int i = 0;
    int max = 0;
    int j = 0;
    while (cube->map[j])
    {
    cube->map_stuff.max = fmax(ft_strlengnl(cube->map[i]), ft_strlengnl(cube->map[i+1]));
        j++; // here
        /* code */
    }
    cube->map_stuff.lines = j;
    while (cube->map[i])
    {
        cube->map[i] = copy_and_fill(cube->map[i],cube->map_stuff.max,' ');
        i++; // here
        /* code */
    }
    
}