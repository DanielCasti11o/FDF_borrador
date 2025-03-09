/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:35:54 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/09 22:16:18 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fr_words(char **wds)
{
	int	i;

	i = 0;
	while (wds[i])
	{
		free(wds[i]);
		i++;
	}
	free(wds);
}

int	count_spaces(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	*atoi_ptr(char *str, int len)
{
	int		i;
	int		*new_ptr;
	char	**wd;

	i = 0;
	new_ptr = malloc((len) * sizeof(int));
	if (!new_ptr)
		return (NULL);
	wd = ft_split(str, ' ');
	if (!wd)
		return (NULL);
	while (wd[i] != NULL)
	{
		// printf("str %s\n", wd[i]);
		new_ptr[i] = ft_atoi(wd[i]);
		// printf("new %d ", new_ptr[i]);
		i++;
	}
	// printf("\n");
	new_ptr[i] = '\0';
	fr_words(wd);
	// printf("numEE %d\n", new_ptr[i]);
	return (new_ptr);
}


int	*lengs(int i, int fd, char *argv, t_ejes *eje)
{
	int		*len;
	int		j;
	char	*str;

	j = 0;
	len = malloc((i + 1) * sizeof(int));
	if (!len)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd);
	// if (!str)
	// {
	// 	return (free(str), free(len), close(fd), NULL);
	// }
	len[j] = ft_strlen(str) - 1;
	printf("longi 1-> %d\n", len[j]);
	j++;
	while (str != NULL)
	{
		len[j] = ft_strlen(str) - 1;
		free(str);
		str = get_next_line(fd);
		printf("longi %d\n", len[j]);
		j++;
	}
	len[j] = 0;
	free(str);
	j = 0;
	printf("i ==== %d\n", i);
	while (j < (i + 1))
	{
		printf("longi0 %d longcompa %d \n", len[0], len[j]);
		if (len[0] != len[j])
		{
			free(len);
			free(eje);
			// fr_struct(eje);
			close(fd);
			ft_error("ERROR: Invalid map\n", 1);
		}
		j++;
	}
	return (close(fd), len);
}

int	*rest_len(int *len, char **lines)
{
	int	i;
	int	*res;

	i = 0;
	res = len;
	while (lines[i])
	{
		res[i] = ft_countsubstr(lines[i], ' ');
		i++;
	}
	return (res);
}
