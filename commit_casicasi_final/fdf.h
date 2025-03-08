/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:53:02 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 14:29:40 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EJE_X_W 1800
# define EJE_Y_W 1800
# define POS_INIT_X 700
# define POS_INIT_Y 700

# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_bress
{
	float		dif_x;
	float		dif_y;
	int			m;

}				t_bress;

typedef struct s_ejes
{
	int		*len_x;
	int		len_y;
	int		**matx_z;
	int		zoom;
	int		color;
	float	pos_x1;
	float	pos_y1;
	float	pos_x;
	float	pos_y;
	void	*mlx;
	void	*win;
	int		move_y;
	int		move_x;
	int		z;
	int		z1;
	float	eje_rot_x;
	float	eje_rot_y;
}				t_ejes;

typedef struct s_coord
{
	int	**x1;
	int	**y1;
}				t_coord;

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

int		ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		count_lines(int fd, char *argv);
char	**read_map(int fd, int i, int *len, char *argv);
int		**matx_to_arr(char **lines, int i, int *len);
int		*lengs(int i, int fd, char *argv);
void	fr_words(char **wds);
int		ft_atoi(const char *nptr);
int		*atoi_ptr(char *str, int len);
int		count_spaces(char *line);
int		*rest_len(int *len, char **lines);
int		ft_countsubstr(const char*s, char c);
char	**ft_split(char const *s, char c);
void	prints(int i, int *len, t_coord *coord);
int		*ft_intchr(int *s, int c);
t_ejes	*init_ejes(int fd, char **lines, char *argv);
t_coord	*find_coord_iso(t_ejes *eje);
t_coord	*init_coord(t_ejes *eje);
void	printlines(int x, int y, int x1, int y1);
void	alg_bressenham(t_ejes *eje);
void	slopes(t_ejes *eje, int x, int y);
t_bress	*init_bress(int x, int y, float x1, float y1);
void	ft_isometric(t_ejes *eje, int z, int z1);
int		Vabs(int n);
int		max(int difx, int dify);
void	draw(t_ejes *eje);
void	ft_events(t_ejes *eje);
int		ft_keys(int keycode, t_ejes *eje);
void	ft_rot(int keycode, t_ejes *eje);

#endif
