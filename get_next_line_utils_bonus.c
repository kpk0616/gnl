/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:35:32 by epark             #+#    #+#             */
/*   Updated: 2022/08/03 22:28:17 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
	{
		while (*(src + i))
		{
			*(ptr + i) = *(src + i);
			i++;
		}
		*(ptr + i) = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		*(str + i++) = *s1++;
	while (*s2)
		*(str + i++) = *s2++;
	*(str + i) = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	while (*(s + i))
	{
		if (*(s + i) == ch)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
