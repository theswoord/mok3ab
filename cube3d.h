#ifndef CUBE3D_H
#define CUBE3D_H


#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include "MLX420/include/MLX42/MLX42.h"
#include "stdbool.h"
#include "math.h"
#include <limits.h>
#define WIDTH 1980 //l3rd
#define HEIGHT 1080 //tol
#define MINIBLOCK 32 //square block
#define MINISCALE 1
#define SPEED 1.0
#define FOV 66*8
#define ROTSPEED 0.05
#define P1 3.1415926535
#define P2 M_PI/2
#define P3 3*M_PI/2
#define RAD 0.0174533/8.0



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

    ROTA_LEFT = 263,
    ROTA_RIGHT = 262,

    NO=8,
    SO=2,
    WE=4,
    EA=6,

    VERTICAL = 88,
    HORIZONTAL = 99,
};

typedef struct s_textures
{
    mlx_texture_t *NO;
    mlx_texture_t *SO;
    mlx_texture_t *WE;
    mlx_texture_t *EA;

}t_textures;

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
    unsigned char *NO;
    unsigned char *SO;
    unsigned char *WE;
    unsigned char *EA;
    unsigned long finalfloor;
    unsigned long finalceil;
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

    float angle; 
    float distx;
    float disty;
    float real_dis;
    int ray_number;

}t_player;

typedef struct s_lines
{
    unsigned long color;
    double startx;
    double starty;
    double endx;
    double endy;

}t_lines;

typedef struct s_lodev
{
double dirX; // first direction fach kaychof ila kan N(X=0,Y=-1)S(X=0,Y=+1)E(X=+1,Y=0)W(X=-1,Y=0)
double dirY;
double planeX;
double planeY;
double RaydirecX;
double RaydirecY;
int posinmapX;
int posinmapY;
double sideDistX;
double sideDistY;
double deltaDistX;
double deltaDistY;
      //double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
      double cameraX; // x being 0 to WIDTH;
}t_lodev;

typedef struct s_gatto
{
    int what;
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
}t_gatto;

typedef struct s_cube
{
   
    
    // s_mlx mlxstruct;
    // mlx_image_t *anim[2]; // troll
    t_gatto v3;
    t_textures drawings;
    t_lodev win;
    t_lines dda;
    int wallheight;
    mlx_image_t *walls;
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
void pressed(void *par);
int abs(int n);
void liner(t_cube *cube , int ex, int ey);
int is_wall(t_cube *cube , int x , int y );
void cast_v1(t_cube *cube);
int maxed(int a ,int b );
void test_rota(t_cube *cube);
void draw_wall(t_cube * cube);
void draw_verline(t_cube * cube,int x , int ystart , int yend  );
void draw_rec(mlx_image_t *img ,t_cube *cube , int thickness , int color );
void img_clear(mlx_image_t * img, int width, int height);
void castingv2(t_cube *cube);
void ddanalizer(mlx_image_t *img , t_cube *cube,int color);
double normalizeAngle(double angle);
void performRotation(t_cube *cube, int clockwise);
void parse_textures(t_cube *cube);
void draw_background(mlx_image_t *img, t_cube *cube);
unsigned char *extract_color(mlx_texture_t *texture);
void texture_set(t_cube *cube); // you need to free
void textured(mlx_image_t *img , t_cube *cube, unsigned long *row);
void set_background(t_cube *cube);
void cast_v3(t_cube *cube);
float d2r(float deg );
int fixangle(int a);
// void rand_dda(mlx_image_t *img,int sx , int sy , int ex, int ey);

#endif

// x= 848, y= 368

//320 //160 