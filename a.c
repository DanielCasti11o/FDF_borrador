/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:20:38 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/28 21:54:19 by dacastil         ###   ########.fr       */
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

void	draw(t_ejes *eje, t_coord *coord)
{
	t_vars	vars;
	int		len_x;
	int		y;
	int		x;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, EJE_X_W, EJE_X_W, "Hello world!");
	y = 0;

	printf("VALORES %d otraco %d y el otro es %d \n", eje->pos_y, eje->len_y ,(eje->len_y + POS_INIT_Y));
	while (y < eje->len_y)
	{
		x = 0;
		printf("WAITTTTTTTT\n");
		while (x < (eje->len_x[0]))
		{
			// eje->pos_x1 = round((eje->pos_x - eje->pos_y) * cos(30));
			eje->pos_x1 = eje->pos_x + 1;
			alg_bressenham(eje, vars);
			eje->pos_x1 = eje->pos_x - 1;
			// eje->pos_y1 = round((eje->pos_x + eje->pos_y) * sin(30) - eje->matx_z[y][x]);
			eje->pos_y1 = eje->pos_y + 1;
			alg_bressenham(eje, vars);
			eje->pos_y1 = eje->pos_y - 1;
			x++;
		}
		y++;
	}
	mlx_loop(vars.mlx);

}

int	slop_x(t_ejes *eje, t_bress	*bress, t_vars vars, int p)
{
	p = (bress->dif_y * 2) - bress->dif_x;
	while (eje->pos_x != eje->pos_x1)
	{
		eje->pos_x++;
		if (p > 0)
		{
			if (eje->pos_y1 > eje->pos_y)
				eje->pos_y++;
			else
				eje->pos_y--;
			p -= bress->dif_x * 2;
		}
		p += bress->dif_y * 2;
		mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
	}
	return (p);
}

int	slop_y(t_ejes *eje, t_bress	*bress, t_vars vars, int p)
{
	p = (bress->dif_x * 2) - bress->dif_y;
	while (eje->pos_y != eje->pos_y1)
	{
		if (eje->pos_y1 < eje->pos_y)
			eje->pos_y--;
		else
			eje->pos_y++;
		if (p >= 0)
		{
			if (eje->pos_x1 > eje->pos_x)
				eje->pos_x++;
			else
				eje->pos_x--;
			p -= bress->dif_y * 2;
		}
		p += bress->dif_x * 2;
		mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
	}
	return (p);
}

void	alg_bressenham(t_ejes *eje, t_vars	vars)
{
	t_bress	*bress;
	int		p;

	// cases(eje, flag);
	bress = init_bress(eje->pos_x, eje->pos_y, eje->pos_x1, eje->pos_y1);
	while (1)
	{
		mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
		if (bress->dif_x > bress->dif_y)
			p = slop_x(eje, bress, vars, p);
		else
			p = slop_y(eje, bress, vars, p);
		if (eje->pos_x == eje->pos_x1 && eje->pos_y == eje->pos_y1)
			break ;
	}
	// if (flag == 'y')
	// {
	// 	printf("entra este caso1\n");
	// 	eje->pos_y--;
	// }
	// else if ('x')
	// {
	// 	printf("entra este caso2\n");
	// 	eje->pos_x--;
	// }
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
