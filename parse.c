/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:20 by nbouhali          #+#    #+#             */
/*   Updated: 2024/01/30 13:39:30 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_textures(t_cube *cube)
{
	int		what;
	int		i;
	char	*tmp;

	what = 0;
	i = 0;
	tmp = NULL;
	while (cube->textures[i])
	{
		if (ft_strnstr(cube->textures[i]
				+ return_after_space(cube->textures[i]), "NO .", 4))
		{
			tmp = ft_strtrim(cube->textures[i], " \t NO");
			cube->drawings->NO = mlx_load_png(tmp);
			free(tmp);
		}
		else if (ft_strnstr(cube->textures[i]
				+ return_after_space(cube->textures[i]), "SO .", 4))
		{
			what = SO;
			tmp = ft_strtrim(cube->textures[i], " \t SO");
			cube->drawings->SO = mlx_load_png(tmp);
			free(tmp);
		}
		else if (ft_strnstr(cube->textures[i]
				+ return_after_space(cube->textures[i]), "EA .", 4))
		{
			what = EA;
			tmp = ft_strtrim(cube->textures[i], " \t EA");
			cube->drawings->EA = mlx_load_png(tmp);
			free(tmp);
		}
		else if (ft_strnstr(cube->textures[i]
				+ return_after_space(cube->textures[i]), "WE .", 4))
		{
			what = WE;
			tmp = ft_strtrim(cube->textures[i], " \t WE");
			cube->drawings->WE = mlx_load_png(tmp);
			free(tmp);
		}
		else
			problem("Error\nTexture parse\n");
		i++;
	}
	free_tableau(cube->textures);
}

int	return_after_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}
