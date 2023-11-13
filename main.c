#include "cube3d.h"

void draw(mlx_t *mlx, mlx_image_t *img)
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
    unsigned long floor = (220 << 24) | (100 << 16) | (0 << 8) | 0xFF; // hadi parsing dial color;
    unsigned long s9ef = (225 << 24) | (30 << 16) | (0 << 8) | 0xFF; // hadi parsing dial color;

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

// char **read_map(int fd, t_cube *cube)
// {

//     char *longline = NULL;
//     char *line = get_next_line(fd);

//     while (line)
//     {
//         // longline
//         if (found_after_space(line,'F'))
//         {
//             /* code */
//         }
        
//     }

//     // return line;
// }

int main(int ac, char **av)
{

    mlx_t *mlx;
    mlx_image_t *img;

    int fd = open(av[1], O_RDONLY);

    draw(mlx, img);
    return 0;
}