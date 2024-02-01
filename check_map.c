/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:33:20 by youel-id          #+#    #+#             */
/*   Updated: 2024/02/01 02:48:06 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_player(t_cube *cube)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (cube->map[i][j] == 'W' || cube->map[i][j] == 'N'
				|| cube->map[i][j] == 'E' || cube->map[i][j] == 'S')
			{
				if (count == 0)
					cube->xp = (cube->yp = i, j);
				count++;
				if (count > 1)
					return (print_error("Error\nmulti_player"), 0);
			}
		}
	}
	if (count == 0)
		return (print_error("Error\nNo PLAYER"), 0);
	return (1);
}

void	check_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'b' || str[len - 2] != 'u')
		problem("Error\nneed to use .cub \n");
	if (str[len - 3] != 'c' || str[len - 4] != '.')
		problem("Error\nneed to use .cub \n");
}

void	ft_calcule(t_cube *cube)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (cube->map[y] != NULL)
	{
		x = 0;
		while (cube->map[y][x] != '\0')
			x++;
		y++;
	}
	cube->length = y;
	cube->width = x;
}

int	check_walls(t_cube *cube)
{
	int	i;

	i = 0;
	ft_calcule(cube);
	while (i < cube->length)
	{
		if ((cube->map[i][0] != '1' && cube->map[i][0] != ' ')
			|| (cube->map[i][cube->width - 1] != '1' && cube->map[i][cube->width
				- 1] != ' '))
			return (print_error("Error\nThere is no wall\n"), 0);
		i++;
	}
	i = 0;
	while (i < cube->width)
	{
		if ((cube->map[0][i] != '1' && cube->map[0][i] != ' ')
			|| (cube->map[cube->length - 1][i] != '1' && cube->map[cube->length
				- 1][i] != ' '))
			return (print_error("Error\nThere is no wall\n"), 0);
		i++;
	}
	return (1);
}

void	map_check_help(t_cube *cube, int *i, int *j)
{
	if (cube->map[0][*j] == '0')
		problem("Error\nin map\n");
	else if (cube->map[cube->length - 1][*j] == '0')
		problem("Error\nin map\n");
	else if (cube->map[*i][*j] == '0' && ((cube->map[*i + 1][*j] == ' ')
			|| cube->map[*i + 1][*j] == '\t'))
		problem("Error\nin map\n");
	else if (cube->map[*i][*j] == '0' && ((cube->map[*i][*j + 1] == ' ')
			|| cube->map[*i][*j + 1] == '\t'))
		problem("Error\nin map\n");
	else if (cube->map[*i][*j] == '0' && ((cube->map[*i - 1][*j] == ' ')
			|| cube->map[*i - 1][*j] == '\t'))
		problem("Error\nn map\n");
	else if (cube->map[*i][*j] == '0' && ((cube->map[*i][*j - 1] == ' ')
			|| cube->map[*i][*j - 1] == '\t'))
		problem("Error\nin map\n");
}
