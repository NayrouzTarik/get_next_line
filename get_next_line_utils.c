/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:45:16 by ntarik            #+#    #+#             */
/*   Updated: 2024/03/29 01:58:46 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	of;
	char	*pointer;

	of = count * size;
	if (of != 0 && (of / count) != size)
		return (NULL);
	pointer = malloc(of);
	if (pointer != NULL)
		ft_bzero(pointer, of);
	return (pointer);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	if (n == 0)
		return ;
	i = 0;
	str = (char *)s;
	while (i < n)
		str[i++] = 0;
	return ;
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str1 == NULL)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	return (str);
}
// char	*end_of_file(char **cup, char **buffer, char **output)
// {
// 	free(cup);
// 	free(buffer);
// 	free(output);
// 	return (NULL);
// }