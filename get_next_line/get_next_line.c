/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:27:07 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/09 09:59:51 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readed)
		readed = ft_strdup("");
	readed = read_and_join(fd, readed);
	if (!readed)
		return (NULL);
	if (*readed == '\0')
	{
		free(readed);
		readed = NULL;
		return (NULL);
	}
	line = extract_line(readed);
	readed = newsubstr(readed);
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
	if (!last_line)
	{
		return (0);
	}
	while(last_line)
	{
		printf("%s", last_line);
		free(last_line);
		last_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
