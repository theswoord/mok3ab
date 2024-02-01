/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:23 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:45:28 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	found_after_space(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ') || (str[i] == '\t'))
		{
			i++;
		}
		if (str[i] == c)
		{
			return (true);
		}
		else
			return (false);
		i++;
	}
	return (false);
}

void	free_tableau(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*copy_and_fill(char *str, int count, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(count + 1, 1);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (i < count)
	{
		new[i] = c;
		i++;
	}
	free(str);
	return (new);
}

int	toupperv2(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 0;
	}
	if (c >= '0' && c <= '9')
	{
		c += 0;
	}
	return (c);
}

int	element_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}
