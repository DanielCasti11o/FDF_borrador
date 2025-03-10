/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:35:06 by dacastil          #+#    #+#             */
/*   Updated: 2024/11/11 18:30:37 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	if (!temp)
		return (NULL);
	free (buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	next = ft_calloc(((ft_strlen(buffer) - i) + 1), sizeof (char));
	if (!next)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
	{
		next[j] = buffer[i];
		i++;
		j++;
	}
	free (buffer);
	return (next);
}

char	*obt_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i] = '\n';
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	int		bytes_read;
	char	*buff_temp;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	buff_temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff_temp)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff_temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buff_temp);
			free (buffer);
			return (NULL);
		}
		buff_temp[bytes_read] = '\0';
		buffer = free_join(buffer, buff_temp);
		if (ft_strchr(buff_temp, '\n'))
			break ;
	}
	free (buff_temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	if (ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = obt_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

/*
int main ()
{
	char *ptr;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((ptr = get_next_line(-1)))
	{
		printf("%s", ptr);
		free (ptr);
	}
	ptr = get_next_line(-1);
	printf("%s", ptr);
	free (ptr);
    close(fd);
	return 0;
}
*/
