/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:35:30 by epark             #+#    #+#             */
/*   Updated: 2022/08/03 22:25:58 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(int fd, char *buffer, char *save)
{
	int		count;
	char	*temp_pointer;

	count = 1;
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		temp_pointer = save;
		save = ft_strjoin(temp_pointer, buffer);
		if (save == NULL)
			return (NULL);
		free(temp_pointer);
		temp_pointer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

static char	*ft_extract(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_strdup(&line[i + 1]);
	if (result == NULL)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = ft_read_line(fd, buffer, save[fd]);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = ft_extract(line);
	return (line);
}
