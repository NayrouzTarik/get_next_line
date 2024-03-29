/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:43:34 by ntarik            #+#    #+#             */
/*   Updated: 2024/03/29 02:18:23 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup_until_newline(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
char	*get_therest(char *str);
#endif