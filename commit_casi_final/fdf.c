/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:43 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 00:31:59 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**matx_to_arr(char **lines, int i, int *len)
{
	int	**matx_arr;
	int	j;

	j = 0;
	matx_arr = (int **)malloc((i + 1) * sizeof(int *));
	while (j < i)
	{
		matx_arr[j] = atoi_ptr(lines[j], len[j]);
		printf("line");
		for (int c = 0 ; c < len[j]; c++)
		{
			printf("%3d", matx_arr[j][c]);
		}
		printf("\n");
		j++;
	}
	printf("termina matrix\n");
	matx_arr[j] = NULL;
	return (matx_arr);
}

int	count_lines(int fd, char *argv)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**read_map(int fd, int i, int *len, char *argv)
{
	char	**matx;
	int		j;

	j = 0;
	printf("lslls = %d\n", len[j]);
	if (!len)
		return (free(len), NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (free(len), NULL);
	matx = malloc((i + 1) * sizeof(char *));
	if (!matx)
		return (free(len), NULL);
	printf("reservada memo doble p\n");
	while (j < i || get_next_line(fd) != NULL)
	{
		matx[j] = malloc(((len[j] + 1) * sizeof(char)));
		matx[j] = get_next_line(fd);
		if (!matx[j])
			return (fr_words(matx), NULL);
		j++;
	}
	matx[j] = NULL;
	close (fd);
	return (matx);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**lines = NULL;
	t_ejes	*eje;
	// t_coord	*coord;

	fd = 0;
	if (argc != 2)
	{
		printf("Invalid arguments\n");
		exit(1);
	}
	eje = init_ejes(fd, lines, argv[1]);
	printf("start\n");
	// int	k = 0;
	// int	p = 0;
	// int	ñ;
	// while (k < eje->len_y)
	// {
	// 	ñ = 0;
	// 	while (ñ < eje->len_x[p])
	// 	{
	// 		printf("%3d", eje->matx_z[k][ñ]);
	// 		ñ++;
	// 	}
	// 	printf("\n");
	// 	p++;
	// 	k++;
	// }

	// eje->pos_y = POS_INIT_Y * 10;
	// k = 0;
	// p = 0;
	// while (k < eje->len_y)
	// {
	// 	ñ = 0;
	// 	while (ñ < eje->len_x[p])
	// 	{
	// 		printf("(x1 %d) ", coord->x1[k][ñ]);
	// 		printf("(y1 %d) ", coord->y1[k][ñ]);
	// 		ñ++;
	// 	}
	// 	printf("\n");
	// 	p++;
	// 	k++;
	// }
	// int	i = 0;
	// int	len = eje->len_y;
	// coord = find_coord_iso(eje);
	ft_events(eje);
	printf("salee\n");
	// alg_bressenham(100, 100, 1000, 300);
	// printlines(10, 10, 1000, 500);
	// prints(eje->len_y, eje->len_x, coord);
}
