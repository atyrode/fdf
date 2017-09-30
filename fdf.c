/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 17:16:57 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 16:27:30 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	key_test(int keycode, t_mlx *mlx)
{
		if (keycode == 126 || keycode == 125)
	{
		if (O == 1)
			T_HEIGHT = (keycode == 126) ? T_HEIGHT + 2 : T_HEIGHT - 2;
		else
			SHIFT_Y = (keycode == 126) ? SHIFT_Y - ZOOM : SHIFT_Y + ZOOM;
	}
	if (keycode == 124 || keycode == 123)
	{
		if (O == 1)
			T_WIDTH = (keycode == 123) ? T_WIDTH + 2 : T_WIDTH - 2;
		else
			SHIFT_X = (keycode == 123) ? SHIFT_X - ZOOM : SHIFT_X + ZOOM;
	}
	if (keycode == 69 || keycode == 78)
	{
		ZOOM = (keycode == 69) ? ZOOM + 5 : ZOOM - 5;
		SHIFT_X = (keycode == 69) ? SHIFT_X - ZOOM : SHIFT_X + ZOOM;
	}
	return ;
}

int		key_func(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123
			|| keycode == 69 || keycode == 78)
		key_test(keycode, mlx);
	if (keycode == 1)
		SPIN = (SPIN + 1 <= 4) ? SPIN + 1 : 1;
	if (keycode == 4)
		H = (H == 0) ? 1 : 0;
	if (keycode == 49)
		LAYER = (LAYER == 0) ? 2 : LAYER - 1;
	if (keycode == 116 || keycode == 121)
		Z_SIZE = (keycode == 116) ? Z_SIZE + 1 : Z_SIZE - 1;
	if (keycode == 31)
		O = (O == 0) ? 1 : 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	new_image(mlx);
	two_per_two(ARGV1, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	return (0);
}

int		*coords_spin(t_mlx *mlx, int *coords, int spv, int psv)
{
	if (SPIN == 3)
	{
		coords[A] = ((((Y + J) + (X + I)) * ((T_WIDTH + ZOOM)/ 2)) +
				((W_WIDTH * 13) / 32) + SHIFT_X);
		coords[A + 1] = ((((X + I) - (Y + J)) * ((T_HEIGHT + ZOOM) / 2)) +
				((W_HEIGHT * 8) / 16) - ((ft_getnbr(Z)) * Z_SIZE) + SHIFT_Y);
	}
	else if (SPIN == 4 || SPIN == 2)
	{
		coords[A] = (((spv * ((Y + J) - (X + I))) * ((T_WIDTH + ZOOM)/ 2))
				+ ((W_WIDTH * (16 - psv)) / 32) + SHIFT_X);
		coords[A + 1] = (((spv * ((X + I) + (Y + J))) * ((T_HEIGHT + ZOOM)
						/ 2)) + ((W_HEIGHT * (10 - 2 * psv)) / 16) -
				((ft_getnbr(Z)) * Z_SIZE) + SHIFT_Y);
	}
	else if (SPIN == 1)
	{
		coords[A] = (((-1 * ((Y + J) + (X + I))) * ((T_WIDTH + ZOOM)/ 2)) +
				((W_WIDTH * 22) / 32) + SHIFT_X);
		coords[A + 1] = (((((Y + J) - (X + I))) * ((T_HEIGHT + ZOOM) / 2)) +
				((W_HEIGHT * 6) / 16) - ((ft_getnbr(Z)) * Z_SIZE) + SHIFT_Y);
	}
	return (coords);
}

void	calc_loop(t_mlx *mlx, int *coords, int spv, int psv)
{
	if (A == 2)
	{
		if (B == 0)
			J = (Y_TMP == (Y_NB_VAL - 1)) ? 0 : 1;
		if (B == 1)
			I = (X_TMP > 0) ? 0 : 1;
		COLORXY2 = Z;
	}
	else
		COLORXY1 = Z;
	coords = coords_spin(mlx, coords, spv, psv);
	A += 2;
	return ;
}

void	ft_calc_coords(t_mlx *mlx, int b)
{
	int		*coords;
	int		spv;
	int		psv;

	J = 0;
	I = 0;
	A = 0;
	B = b;
	spv = 0;
	psv = 0;
	if (SPIN == 2 || SPIN == 4)
	{
		spv = (SPIN == 2) ? 1 : -1;
		psv = (SPIN == 2) ? 3 : 0;
	}
	if (!(coords = malloc(sizeof(int) * 4)))
		exit(-1);
	while (A <= 2)
		calc_loop(mlx, coords, spv, psv);
	X1 = coords[0];
	Y1 = coords[1];
	X2 = coords[2];
	Y2 = coords[3];
	free(coords);
	return ;
}
