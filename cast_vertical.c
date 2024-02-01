/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:50:43 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:57:23 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	vertical_part_one(t_cube *cube)
{
	double	tanges;

	tanges = -tan(cube->v3.rayangle);
	if (cube->v3.rayangle > M_PI / 2 && cube->v3.rayangle < 3 * M_PI / 2)
	{
		cube->v3.rayx = ((int)cube->p.x / MB) * MB - 0.0001;
		cube->v3.rayy = ((int)cube->p.x - cube->v3.rayx) * tanges
			+ (int)cube->p.y;
		cube->v3.xoffset = -MB;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle < M_PI / 2 || cube->v3.rayangle > 3 * M_PI / 2)
	{
		cube->v3.rayx = ((int)cube->p.x / MB * MB) + MB;
		cube->v3.rayy = ((int)cube->p.x - cube->v3.rayx) * tanges
			+ (int)cube->p.y;
		cube->v3.xoffset = MB;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle == M_PI / 2)
		cube->v3.yoffset = MB;
	if (cube->v3.rayangle == 3 * M_PI / 2)
		cube->v3.yoffset = -MB;
}

void	vertical_rays(t_cube *cube)
{
	cube->v3.Vx = cube->v3.rayx;
	cube->v3.Vy = cube->v3.rayy;
}

double	vertical(t_cube *c)
{
	int	mapy;
	int	mapx;

	vertical_part_one(c);
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
				return (99999889789997897);
		}
	}
	vertical_rays(c);
	return (sqrt(pow(c->v3.Vx - c->p.x, 2) + pow(c->v3.Vy - c->p.y, 2)));
}

void	cast_v3_help(t_cube *cube)
{
	double	dh;
	double	dv;

	if (cube->v3.rayangle <= 0)
		cube->v3.rayangle += 2 * M_PI;
	if (cube->v3.rayangle >= 2 * M_PI)
		cube->v3.rayangle -= 2 * M_PI;
	dh = horizontal(cube);
	dv = vertical(cube);
	cube->v3.wallheight = (HEIGHT * MB) / cube->v3.distance;
	cube->v3.savewallheight = cube->v3.wallheight;
	if (cube->v3.wallheight > HEIGHT)
		cube->v3.wallheight = HEIGHT;
	if (dh < dv)
	{
		cube->v3.distance = dh;
		cube->v3.side = 0;
	}
	else
	{
		cube->v3.distance = dv;
		cube->v3.side = 1;
	}
}

void	draw_textures(t_cube *cube)
{
	if (cube->v3.side == PH)
	{
		if (cube->v3.rayangle < M_PI)
			textured_inverted(cube, cube->colors->SO, cube->v3.side,
				height_extract(cube, "SO"));
		else
			textured(cube, cube->colors->NO, cube->v3.side, height_extract(cube,
					"NO"));
	}
	else
	{
		if (cube->v3.rayangle > 3 * M_PI / 2 || cube->v3.rayangle < M_PI / 2)
			textured(cube, cube->colors->EA, cube->v3.side, height_extract(cube,
					"EA"));
		else
			textured_inverted(cube, cube->colors->WE, cube->v3.side,
				height_extract(cube, "WE"));
	}
}
