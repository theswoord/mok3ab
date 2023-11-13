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


typedef struct s_cube
{
   
    
    // s_mlx mlxstruct;
    char **textures;
    char **background;
    char **map;

} t_cube;


bool found_after_space(char *str, char c);













#endif