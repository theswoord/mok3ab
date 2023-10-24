/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali <nbouhali@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:51:56 by nbouhali          #+#    #+#             */
/*   Updated: 2023/02/07 22:35:03 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*mbdla;

	a = 0;
	mbdla = (char *)s;
	while (a <= ft_strlen(mbdla))
	{
		if (mbdla[a] == (char)c)
		{
			return (mbdla + a);
		}
		a++;
	}
	return (0);
}
