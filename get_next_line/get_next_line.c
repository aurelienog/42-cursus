/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:27:07 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/29 18:34:15 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	i;
	int	bytesread;
	char	*buffer;
	char	*line;


	buffer = malloc(1024 + 1);
	bytesread = read(fd, buffer, 1024);
	if (bytesread <= 0)
		return (NULL);
	buffer[bytesread] = '\0';
	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
                i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	ft_putstr_fd(line, 1);
	if (i > 0 && buffer[i - 1] == '\n')
		ft_putchar_fd('\n', 1);
	free(buffer);
	return (line);
}

int	main(void)
{
	char	*last_line;
	int	fd;
	char	*buffer;

	
	fd = open("test.txt", O_RDONLY);
        if (fd == -1)
                return (0);
	last_line = get_next_line(fd);
        buffer = move_end_line(buffer, last_line);
	
	while(buffer)
	{
		last_line = get_next_line(fd);
		buffer = move_end_line(buffer, last_line);
		free(last_line);
	}
	close(fd);
	return (0);
}
