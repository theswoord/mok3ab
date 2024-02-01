/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:48:36 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:48:52 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_check(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	ft_calcule(cube);
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			map_check_help(cube, &i, &j);
		}
	}
}

void	check_ft(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (ft_strchr(cube->wanted, (toupperv2(cube->map[i][j]))) == 0)
			{
				problem("Error\nin alpha\n");
			}
		}
	}
}
