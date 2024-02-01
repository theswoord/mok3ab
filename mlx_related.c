/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:18 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:41:10 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	boundaries(t_cube *cube)
{
	cube->bound.frontx = (cube->p.x + 3 * round(cube->v3.deltax)) / MB;
	cube->bound.fronty = (cube->p.y + 3 * round(cube->v3.deltay)) / MB;
	cube->bound.backx = (cube->p.x - 3 * round(cube->v3.deltax)) / MB;
	cube->bound.backy = (cube->p.y - 3 * round(cube->v3.deltay)) / MB;
	cube->bound.righty = (cube->p.y + 3 * round(cube->v3.deltax)) / MB;
	cube->bound.rightx = (cube->p.x - 3 * round(cube->v3.deltay)) / MB;
	cube->bound.lefty = (cube->p.y - 3 * round(cube->v3.deltax)) / MB;
	cube->bound.leftx = (cube->p.x + 3 * round(cube->v3.deltay)) / MB;
}

void	pressed(void *par)
{
	t_cube	*cube;

	cube = par;
	boundaries(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
		move_forward(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_LEFT))
		turn_left(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
		move_backward(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_RIGHT))
		turn_right(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
	{
		free_all(cube);
		printf("the game exited\n");
		exit(0);
	}
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
		strife_right(cube);
	if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
		strife_left(cube);
	cast_v3(cube);
}

void	move_forward(t_cube *cube)
{
	if (cube->map[cube->bound.fronty][(int)cube->p.x / MB] != '1'
		&& cube->map[(int)cube->p.y / MB][cube->bound.frontx] != '1')
	{
		if (cube->map[cube->bound.fronty][cube->bound.frontx] != '1')
		{
			cube->p.y += round(cube->v3.deltay);
			cube->p.x += round(cube->v3.deltax);
		}
	}
}
