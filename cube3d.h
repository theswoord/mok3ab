#ifndef CUBE3D_H
#define CUBE3D_H


#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include "MLX420/include/MLX42/MLX42.h"
#include "stdbool.h"
#include <math.h>
#include <limits.h>
#define WIDTH 1980.0 //l3rd
#define HEIGHT 1080.0 //tol
#define MINIBLOCK 32 //square block
#define SPEED 7.0
#define FOV 66*30  // 32 
#define ROTSPEED 0.05
#define P1 3.1415926535
#define P2 M_PI/2
#define P3 3*M_PI/2
#define RAD 0.0174533 /30.0 //30

enum
{
    NO=8,
    SO=2,
    WE=4,
    EA=6,

    VERTICAL = 88,
    HORIZONTAL = 99,
    PV=1,
    PH=0,
    
};

typedef struct s_textures
{
    mlx_texture_t *EA;
    mlx_texture_t *NO;
    mlx_texture_t *WE;
    mlx_texture_t *SO;
}t_textures;

typedef struct s_win
{
    mlx_t *mlx;
    mlx_image_t *img;


} t_win;
typedef struct s_colors
{
    int F[3];
    int C[3];
    unsigned long *EA; //1
    unsigned long *NO; //2
    unsigned long *WE; //3
    unsigned long *SO; //4
    unsigned long finalfloor;
    unsigned long finalceil;
    int dim[8];

}t_colors ;

typedef struct s_map
{
    double max;
    double lines;
}t_map;
typedef struct s_player
{
    double x;
    double y;
    double angle; 
}t_player;

typedef struct s_lines
{
    unsigned long color;
    double startx;
    double starty;
    double endx;
    double endy;
    double savestarty;
}t_lines;


typedef struct s_gatto
{
    int what;
    int side;
    double wallx;
    double wally;
    double distance;
    double deltax;
    double deltay;
    double angle;
    double rayangle;
    double rayx;
    double rayy;
    double xoffset;
    double yoffset;
    double Hx;
    double Hy;
    double Vx;
    double Vy;
    int wallheight;
    int savewallheight;
    
}t_gatto;

typedef struct s_bound
{
    int frontx;
    int fronty;
    int backx;
    int backy;
    int leftx;
    int lefty;
    int rightx;
    int righty;
    int bound[2];
    
}t_bound;


typedef struct s_cube
{
   
    t_gatto v3;
    t_textures *drawings;
    t_lines dda;
    int wallheight;
    mlx_image_t *walls;
    t_player player;
    t_map map_stuff;
    t_win *window;
    t_colors *colors;
    char **textures;
    char **background;
    char **map;
    mlx_image_t *mini_map;
    t_bound bound;
    int xp;
    int yp;
    int length;
    int width;
    int queue;
    const char* wanted;
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
void draw_player(t_cube *cube);
void pressed(void *par);
int abs(int n);
void ddanalizer(mlx_image_t *img , t_cube *cube,int color);
void parse_textures(t_cube *cube);
void draw_background(mlx_image_t *img, t_cube *cube);
void texture_set(t_cube *cube); // you need to free
unsigned long *extract_color(mlx_texture_t *texture,int *arr);

void set_background(t_cube *cube);
void cast_v3(t_cube *cube);
void draw_textures(t_cube * cube );
void textured(t_cube *cube, unsigned long *row, int polarity, int height );
int height_extract(t_cube *cube, char *texture);
void boundaries(t_cube * cube);
void draw_sun(t_cube * cube);
void free_tab(char **tab);
void img_destroy(t_cube * cube);
void free_all(t_cube*cube);
void free_stucts(t_cube * cube);
int check_player(t_cube *cube);
void	check_cub(char *str);
int	check_walls(t_cube *cube);
void map_check(t_cube *cube);
void check_double_lines(char *str);
void check_ft(t_cube *cube);
int	toupperv2(int c);
void textured_inverted(t_cube *cube, unsigned long *row, int polarity, int height);
int element_count(char* str, char c);
#endif