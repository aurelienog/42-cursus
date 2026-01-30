/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:27:07 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/30 17:01:59 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*substr(char *readed, char *line)
{
	size_t	i;
	size_t	j;
	char	*remainder;

	if (ft_strlen(readed) <= ft_strlen(line))
		return (NULL);
	remainder = malloc(ft_strlen(readed) - ft_strlen(line) + 1);
	i = ft_strlen(line);
	if (!remainder)
		return (NULL);
	j = 0;
	while(readed[i])
		remainder[j++] = readed[i++];
	remainder[j] = '\0';
	return (remainder);
}

static	*extract_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
                i++;
	if (str[i] == '\n')
	{
		line = malloc(i + 1);
		//copiar
		line[i] == '\n';
		return (line);
	}
	else
	{
		line = malloc(i);
		line[i] == '\0';
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

	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread <= 0)
		return (NULL);
	buffer[bytesread] = '\0';
	if (!readed)
		readed = ft_strcpy(buffer);
	else
		readed = ft_strjoin(readed, buffer);
	while(!ft_strrchr(readed, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			line = extract_line(readed);
			return (NULL);
		}
		buffer[bytesread] = 0;
	}
	line = extract_line(readed);
	readed = substr(readed, line);//add memory and copy what is after line	
	if (bytesread <= 0 && !readed)
		free(readed);
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

	printf("%s", last_line);
	while(last_line)
	{
		last_line = get_next_line(fd);
		printf("%s", last_line);
	}
	if (last_line)
		free(last_line);
	close(fd);
	return (0);
}
