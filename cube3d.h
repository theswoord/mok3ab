#ifndef CUBE3D_H
#define CUBE3D_H


#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include "MLX420/include/MLX42/MLX42.h"
#include "stdbool.h"

#define WIDTH 800 //l3rd
#define HEIGHT 600 //tol

// typedef struct s_mlx
// {



// } t_mlx;
typedef struct s_colors
{
    /* data */
    int F[3];
    int C[3];
}t_colors ;



typedef struct s_cube
{
   
    
    // s_mlx mlxstruct;
    t_colors colors;
    char **textures;
    char **background;
    char **map;

} t_cube;


bool found_after_space(char *str, char c);

/*map*/
void read_map(int fd, t_cube *cube);
void map_divider(char * textures , char *background , char *map , t_cube *cube);
void print_tableau(char ** tableau);











#endif