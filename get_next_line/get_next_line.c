/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:27:07 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/02 14:51:41 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*newsubstr(char *readed, char *line)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*remainder;

	if (!readed)
		return (NULL);
	length = ft_strlen(readed) - ft_strlen(line);
	if (length == 0)
	{
		free(readed);
		return (NULL);
	}
	remainder = malloc((length + 1) * sizeof(char));
	if (!remainder)
	{
		free(readed);
		return (NULL);
	}
	i = ft_strlen(line);
	j = 0;
	while(readed[i])
		remainder[j++] = readed[i++];
	remainder[j] = '\0';
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
		line = malloc((i + 1) * sizeof(char));
	else
		line = malloc(i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
		return (line);
	}
	else
	{
		line[i] = '\0';
		return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char    *line;
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread;

	line = extract_line(readed);
	if (!line)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			return (NULL);
		buffer[bytesread] = '\0';
		readed = newstrjoin(readed, line);
	}
	while(!ft_strchr((const char *)readed, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			break;
		buffer[bytesread] = '\0';
		readed = newstrjoin(readed, buffer);
	}
	line = extract_line(readed);
	readed = newsubstr(readed, line);
	return (line);
}
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char	*last_line;
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
        if (fd == -1)
                return (0);

	last_line = get_next_line(fd);
	printf("%s", last_line);
	free(last_line);

	while(last_line)
	{
		last_line = get_next_line(fd);
		printf("%s", last_line);
		 free(last_line);

	}
	close(fd);
	return (0);
}
