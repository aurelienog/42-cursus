/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:20:53 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/09 18:24:30 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*newsubstr(char *readed)
{
	size_t	i;
	char	*remainder;

	if (!readed)
		return (NULL);
	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (readed[i] == '\n')
		i++;
	if (readed[i] == '\0')
	{
		free(readed);
		return (NULL);
	}
	remainder = ft_strdup(readed + i);
	free(readed);
	return (remainder);
}

char	*extract_line(char *str)
{
	size_t	i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_and_join(int fd, char *readed)
{
	char		*buffer;
	int			bytesread;
	char		*temp;

	bytesread = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(readed), NULL);
	while ((readed &&!ft_strchr(readed, '\n')) && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(readed), free(buffer), NULL);
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		temp = newstrjoin(readed, buffer);
		if (!temp)
			return (free(buffer), NULL);
		readed = temp;
	}
	free(buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!readed[fd])
		readed[fd] = ft_strdup("");
	readed[fd] = read_and_join(fd, readed[fd]);
	if (!readed[fd])
		return (NULL);
	if (*readed[fd] == '\0')
	{
		free(readed[fd]);
		readed[fd] = NULL;
		return (NULL);
	}
	line = extract_line(readed[fd]);
	readed[fd] = newsubstr(readed[fd]);
	return (line);
}
//main
