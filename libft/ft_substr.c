/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali <nbouhali@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:52:29 by nbouhali          #+#    #+#             */
/*   Updated: 2023/02/06 22:22:34 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			b;
	char			*subs;
	unsigned int	test;

	if (!s)
	{
		return (0);
	}
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	b = 0;
	test = ft_strlen(s);
	subs = malloc(len * sizeof(char) + 1);
	if (!subs)
		return (0);
	while (b < len && test >= start)
	{
		subs[b] = s[start];
		b++;
		start++;
	}
	subs[b] = '\0';
	return (subs);
}
