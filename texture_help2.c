/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_help2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:44:25 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:13:27 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	textured(t_cube *cube, unsigned long *row, int polarity, int height)
{
	int		colm;
	int		rowm;
	double	steps;
	double	y;

	steps = fabs(cube->dda.endy - cube->dda.starty);
	y = cube->dda.starty;
	while (steps > 0)
	{
		y += 1;
		if (polarity == 0)
			colm = (int)(cube->v3.hx + 0.0002) % MB;
		else if (polarity == 1)
			colm = (int)(cube->v3.vy + 0.0002) % MB;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight
				* height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return ;
			mlx_put_pixel(cube->window->img, (cube->dda.startx), y, row[((height
						/ MB) * colm + (height * rowm))]);
		}
		steps--;
	}
}

void	textured_inverted(t_cube *cube, unsigned long *row, int polarity,
		int height)
{
	int		colm;
	int		rowm;
	double	steps;
	double	y;

	steps = fabs(cube->dda.endy - cube->dda.starty);
	y = cube->dda.starty;
	while (steps > 0)
	{
		y += 1;
		if (polarity == 0)
			colm = (int)(cube->v3.hx + 0.0002) % MB;
		else if (polarity == 1)
			colm = (int)(cube->v3.vy + 0.0002) % MB;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight
				* height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return ;
			mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				row[((height / MB) * 31 - colm + (height * rowm))]);
		}
		steps--;
	}
}

int	height_extract(t_cube *cube, char *texture)
{
	if (!ft_strncmp(texture, "EA", 3))
		return (cube->colors->dim[0]);
	if (!ft_strncmp(texture, "NO", 3))
		return (cube->colors->dim[2]);
	if (!ft_strncmp(texture, "WE", 3))
		return (cube->colors->dim[4]);
	if (!ft_strncmp(texture, "SO", 3))
		return (cube->colors->dim[6]);
	return (0);
}
