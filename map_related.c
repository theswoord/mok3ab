/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:12 by nbouhali          #+#    #+#             */
/*   Updated: 2024/01/30 17:12:04 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	mini_map_draw_help(t_cube *cube, int *y, int *x)
{
	if (cube->map[*y][*x] == 'S')
		cube->v3.angle = P2;
	if (cube->map[*y][*x] == 'N')
		cube->v3.angle = P3;
	if (cube->map[*y][*x] == 'E')
		cube->v3.angle = 0.0;
	if (cube->map[*y][*x] == 'W')
		cube->v3.angle = M_PI;
}

void	mini_map_draw(t_cube *cube)
{
	int			x;
	int			y;
	static int	save;

	x = 0;
	y = 0;
	while (y < cube->map_stuff.lines)
	{
		while (x < cube->map_stuff.max)
		{
			if ((cube->map[y][x] == 'S' || cube->map[y][x] == 'N'
					|| cube->map[y][x] == 'E' || cube->map[y][x] == 'W')
				&& save == 0)
			{
				save = 1;
				cube->player.x = (x * MINIBLOCK) + MINIBLOCK / 2;
				cube->player.y = (y * MINIBLOCK) + MINIBLOCK / 2;
				mini_map_draw_help(cube, &y, &x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[j])
	{
		cube->map_stuff.max = fmax(cube->map_stuff.max, ft_strlengnl(cube->map[j
					+ 1]));
		j++;
	}
	cube->map_stuff.lines = j;
	while (cube->map[i])
	{
		cube->map[i] = copy_and_fill(cube->map[i], cube->map_stuff.max, ' ');
		i++;
	}
}
