/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:04 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:09:05 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_textures(t_cube *cube)
{
	free(cube->colors->no);
	free(cube->colors->so);
	free(cube->colors->ea);
	free(cube->colors->we);
}

void	img_destroy(t_cube *cube)
{
	mlx_delete_image(cube->window->mlx, cube->window->img);
	mlx_close_window(cube->window->mlx);
}

void	free_stucts(t_cube *cube)
{
	free_tableau(cube->map);
	free(cube->window);
	free(cube->drawings);
	free(cube->colors);
	free(cube);
}

void	free_all(t_cube *cube)
{
	free_textures(cube);
	img_destroy(cube);
	free_stucts(cube);
}
