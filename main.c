#include "cube3d.h"

void draw(mlx_t *mlx, mlx_image_t *img, t_cube *cube)
{
    mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);

    // img = mlx_new_image(mlx,WIDTH,HEIGHT);
    // mlx_image_to_window(mlx,)
    // mlx_pn
    mlx_texture_t *hh;
    mlx_texture_t *hhj;
    mlx_image_t *hhhh;

    // hh = mlx_load_png("./blood.png");
    // hhhh = mlx_texture_to_image(mlx, hh);
    hhhh = mlx_new_image(mlx, WIDTH, HEIGHT);
    int x = 0;
    int y = 0;
    unsigned long color = 0xc86400;
    unsigned long FF = 0xc86400FF;
    unsigned long floor = (cube->colors.F[0] << 24) | (cube->colors.F[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;
    unsigned long s9ef = (cube->colors.C[0] << 24) | (cube->colors.C[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;

    printf("l3rd %d , lines %d \n",WIDTH,HEIGHT);
    while (x < WIDTH)
    {
        // x = 0;
        while (y < HEIGHT/2)
        {
            mlx_put_pixel(hhhh, x, y, s9ef );
            y++;
            /* code */
        }
        // while (y < HEIGHT/2)
        // {
        //     mlx_put_pixel(hhhh, x +HEIGHT/2, y, floor );
        //     y++;
        //     /* code */
        // }
        
        y=0;
        x++;
    }
    mlx_image_to_window(mlx, hhhh, 0, 0);
    // mlx_
    // hh.
    // hhj =  mlx_new_image(mlx,100,100);
    // mlx_put_string(mlx,"asdkfjlaksfjklas", 90 ,100);
    // // mlx_image_to_window(mlx , hh ,300,300);
    // mlx_image_to_window(mlx , hh,100,100);
    // // mlx_put_pixel()
    mlx_loop(mlx);
    mlx_terminate(mlx);
}
void map_divider(char * textures , char *background , char *map , t_cube *cube)
{
    cube->background = ft_split (background, '\n');
    cube->textures = ft_split (textures, '\n');
    cube->map = ft_split (map, '\n');

}

void rgb_parse(char * str, t_cube *cube)
{
    // str = ft_strtrim(str, " \t");
    int i = 0;
    char * 
    // while (str[i])
    // {
        
    //     i++;
    //     /* code */
    // }
    
}

void read_map(int fd, t_cube *cube)
{

    char *textures = NULL;
    char *background = NULL;
    char *map = NULL;

    char *line = get_next_line(fd);

    while (line)
    {
        // longline
        if (found_after_space(line,'F') || found_after_space(line,'C') )
        {
            background = ft_strjoingnl(background,line);
            free(line);
            /* code */
        }
            else if (found_after_space(line,'N') || found_after_space(line,'S') ||found_after_space(line,'W') ||found_after_space(line,'E'))
        {
            textures = ft_strjoingnl(textures,line);
            free(line);
            /* code */
        }
           else if (found_after_space(line,'1'))
        {
            map = ft_strjoingnl(map,line);
            free(line);
            /* code */
        }
        else
        {
            free (line);
        }
        line = get_next_line(fd);

    }
    map_divider(textures,background,map,cube);
    // return line;
}

int main(int ac, char **av)
{
    t_cube cube;
    mlx_t *mlx;
    mlx_image_t *img;

    int fd = open(av[1], O_RDONLY);
    read_map(fd,   &cube );
    // printf("%s\n", cube.background[0]);
    print_tableau(cube.textures);
    printf("---------------------\n");
    print_tableau(cube.map);
    printf("---------------------\n");

    print_tableau(cube.background);

    // draw(mlx, img);
    return 0;
}