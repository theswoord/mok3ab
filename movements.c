/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:33:32 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:50:16 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	turn_left(t_cube *cube)
{
	cube->v3.angle -= ROTSPEED;
	if (cube->v3.angle < 0)
	{
		cube->v3.angle += 2 * M_PI;
	}
	cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	cube->v3.deltay = sin(cube->v3.angle) * SPEED;
}

void	move_backward(t_cube *cube)
{
	if (cube->map[cube->bound.backy][(int)cube->p.x / MB] != '1'
		&& cube->map[(int)cube->p.y / MB][cube->bound.backx] != '1')
	{
		if (cube->map[cube->bound.backy][cube->bound.backx] != '1')
		{
			cube->p.y -= round(cube->v3.deltay);
			cube->p.x -= round(cube->v3.deltax);
		}
	}
}

void	strife_left(t_cube *cube)
{
	if (cube->map[cube->bound.lefty][(int)cube->p.x / MB] != '1'
		&& cube->map[(int)cube->p.y / MB][cube->bound.leftx] != '1')
	{
		if (cube->map[cube->bound.lefty][cube->bound.leftx] != '1')
		{
			cube->p.x += round(cube->v3.deltay);
			cube->p.y -= round(cube->v3.deltax);
		}
	}
}

void	strife_right(t_cube *cube)
{
	if (cube->map[cube->bound.righty][(int)cube->p.x / MB] != '1'
		&& cube->map[(int)cube->p.y / MB][cube->bound.rightx] != '1')
	{
		if (cube->map[cube->bound.righty][cube->bound.rightx] != '1')
		{
			cube->p.x -= round(cube->v3.deltay);
			cube->p.y += round(cube->v3.deltax);
		}
	}
}

void	turn_right(t_cube *cube)
{
	cube->v3.angle += ROTSPEED;
	if (cube->v3.angle >= 2 * M_PI)
	{
		cube->v3.angle -= 2 * M_PI;
	}
	cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	cube->v3.deltay = sin(cube->v3.angle) * SPEED;
}
