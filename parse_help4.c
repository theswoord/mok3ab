/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:33:27 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:09:13 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_north(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t NO");
	cube->drawings->no = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_south(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t SO");
	cube->drawings->so = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_east(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t EA");
	cube->drawings->ea = mlx_load_png(*tmp);
	free(*tmp);
}

void	parse_west(t_cube *cube, char **tmp, int *i)
{
	*tmp = ft_strtrim(cube->textures[*i], " \t WE");
	cube->drawings->we = mlx_load_png(*tmp);
	free(*tmp);
}
