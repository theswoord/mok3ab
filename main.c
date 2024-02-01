/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:06 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:51:30 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_functions(int fd, t_cube *cube)
{
	cube->wanted = "01EWSN ";
	read_map(fd, cube);
	check_ft(cube);
	parse(cube);
	parse_textures(cube);
	if (!cube->drawings->NO || !cube->drawings->EA || !cube->drawings->WE
		|| !cube->drawings->SO)
		problem("Error\ncheck the PNG or read ^above^ \n");
	texture_set(cube);
	init_mlx(cube);
	fill_map(cube);
	map_check(cube);
	if (!check_player(cube) || !check_walls(cube))
		exit(1);
	draw_background(cube->window->img, cube);
	mini_map_draw(cube);
}

int	main(int ac, char **av)
{
	int		fd;
	t_cube	*cube;

	if (ac != 2)
	{
		print_error("Error\nmore or less than 2 ac\n");
		return (0);
	}
	check_cub(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	cube = (t_cube *)malloc(sizeof(t_cube));
	ft_memset(cube, 0, sizeof(t_cube));
	struct_init(cube);
	parse_functions(fd, cube);
	cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	cube->v3.deltay = sin(cube->v3.angle) * SPEED;
	mlx_loop_hook(cube->window->mlx, &pressed, cube);
	mlx_loop(cube->window->mlx);
	mlx_terminate(cube->window->mlx);
	return (0);
}

void	set_background(t_cube *cube)
{
	cube->colors->finalfloor = (cube->colors->F[0] << 24)
		| (cube->colors->F[1] << 16)
		| (cube->colors->F[2] << 8)
		| 0xFF;
	cube->colors->finalceil = (cube->colors->C[0] << 24)
		| (cube->colors->C[1] << 16)
		| (cube->colors->C[2] << 8)
		| 0xFF;
}
