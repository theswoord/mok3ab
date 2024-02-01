/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:20 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:19:48 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_north(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t NO");
	cube->drawings->NO = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_south(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t SO");
	cube->drawings->SO = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_east(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t EA");
	cube->drawings->EA = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_west(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t WE");
	cube->drawings->WE = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_textures(t_cube *c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (c->textures[i])
	{
		if (ft_strnstr(c->textures[i] + sp(c->textures[i]), "NO .", 4))
			parse_north(c, &tmp, &i);
		else if (ft_strnstr(c->textures[i] + sp(c->textures[i]), "SO .", 4))
			parse_south(c, &tmp, &i);
		else if (ft_strnstr(c->textures[i] + sp(c->textures[i]), "EA .", 4))
			parse_east(c, &tmp, &i);
		else if (ft_strnstr(c->textures[i] + sp(c->textures[i]), "WE .", 4))
			parse_west(c, &tmp, &i);
		else
			problem("Error\nTexture parse\n");
		i++;
	}
	free_tableau(c->textures);
}

int	sp(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}
