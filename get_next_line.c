/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:23:32 by ntarik            #+#    #+#             */
/*   Updated: 2024/03/29 02:12:44 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup_until_newline(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dup = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dup[i] = '\n';
		i++;
	}
	return (dup);
}

char	*get_therest(char *str)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dup)
		return (free(str), NULL);
	i++;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	return (free(str),dup);
}

char	*get_next_line(int fd)
{
	static char	*cup;
	char		*buffer;
	int			bytes_reading;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_reading = 1;
	while (!ft_strchr(cup, '\n') && bytes_reading != 0)
	{
		bytes_reading = read(fd, buffer, BUFFER_SIZE);
		if (bytes_reading == -1)
			return ((free(cup)), (free(buffer)), NULL);
		buffer[bytes_reading] = '\0';
		cup = ft_strjoin(cup, buffer);
	}
	output = ft_strdup_until_newline(cup);
	cup = get_therest(cup);
	if (output[bytes_reading] == '\0' && bytes_reading == 0)
		return ((free(output)), (free(cup)), (free(buffer)), NULL);
	return ((free(buffer)), output);
}

// void f()
// {
// 	system("leaks a.out");
// }

// int main ()
// {
// 	int fd;
// 	char *line;
	
// 	fd = open("tst", O_RDONLY | O_CREAT , 0755);
// 	while (1) {
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
		
// }