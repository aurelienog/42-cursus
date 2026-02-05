/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:27:07 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/05 14:47:36 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*newsubstr(char *readed, char *line)
{
	size_t	start;
	size_t	length;
	char	*remainder;

	if (!readed)
		return (NULL);
	start = ft_strlen(line);
	length = ft_strlen(readed) - start;
	if (length == 0)
	{
		free(readed);
		return (NULL);
	}
	remainder = ft_substr(readed, start, length);
	free(readed);
	return (remainder);
}

static char	*extract_line(char *str)
{
	size_t	i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytesread;

	if (!readed)
		readed = ft_strdup("");
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		readed = newstrjoin(readed, buffer);
	}
	while (!ft_strchr((const char *)readed, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			break ;
		buffer[bytesread] = '\0';
		readed = newstrjoin(readed, buffer);
	}
	if (bytesread <= 0 && readed && *readed == '\0')
	{
		free(readed);
		readed = NULL;
		return (NULL);
	}
	line = extract_line(readed);
	readed = newsubstr(readed, line);
	return (line);
}
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*last_line;
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
        if (fd == -1)
                return (0);
	last_line = get_next_line(fd);
	printf("%s", last_line);
	if (!last_line)
	{
		return (0);
	}
	while(last_line)
	{
		free(last_line);
		last_line = get_next_line(fd);
		printf("%s", last_line);
	}
	close(fd);
	return (0);
}
