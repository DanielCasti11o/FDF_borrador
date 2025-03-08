/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:51:20 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 14:40:48 by dacastil         ###   ########.fr       */
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
		exit(0);
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
	{
		eje->eje_rot_y += 0.7;
		if (eje->eje_rot_y >= 3 && eje->eje_rot_y < 4)
			eje->eje_rot_y += 1.5;
		else if (eje->eje_rot_y < 6)
			eje->eje_rot_y += 0.9;
		else if (eje->eje_rot_y > 6)
			eje->eje_rot_y = 1;
	}
	if (keycode == 111)
	{
		eje->eje_rot_x += 0.9;
		if (eje->eje_rot_x >= 3 && eje->eje_rot_x < 4)
			eje->eje_rot_x += 0.6;
		else if (eje->eje_rot_x < 8)
			eje->eje_rot_x += 0.4;
		else if (eje->eje_rot_x > 9)
			eje->eje_rot_x = 1;
	}
}
