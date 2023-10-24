#include "cube3d.h"

void draw(mlx_t *mlx, mlx_image_t * img)
{
        mlx = mlx_init(WIDTH,HEIGHT,"almoka3ab",true);

    img = mlx_new_image(mlx,WIDTH-100,HEIGHT-100);
    // mlx_image_to_window(mlx,)

    mlx_loop(mlx);
	mlx_terminate(mlx);
}

char **read(int fd ,t_cube *cube)
{

char *longline = NULL;
char * line = get_next_line(fd);


while (line)
{
    longline
}



}

int main(int ac, char ** av){

    mlx_t *mlx;
    mlx_image_t *img;

int fd = open(av[1], O_RDONLY);



    // draw(mlx,img);
    return 0;
}