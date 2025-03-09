/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:51:20 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/09 21:36:27 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_events(t_ejes *eje)
{
	eje->mlx = mlx_init();
	eje->win = mlx_new_window(eje->mlx, EJE_X_W, EJE_X_W, "Hello world!");
	draw(eje);
	mlx_key_hook(eje->win, ft_keys, eje);
	mlx_loop(eje->mlx);
}

int	ft_keys(int keycode, t_ejes *eje)
{
	if (keycode == 65307)
	{
		free(eje->len_x);
		fr_ints(eje->matx_z, eje);
		exit(1);
		mlx_destroy_window((void *)eje->win, (void *)eje->win);
	}
	if ((keycode == 65362 || keycode == 119))
		eje->move_y -= 10;
	if (keycode == 65364 || keycode == 115)
		eje->move_y += 10;
	if (keycode == 65361 || keycode == 97)
		eje->move_x -= 10;
	if (keycode == 65363 || keycode == 100)
		eje->move_x += 10;
	if (keycode == 122 && eje->zoom < 100)
		eje->zoom += 10;
	if (keycode == 108 && eje->zoom - 10 >= 0)
		eje->zoom -= 10;
	ft_rot(keycode, eje);
	mlx_clear_window(eje->mlx, eje->win);
	draw(eje);
	return (0);
}

void	ft_rot(int keycode, t_ejes *eje)
{
	if (keycode == 114 && eje->eje_rot_y > 0)
		eje->eje_rot_y += 0.1;
	if (keycode == 111)
		eje->eje_rot_x += 0.1;
}
