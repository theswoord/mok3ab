/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:23 by nbouhali          #+#    #+#             */
/*   Updated: 2024/01/29 18:30:52 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	found_after_space(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ') || (str[i] == '\t'))
		{
			i++;
		}
		if (str[i] == c)
		{
			return (true);
		}
		else
			return (false);
		i++;
	}
	return (false);
}

void	free_tableau(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*copy_and_fill(char *str, int count, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(count + 1, 1);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (i < count)
	{
		new[i] = c;
		i++;
	}
	free(str);
	return (new);
}

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
			colm = (int)(cube->v3.Hx + 0.0002) % MINIBLOCK;
		else if (polarity == 1)
			colm = (int)(cube->v3.Vy + 0.0002) % MINIBLOCK;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight
				* height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return ;
			mlx_put_pixel(cube->window->img, (cube->dda.startx), y, row[((height
						/ MINIBLOCK) * colm + (height * rowm))]);
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
			colm = (int)(cube->v3.Hx + 0.0002) % MINIBLOCK;
		else if (polarity == 1)
			colm = (int)(cube->v3.Vy + 0.0002) % MINIBLOCK;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight
				* height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return ;
			mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				row[((height / MINIBLOCK) * 31 - colm + (height * rowm))]);
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

int	toupperv2(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 0;
	}
	if (c >= '0' && c <= '9')
	{
		c += 0;
	}
	return (c);
}

int	element_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}
