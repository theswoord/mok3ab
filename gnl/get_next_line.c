/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:16 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:22:43 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			readd;
	char		*join;
	static char	*chyata;

	join = ft_calloc(BUFFER_SIZE, 1);
	readd = 1;
	if (chyata)
	{
		join = ft_strjoingnl(join, chyata);
		free(chyata);
		chyata = NULL;
	}
	join = reader(fd, join, &readd);
	if (join && (pos(join, '\n') != -1))
	{
		chyata = ft_substrgnl(join, (pos(join, '\n') + 1), (pos(join, '\0')));
		join = n9esmnjoin(join);
	}
	else if (readd == 0 && ft_strlengnl(join) == 0)
	{
		free(join);
		return (NULL);
	}
	return (join);
}

char	*n9esmnjoin(char *str)
{
	char	*pointer;

	if (!str)
		return (NULL);
	pointer = ft_substrgnl(str, 0, (pos(str, '\n') + 1));
	free(str);
	return (pointer);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		kay7sb;
	int		a;
	char	*array;

	kay7sb = 0;
	a = count * size;
	array = malloc(a);
	if (!array)
		return (0);
	while (kay7sb < a)
	{
		array[kay7sb] = '\0';
		kay7sb++;
	}
	return (array);
}

char	*reader(int fd, char *join, int *readd)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while (pos(buffer, '\n') == -1 && *readd > 0)
	{
		ft_bzerognl(buffer, BUFFER_SIZE);
		*readd = read(fd, buffer, BUFFER_SIZE);
		if (*readd == -1)
		{
			free(buffer);
			free(join);
			return (NULL);
		}
		join = ft_strjoingnl(join, buffer);
	}
	free(buffer);
	return (join);
}
// int main()
// {
//     int i;
//     char* c = ft_calloc(1,1);
//     int fd = open("42_with_nl", O_RDONLY);
//     // for (i = 0; i < 15; i++)
//         printf("%s", get_next_line(fd));

//         i = read(fd, &c, 1);
//         printf("||%s||\n",c);
//         printf("%d",i);
//                 // printf("%s", get_next_line(fd));
//                 //                 printf("%s", get_next_line(fd));

// //printf("%s", get_next_line(fd));

//     //printf("%s", get_next_line(fd));
//     //printf("%s", get_next_line(fd));

//     // get_next_line(fd);
// }
