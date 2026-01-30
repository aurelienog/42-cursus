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

#include "get_next_line.h"i

char	*substr(char *readed, char *line)
{
	size_t	i;
	size_t	length;
	char	*remainder;

	length = ft_strlen(line);
	remainder = malloc(length);
	if (!remainder)
		return (NULL);
	i = 0;
	while(readed[length])
		remainder[i++] = readed[length++];
	return (remainder);
}

static	*extract_line(char *str)
{
	size_t	i;
	char	*line;

	line = malloc(get_line_length(str));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		line[i] = str[i];
                i++;
	}
	if (line[i] == '\n')
	{
		line[i] == '\n';
		return (line);
	}
	else if (str[i] == '\0')
	{
		line[i] == '\0';
		return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char    *line;
	char	*buffer;
	int		bytesread;

	if (!readed)
	{
		readed = malloc();
		if (!readed)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(readed, buffer);
	}
	while(!ft_strrchr(readed, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(readed, buffer);
	}
	line = extract_line(readed);
	readed = substr(readed, line);//position at the end of line and add memory	
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
