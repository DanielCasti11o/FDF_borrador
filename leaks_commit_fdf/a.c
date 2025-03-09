/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:20:38 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 14:42:46 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// void	cases(t_ejes *eje, char flag)
// {
// 	if (flag == 'x')
// 	{
// 		eje->pos_x++;
// 	}
// 	else if (flag == 'y')
// 	{
// 		eje->pos_y++;
// 	}
// }

void	draw(t_ejes *eje)
{
	int		y;
	int		x;

	y = 0;
	eje->pos_y = 0;
	// printf("VALORES %d otraco %d y el otro es %d \n", eje->pos_y, eje->len_y ,(eje->len_y + POS_INIT_Y));
	while (y < eje->len_y)
	{
		x = 0;
		eje->pos_x = 0;
		// printf("WAITTTTTTTT\n");
		while (x < (eje->len_x[0]))
		{
			slopes(eje, x, y);
			x++;
			eje->pos_x++;
		}
		eje->pos_y++;
		y++;
	}
	// printf("sarhdle\n");
}

void	slopes(t_ejes *eje, int x, int y)
{
	eje->pos_y1 = eje->pos_y;
	if (x < eje->len_x[0] - 1)
	{
		eje->pos_x1 = eje->pos_x + 1;
		alg_bressenham(eje);
	}
	eje->pos_x1 = eje->pos_x;
	if (y < eje->len_y - 1)
	{
		eje->pos_y1 = eje->pos_y + 1;
		alg_bressenham(eje);
	}
}

void	alg_bressenham(t_ejes *eje)
{
	t_bress	*bress;
	float	temp;
	float	temp2;

	temp = eje->pos_x;
	temp2 = eje->pos_y;
	eje->z = eje->matx_z[(int)eje->pos_y][(int)eje->pos_x];
	eje->z1 = eje->matx_z[(int)eje->pos_y1][(int)eje->pos_x1];
	eje->pos_x *= eje->zoom;
	eje->pos_y *= eje->zoom;
	eje->pos_x1 *= eje->zoom;
	eje->pos_y1 *= eje->zoom;
	ft_isometric(eje, eje->z, eje->z1);
	eje->pos_x += POS_INIT_X + eje->move_x;
	eje->pos_y += POS_INIT_Y + eje->move_y;
	eje->pos_x1 += POS_INIT_X + eje->move_x;
	eje->pos_y1 += POS_INIT_Y + eje->move_y;
	bress = init_bress(eje->pos_x, eje->pos_y, eje->pos_x1, eje->pos_y1);
			if (eje->z > 0 || eje->z1 > 0)
			{
				eje->color -= 0x11;
			}
		else
			eje->color = 0xFFFFFF;
	while ((int)(eje->pos_x - eje->pos_x1) || (int)(eje->pos_y - eje->pos_y1))
	{
		if ((bress->dif_x > 0 && (int)(eje->pos_x - eje->pos_x1) > 0) ||
			(bress->dif_x < 0 && (int)(eje->pos_x - eje->pos_x1) < 0) ||
			(bress->dif_y > 0 && (int)(eje->pos_y - eje->pos_y1) > 0) ||
			(bress->dif_y < 0 && (int)(eje->pos_y - eje->pos_y1) < 0))
			{
				printf("ayayay\n");
				break ;
			}
		if (eje->pos_x >= 0 || eje->pos_y >= 0 || eje->pos_x <= EJE_X_W || eje->pos_y <= EJE_Y_W)
			mlx_pixel_put(eje->mlx, eje->win, eje->pos_x, eje->pos_y, eje->color);
		eje->pos_x += bress->dif_x;
		eje->pos_y += bress->dif_y;
	}
	eje->pos_x = temp;
	eje->pos_y = temp2;
}

// void	key_hook(int keycode, t_vars vars)
// {

// }

// void	prints(int i, int *len, t_coord *coord)
// {
// 	t_vars	vars;
// 	t_ejes	eje;
// 	int		pix;
// 	int		x;
// 	int		y;
// 	int		aux;
// 	int		pt = 0;
// 	int		pt_peq = 0;
// 	int		ref;

// 	x = 100;
// 	pix = 0;
// 	ref = 0;
// 	y = 500;
// 	aux = 0;
// 	i += 500;
// 	len[aux] += 100;
// 	printf("lenen0 = %d\n", len[aux]);
// 	printf ("ostras = %d\n", i);
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 2000, 1000, "Hello world!");
// 	while (ref < len[aux])
// 	{
// 		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
// 		mlx_pixel_put(vars.mlx, vars.win, (coord->eje->pos_y1[pt][pt_peq] + x), (y), 0xFFFFFF);
// 		x++;
// 		while (pix != 15)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
// 			mlx_pixel_put(vars.mlx, vars.win, x, (coord->eje->pos_y1[pt][pt_peq] + y), 0xFFFFFF);
// 			y++;
// 			pix++;
// 			pt_peq++;
// 		}
// 		pt_peq = 0;
// 		y -= 15;
// 		pix = 0;
// 		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
// 		mlx_pixel_put(vars.mlx, vars.win, (coord->eje->pos_y1[pt][pt_peq] + x), (y), 0xFFFFFF);
// 		x++;
// 		ref++;
// 		while (pix != 15)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
// 			x++;
// 			pix++;
// 		}
// 		pix = 0;
// 		if (ref == (len[aux] - 100))
// 		{
// 			printf("aguacate\n");
// 			y++;
// 			pt++;
// 			if (y == i)
// 				break ;
// 			ref = 0;
// 			aux++;
// 			len[aux] += 100;
// 			x = 100;
// 		}
// 		if (y == i)
// 			break ;
// 	}
// 	mlx_loop(vars.mlx);
// }












// mlx_key_hook(vars.win, key_hook, &vars);
	// while (len[aux])
	// {
	// 	y = 100;
	// while (y < i)
	// {
	// 	mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
	// 	y++;
	// }
	// x = 20;
	// while (x < len[aux])
	// {
	// 		// len[aux] += 100;
	// 	mlx_pixel_put(vars.mlx, vars.win, x, y, 0x00FF00);
	// 	x++;
	// }
	// 	aux ++;
	// 	len[aux] += 100;
	// 	// mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
	// 	// y += 10;
	// }
