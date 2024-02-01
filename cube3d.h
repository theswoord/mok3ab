/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:27:56 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:25:13 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "MLX420/include/MLX42/MLX42.h"
# include "stdbool.h"
# include <limits.h>
# include <math.h>
# define WIDTH 1980.0
# define HEIGHT 1080.0
# define MB 32
# define SPEED 7.0
# define FOV 66 * 30
# define ROTSPEED 0.05
# define P1 3.1415926535
# define P2 M_PI / 2
# define P3 3 * M_PI / 2
# define RAD 0.0174533 / 30.0

enum
{
	VERTICAL = 88,
	HORIZONTAL = 99,
	PV = 1,
	PH = 0,

};

typedef struct s_textures
{
	mlx_texture_t	*EA;
	mlx_texture_t	*NO;
	mlx_texture_t	*WE;
	mlx_texture_t	*SO;
}					t_textures;

typedef struct s_win
{
	mlx_t			*mlx;
	mlx_image_t		*img;

}					t_win;
typedef struct s_colors
{
	int				F[3];
	int				C[3];
	unsigned long	*EA;
	unsigned long	*NO;
	unsigned long	*WE;
	unsigned long	*SO;
	unsigned long	finalfloor;
	unsigned long	finalceil;
	int				dim[8];

}					t_colors;

typedef struct s_map
{
	double			max;
	double			lines;
}					t_map;
typedef struct s_player
{
	double			x;
	double			y;
	double			angle;
}					t_player;

typedef struct s_lines
{
	unsigned long	color;
	double			startx;
	double			starty;
	double			endx;
	double			endy;
	double			savestarty;
}					t_lines;

typedef struct s_gatto
{
	int				what;
	int				side;
	double			wallx;
	double			wally;
	double			distance;
	double			deltax;
	double			deltay;
	double			angle;
	double			rayangle;
	double			rayx;
	double			rayy;
	double			xoffset;
	double			yoffset;
	double			Hx;
	double			Hy;
	double			Vx;
	double			Vy;
	int				wallheight;
	int				savewallheight;

}					t_gatto;

typedef struct s_bound
{
	int				frontx;
	int				fronty;
	int				backx;
	int				backy;
	int				leftx;
	int				lefty;
	int				rightx;
	int				righty;
	int				bound[2];

}					t_bound;

typedef struct s_cube
{
	t_gatto			v3;
	t_textures		*drawings;
	t_lines			dda;
	int				wallheight;
	t_player		p;
	t_map			misc;
	t_win			*window;
	t_colors		*colors;
	char			**textures;
	char			**background;
	char			**map;
	t_bound			bound;
	int				xp;
	int				yp;
	int				length;
	int				width;
	int				queue;
	const char		*wanted;
}					t_cube;

bool				found_after_space(char *str, char c);

void				read_map(int fd, t_cube *cube);
void				map_divider(char *textures, char *background, char *map,
						t_cube *cube);
void				free_tableau(char **tab);
void				rgb_parse(char *str, t_cube *cube);
void				mini_map_draw(t_cube *cube);
char				*copy_and_fill(char *str, int count, char c);
void				fill_map(t_cube *cube);
void				pressed(void *par);
void				parse_textures(t_cube *cube);
void				draw_background(mlx_image_t *img, t_cube *cube);
void				texture_set(t_cube *cube);
unsigned long		*extract_color(mlx_texture_t *texture, int *arr);
void				print_error(char *str);
void				set_background(t_cube *cube);
void				cast_v3(t_cube *cube);
void				draw_textures(t_cube *cube);
void				textured(t_cube *cube, unsigned long *row, int polarity,
						int height);
int					height_extract(t_cube *cube, char *texture);
void				boundaries(t_cube *cube);
void				img_destroy(t_cube *cube);
void				free_all(t_cube *cube);
void				free_stucts(t_cube *cube);
int					check_player(t_cube *cube);
void				check_cub(char *str);
int					check_walls(t_cube *cube);
void				map_check(t_cube *cube);
void				check_ft(t_cube *cube);
int					toupperv2(int c);
void				textured_inverted(t_cube *cube, unsigned long *row,
						int polarity, int height);
int					element_count(char *str, char c);
int					sp(char *str);
void				move_forward(t_cube *cube);
void				strife_right(t_cube *cube);
void				strife_left(t_cube *cube);
void				move_backward(t_cube *cube);
void				turn_right(t_cube *cube);
void				turn_left(t_cube *cube);
void				problem(char *str);
void	horizontal_part_one(t_cube *cube);
void	horizontal_rays(t_cube *cube);
void	vertical_part_one(t_cube *cube);
void	vertical_rays(t_cube *cube);
void	cast_v3_help(t_cube *cube);
void	parse_functions(int fd, t_cube *cube);
void	struct_init(t_cube *cube);
void	ptr_init(char **textures, char **background, char **map);
void	read_map_lost(char **save_ptr, char **map);
void	read_map_help(t_cube *cube, char **line, char **map);
void	read_textures(t_cube *cube, char **line, char **textures);
void	read_background(t_cube *cube, char **line, char **background);
#endif