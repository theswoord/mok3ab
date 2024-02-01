/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:51:20 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:13:16 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	horizontal_part_one(t_cube *cube)
{
	double	tanges;

	tanges = -1 / tan(cube->v3.rayangle);
	if (cube->v3.rayangle > M_PI)
	{
		cube->v3.rayy = ((int)cube->p.y / MB * MB) - 0.0001;
		cube->v3.rayx = ((int)cube->p.y - cube->v3.rayy) * tanges
			+ (int)cube->p.x;
		cube->v3.yoffset = -MB;
		cube->v3.xoffset = -cube->v3.yoffset * tanges;
	}
	if (cube->v3.rayangle < M_PI)
	{
		cube->v3.rayy = ((int)cube->p.y / MB) * MB + MB;
		cube->v3.rayx = ((int)cube->p.y - cube->v3.rayy) * tanges
			+ (int)cube->p.x;
		cube->v3.yoffset = MB;
		cube->v3.xoffset = -cube->v3.yoffset * tanges;
	}
	if (cube->v3.rayangle == 0)
		cube->v3.xoffset = MB;
	if (cube->v3.rayangle == M_PI)
		cube->v3.xoffset = -MB;
}

void	horizontal_rays(t_cube *cube)
{
	cube->v3.hx = cube->v3.rayx;
	cube->v3.hy = cube->v3.rayy;
}

double	horizontal(t_cube *c)
{
	int	mapy;
	int	mapx;

	horizontal_part_one(c);
	while (1)
	{
		mapy = (int)c->v3.rayy / MB;
		mapx = (int)c->v3.rayx / MB;
		if ((mapy >= c->misc.lines || mapx >= c->misc.max) || (mapy <= 0
				|| mapx <= 0) || c->map[mapy][mapx] == '1')
			break ;
		else
		{
			if (c->v3.rayy < (c->misc.lines * MB) && c->v3.rayy > 0)
				c->v3.rayy += c->v3.yoffset;
			else
				return (99999889997897897);
			if (c->v3.rayx < (c->misc.max * MB) && c->v3.rayx > 0)
				c->v3.rayx += c->v3.xoffset;
			else
				return (99999988899997897);
		}
	}
	horizontal_rays(c);
	return (sqrt(pow(c->v3.hx - c->p.x, 2) + pow(c->v3.hy - c->p.y, 2)));
}

void	cast_v3(t_cube *cube)
{
	int		i;
	double	ca;

	i = 0;
	cube->v3.rayangle = cube->v3.angle - WIDTH / 2 * RAD / 30.0;
	draw_background(cube->window->img, cube);
	while (i < WIDTH)
	{
		cast_v3_help(cube);
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
		cube->v3.rayangle += RAD / 30.0;
		draw_textures(cube);
		i++;
	}
}
