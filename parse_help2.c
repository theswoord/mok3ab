/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:33:05 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:50:20 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
		problem("Error\nnumber of color are more or less than 3.\n");
	i = 0;
	while (tab[i])
	{
		if (what == 'F')
		{
			cube->colors->F[i] = ft_atoi(tab[i]);
			if ((ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0))
				problem("Error\ncolor range more than 255 or less than 0\n");
		}
		if (what == 'C')
		{
			cube->colors->C[i] = ft_atoi(tab[i]);
			if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
				problem("Error\ncolor range more than 255 or less than 0\n");
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
	if (ft_strnstr(str + sp(str), "F ", 2))
	{
		tmp = ft_strtrim(str, " \tF");
		free(str);
		what = 'F';
	}
	else if (ft_strnstr(str + sp(str), "C ", 2))
	{
		tmp = ft_strtrim(str, " \tC");
		free(str);
		what = 'C';
	}
	else
		problem("Error\nColor parse problems \n");
	work = ft_split(tmp, ',');
	free(tmp);
	set_rgb(work, cube, what);
	free_tableau(work);
}

void	read_background(t_cube *cube, char **line, char **background)
{
	*background = ft_strjoingnl(*background, *line);
	cube->queue++;
	free(*line);
}

void	read_textures(t_cube *cube, char **line, char **textures)
{
	*textures = ft_strjoingnl(*textures, *line);
	cube->queue++;
	free(*line);
}
