/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:56:15 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 16:26:37 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void			case1rosette(t_mlx *mlx)
{
	int			i;
	double		cursor;

	i = 0;
	while (i < RX)
	{
		cursor = ft_get_cursor(i, 0, RX);
		COLOR = ft_apply_color(COLORXY1, COLORXY2, cursor, mlx);
		image_set_pixel(mlx);
		i++;
		X1 += X_INCR;
		EX -= DY;
		if (EX < 0)
		{
			Y1 += Y_INCR;
			EX += DX;
		}
	}
	return ;
}

void			case2rosette(t_mlx *mlx)
{
	int			i;
	double		cursor;

	i = 0;
	while (i < RY)
	{
		cursor = ft_get_cursor(i, 0, RY);
		COLOR = ft_apply_color(COLORXY1, COLORXY2, cursor, mlx);
		image_set_pixel(mlx);
		i++;
		Y1 += Y_INCR;
		EY -= DX;
		if (EY < 0)
		{
			X1 += X_INCR;
			EY += DY;
		}
	}
	return ;
}

void			ft_line_tracer(t_mlx *mlx)
{
	EY = abs(Y2 - Y1);
	EX = abs(X2 - X1);
	DX = 2 * EX;
	DY = 2 * EY;
	X_INCR = 1;
	Y_INCR = 1;
	RX = EX;
	RY = EY;
	if (X1 > X2)
		X_INCR = -1;
	if (Y1 > Y2)
		Y_INCR = -1;
	if (RX > RY)
		case1rosette(mlx);
	else if (RX < RY)
		case2rosette(mlx);
	return ;
}

void			ft_tab_coord_sending(t_mlx *mlx)
{
	X_TMP = 0;
	while (X_TMP <= 1)
	{
		Y = 0;
		Y_TMP = 0;
		while (Y_TMP < Y_NB_VAL)
		{
			if (LAYER != 1)
			{
				ft_calc_coords(mlx, 1);
				ft_line_tracer(mlx);
			}
			if (LAYER != 0)
			{
				ft_calc_coords(mlx, 0);
				ft_line_tracer(mlx);
			}
			Y++;
			Y_TMP++;
		}
		X_TMP++;
		X++;
	}
	return ;
}
