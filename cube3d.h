#ifndef CUBE3D_H
#define CUBE3D_H


#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include "MLX420/include/MLX42/MLX42.h"
#include "stdbool.h"
#include "math.h"
#define WIDTH 1980 //l3rd
#define HEIGHT 1080 //tol
#define MINIBLOCK 32 //square block
#define MINISCALE 1

enum
{
    W= 87,
    S= 83,
    A= 65,
    D= 68,

    UP=265,
    DOWN=264,
    LEFT=263,
    RIGHT=262,
};
typedef struct s_win
{
    mlx_t *mlx;
    mlx_image_t *img;


} t_win;
typedef struct s_colors
{
    /* data */
    int F[3];
    int C[3];
}t_colors ;

typedef struct s_map
{
    int max;
    int lines;
}t_map;
typedef struct s_player
{
    int x;
    int y;
    float dirx;
    float diry;
}t_player;

typedef struct s_lines
{
    int startx;
    int starty;
    int endx;
    int endy;



}t_lines;

typedef struct s_cube
{
   
    
    // s_mlx mlxstruct;
    // mlx_image_t *anim[2]; // troll
    t_player player;
    t_map map_stuff;
    t_win *window;
    t_colors colors;
    char **textures;
    char **background;
    char **map;
    mlx_image_t *mini_map;


} t_cube;


bool found_after_space(char *str, char c);

/*map*/
void read_map(int fd, t_cube *cube);
void map_divider(char * textures , char *background , char *map , t_cube *cube);
void print_tableau(char ** tableau);
void free_tableau(char ** tab);
void rgb_parse(char * str, t_cube *cube);
void draw_2dblock(mlx_image_t *img, int x , int y, int size, int color);
void mini_map_draw(t_cube *cube);
char* copy_and_fill(char *str, int count , char c);
void fill_map(t_cube *cube);
void draw_player(t_cube *cube, int size);
void pressed(mlx_key_data_t keydata,void *par);
int abs(int n);
void liner(t_cube *cube , int ex, int ey);
int is_wall(t_cube *cube , int x , int y );






#endif

// x= 848, y= 368