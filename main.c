/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:06 by nbouhali          #+#    #+#             */
/*   Updated: 2024/01/29 18:38:50 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	texture_set(t_cube *cube)
{
	int	i;

	i = 0;
	cube->colors->EA = extract_color(cube->drawings->EA, cube->colors->dim);
	cube->colors->NO = extract_color(cube->drawings->NO, cube->colors->dim);
	cube->colors->WE = extract_color(cube->drawings->WE, cube->colors->dim);
	cube->colors->SO = extract_color(cube->drawings->SO, cube->colors->dim);
	while (i < 8)
	{
		if (cube->colors->dim[i] != 32)
		{
			print_error("Error\nmore or less than 32 bit\n");
			exit(1);
		}
		i++;
	}
}

unsigned long	*extract_color(mlx_texture_t *texture, int *arr)
{
	int				i;
	int				j;
	static int		k;
	int				total;
	unsigned long	*tmp;

	i = 0;
	j = 0;
	total = texture->height * texture->width;
	tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
	if (!tmp)
		return (NULL);
	arr[k] = texture->height;
	arr[k + 1] = texture->width;
	k += 2;
	while (i < total)
	{
		tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j
				+ 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j
				+ 3]);
		j += texture->bytes_per_pixel;
		i++;
	}
	mlx_delete_texture(texture);
	return (tmp);
}

void	init_mlx(t_cube *cube)
{
	cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", false);
	cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0);
}

void	set_background(t_cube *cube)
{
	cube->colors->finalfloor = (cube->colors->F[0] << 24)
		| (cube->colors->F[1] << 16)
		| (cube->colors->F[2] << 8)
		| 0xFF;
	cube->colors->finalceil = (cube->colors->C[0] << 24)
		| (cube->colors->C[1] << 16)
		| (cube->colors->C[2] << 8)
		| 0xFF;
}

void	draw_background(mlx_image_t *img, t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(img, x, y, cube->colors->finalceil);
			y++;
		}
		while (y < HEIGHT)
		{
			mlx_put_pixel(img, x, y, cube->colors->finalfloor);
			y++;
		}
		y = 0;
		x++;
	}
}

void	map_divider(char *textures, char *background, char *map, t_cube *cube)
{
	if (cube->queue < 6)
	{
		print_error("Error\nSomething wrong with the map");
		exit(1);
	}
	cube->background = ft_split(background, '\n');
	if (element_count(background, ',') > 4)
	{
		print_error("Error\ncheck the RGB params");
		exit(1);
	}
	free(background);
	cube->textures = ft_split(textures, '\n');
	free(textures);
	cube->map = ft_split(map, '\n');
	free(map);
}

void	parse(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->background[i])
	{
		rgb_parse(cube->background[i], cube);
		i++;
	}
	set_background(cube);
}

void	set_rgb(char **tab, t_cube *cube, char what)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		print_error("Error\nnumber of color are more or less than 3.\n");
		exit(1);
	}
	i = 0;
	while (tab[i])
	{
		if (what == 'F')
		{
			cube->colors->F[i] = ft_atoi(tab[i]);
			if ((ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0))
			{
				print_error("Error\ncolor range more than 255 or less than 0\n");
				exit(1);
			}
		}
		if (what == 'C')
		{
			cube->colors->C[i] = ft_atoi(tab[i]);
			if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
			{
				print_error("Error\ncolor range more than 255 or less than 0\n");
				exit(1);
			}
		}
		i++;
	}
}

void	rgb_parse(char *str, t_cube *cube)
{
	char	what;
	char	**work;
	char	*tmp;

	what = 0;
	work = NULL;
	tmp = NULL;
	if (ft_strnstr(str + return_after_space(str), "F ", 2))
	{
		tmp = ft_strtrim(str, " \tF");
		free(str);
		what = 'F';
	}
	else if (ft_strnstr(str + return_after_space(str), "C ", 2))
	{
		tmp = ft_strtrim(str, " \tC");
		free(str);
		what = 'C';
	}
	else
	{
		print_error("Error\nColor parse problems \n");
		exit(1);
	}
	work = ft_split(tmp, ',');
	free(tmp);
	set_rgb(work, cube, what);
	free_tableau(work);
}

void	read_map(int fd, t_cube *cube)
{
	char	*textures;
	char	*background;
	char	*map;
	char	*line;
	char	*save_ptr;

	textures = NULL;
	background = NULL;
	map = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		exit(1);
	}
	while (line)
	{
		if (ft_strnstr(line, "F ", ft_strlen(line)) || ft_strnstr(line, "C ",
				ft_strlen(line)))
		{
			background = ft_strjoingnl(background, line);
			cube->queue++;
			free(line);
		}
		else if (ft_strnstr(line, "EA ", ft_strlen(line)) || ft_strnstr(line,
				"WE ", ft_strlen(line)) || ft_strnstr(line, "SO ",
				ft_strlen(line)) || ft_strnstr(line, "NO ", ft_strlen(line)))
		{
			textures = ft_strjoingnl(textures, line);
			cube->queue++;
			free(line);
		}
		else
		{
			map = ft_strjoingnl(map, line);
			free(line);
			if (ft_strnstr(map, "11", ft_strlen(map)) && cube->queue != 6)
			{
				print_error("Error\neither Map is not last\n");
				exit(1);
			}
		}
		line = get_next_line(fd);
	}
	save_ptr = ft_strtrim(map, "\n");
	free(map);
	if (ft_strnstr(save_ptr, "\n\n", ft_strlen(save_ptr)))
	{
		print_error("Error\nmany newlines found in your map\n");
		exit(1);
	}
	map_divider(textures, background, save_ptr, cube);
}

int	main(int ac, char **av)
{
	int		fd;
	t_cube	*cube;

	if (ac != 2)
	{
		print_error("Error\nmore or less than 2 ac\n");
		return (0);
	}
	check_cub(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	cube = (t_cube *)malloc(sizeof(t_cube));
	ft_memset(cube, 0, sizeof(t_cube));
	cube->window = (t_win *)malloc(sizeof(t_win));
	ft_memset(cube, 0, sizeof(t_win));
	cube->colors = (t_colors *)malloc(sizeof(t_colors));
	ft_memset(cube, 0, sizeof(t_colors));
	cube->drawings = (t_textures *)malloc(sizeof(t_textures));
	ft_memset(cube, 0, sizeof(t_textures));
	cube->wanted = "01EWSN ";
	read_map(fd, cube);
	check_ft(cube);
	parse(cube);
	parse_textures(cube);
	if (!cube->drawings->NO || !cube->drawings->EA || !cube->drawings->WE
		|| !cube->drawings->SO)
	{
		print_error("Error\ncheck the PNG or read ^above^ \n");
		exit(1);
	}
	texture_set(cube);
	init_mlx(cube);
	fill_map(cube);
	map_check(cube);
	if (!check_player(cube) || !check_walls(cube))
		exit(1);
	draw_background(cube->window->img, cube);
	mini_map_draw(cube);
	cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	cube->v3.deltay = sin(cube->v3.angle) * SPEED;
	mlx_loop_hook(cube->window->mlx, &pressed, cube);
	mlx_loop(cube->window->mlx);
	mlx_terminate(cube->window->mlx);
	return (0);
}

double	horizontal(t_cube *cube)
{
	double	tanges;
	int		mapy;
	int		mapx;

	tanges = -1 / tan(cube->v3.rayangle);
	if (cube->v3.rayangle > M_PI)
	{
		cube->v3.rayy = ((int)cube->player.y / MINIBLOCK * MINIBLOCK) - 0.0001;
		cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges
			+ (int)cube->player.x;
		cube->v3.yoffset = -MINIBLOCK;
		cube->v3.xoffset = -cube->v3.yoffset * tanges;
	}
	if (cube->v3.rayangle < M_PI)
	{
		cube->v3.rayy = ((int)cube->player.y / MINIBLOCK) * MINIBLOCK
			+ MINIBLOCK;
		cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges
			+ (int)cube->player.x;
		cube->v3.yoffset = MINIBLOCK;
		cube->v3.xoffset = -cube->v3.yoffset * tanges;
	}
	if (cube->v3.rayangle == 0)
		cube->v3.xoffset = MINIBLOCK;
	if (cube->v3.rayangle == M_PI)
		cube->v3.xoffset = -MINIBLOCK;
	while (1)
	{
		mapy = (int)cube->v3.rayy / MINIBLOCK;
		mapx = (int)cube->v3.rayx / MINIBLOCK;
		if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max)
			|| (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
			break ;
		else
		{
			if (cube->v3.rayy < (cube->map_stuff.lines * MINIBLOCK)
				&& cube->v3.rayy > 0)
				cube->v3.rayy += cube->v3.yoffset;
			else
				return (99999889997897897);
			if (cube->v3.rayx < (cube->map_stuff.max * MINIBLOCK)
				&& cube->v3.rayx > 0)
				cube->v3.rayx += cube->v3.xoffset;
			else
				return (99999988899997897);
		}
	}
	cube->v3.Hx = cube->v3.rayx;
	cube->v3.Hy = cube->v3.rayy;
	return (sqrt(pow(cube->v3.Hx - cube->player.x, 2) + pow(cube->v3.Hy
				- cube->player.y, 2)));
}

double	vertical(t_cube *cube)
{
	double	tanges;
	int		mapy;
	int		mapx;

	tanges = -tan(cube->v3.rayangle);
	if (cube->v3.rayangle > P2 && cube->v3.rayangle < P3)
	{
		cube->v3.rayx = ((int)cube->player.x / MINIBLOCK) * MINIBLOCK - 0.0001;
		cube->v3.rayy = ((int)cube->player.x - cube->v3.rayx) * tanges
			+ (int)cube->player.y;
		cube->v3.xoffset = -MINIBLOCK;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle < P2 || cube->v3.rayangle > P3)
	{
		cube->v3.rayx = ((int)cube->player.x / MINIBLOCK * MINIBLOCK)
			+ MINIBLOCK;
		cube->v3.rayy = ((int)cube->player.x - cube->v3.rayx) * tanges
			+ (int)cube->player.y;
		cube->v3.xoffset = MINIBLOCK;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle == P2)
		cube->v3.yoffset = MINIBLOCK;
	if (cube->v3.rayangle == P3)
		cube->v3.yoffset = -MINIBLOCK;
	while (1)
	{
		mapy = (int)cube->v3.rayy / MINIBLOCK;
		mapx = (int)cube->v3.rayx / MINIBLOCK;
		if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max)
			|| (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
			break ;
		else
		{
			if (cube->v3.rayy < (cube->map_stuff.lines * MINIBLOCK)
				&& cube->v3.rayy > 0)
				cube->v3.rayy += cube->v3.yoffset;
			else
				return (99999889997897897);
			if (cube->v3.rayx < (cube->map_stuff.max * MINIBLOCK)
				&& cube->v3.rayx > 0)
				cube->v3.rayx += cube->v3.xoffset;
			else
				return (99999889789997897);
		}
	}
	cube->v3.Vx = cube->v3.rayx;
	cube->v3.Vy = cube->v3.rayy;
	return (sqrt(pow(cube->v3.Vx - cube->player.x, 2) + pow(cube->v3.Vy
				- cube->player.y, 2)));
}

void	cast_v3(t_cube *cube)
{
	int		i;
	double	dh;
	double	dv;
	double	ca;

	i = 0;
	cube->v3.rayangle = cube->v3.angle - WIDTH / 2 * RAD;
	draw_background(cube->window->img, cube);
	while (i < WIDTH)
	{
		if (cube->v3.rayangle <= 0)
			cube->v3.rayangle += 2 * M_PI;
		if (cube->v3.rayangle >= 2 * M_PI)
			cube->v3.rayangle -= 2 * M_PI;
		dh = horizontal(cube);
		dv = vertical(cube);
		cube->v3.wallheight = (HEIGHT * MINIBLOCK) / cube->v3.distance;
		cube->v3.savewallheight = cube->v3.wallheight;
		if (cube->v3.wallheight > HEIGHT)
			cube->v3.wallheight = HEIGHT;
		if (dh < dv)
		{
			cube->v3.distance = dh;
			cube->v3.side = 0;
		}
		else
		{
			cube->v3.distance = dv;
			cube->v3.side = 1;
		}
		ca = cube->v3.angle - cube->v3.rayangle;
		if (ca <= 0)
			ca += 2 * M_PI;
		if (ca >= 2 * M_PI)
			ca -= 2 * M_PI;
		cube->v3.distance = cube->v3.distance * cos(ca);
		cube->dda.startx = i - 1;
		cube->dda.starty = HEIGHT / 2 - cube->v3.wallheight / 2;
		cube->dda.savestarty = HEIGHT / 2 - cube->v3.savewallheight / 2;
		cube->dda.endy = cube->v3.wallheight / 2 + HEIGHT / 2;
		cube->v3.rayangle += RAD;
		draw_textures(cube);
		i++;
	}
}

void	draw_textures(t_cube *cube)
{
	if (cube->v3.side == PH)
	{
		if (cube->v3.rayangle < M_PI)
			textured_inverted(cube, cube->colors->SO, cube->v3.side,
				height_extract(cube, "SO"));
		else
			textured(cube, cube->colors->NO, cube->v3.side, height_extract(cube,
					"NO"));
	}
	else
	{
		if (cube->v3.rayangle > P3 || cube->v3.rayangle < P2)
			textured(cube, cube->colors->EA, cube->v3.side, height_extract(cube,
					"EA"));
		else
			textured_inverted(cube, cube->colors->WE, cube->v3.side,
				height_extract(cube, "WE"));
	}
}
