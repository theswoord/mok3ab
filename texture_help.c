/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:31:57 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:50:29 by nbouhali         ###   ########.fr       */
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
			problem("Error\nmore or less than 32 bit\n");
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
		problem("Error\nSomething wrong with the map");
	cube->background = ft_split(background, '\n');
	if (element_count(background, ',') > 4)
		problem("Error\ncheck the RGB params");
	free(background);
	cube->textures = ft_split(textures, '\n');
	free(textures);
	cube->map = ft_split(map, '\n');
	free(map);
}
