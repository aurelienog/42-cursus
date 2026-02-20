/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:20:53 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/20 14:31:07 by aunoguei         ###   ########.fr       */
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
			return (free(readed), free(buffer), NULL);
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
	if (!readed[fd])
		return (NULL);
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
/*
#include <stdio.h>
#include <fcntl.h>

int     main(void)
{
        char    *last_line;
        int     fd;
        int     fd2;

        fd = open("test.txt", O_RDONLY);
        if (fd == -1)
                return (0);
        fd2 = open("test2.txt", O_RDONLY);
        if (fd == -1)
                return (0);
//      fd = 0;
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
        //segundo
        last_line = get_next_line(fd2);
        if (!last_line)
        {
                return (0);
        }
        while(last_line)
        {
                printf("%s", last_line);
                free(last_line);
                last_line = get_next_line(fd2);
        }
        close(fd);
        close(fd2);
        return (0);
}
*/
/*
#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	char	*str;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (1);
		str = get_next_line(fd);
		printf("%s", str);
		while (str)
		{
			str = get_next_line(fd);
			if (str)
				printf("%s", str);
		}
		free(str);
		close(fd);
		i++;
	}
	return (0);
}*/
