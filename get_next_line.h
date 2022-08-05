/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:35:35 by epark             #+#    #+#             */
/*   Updated: 2022/08/04 19:22:33 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);

#endif