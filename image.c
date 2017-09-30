/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:41:05 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 16:27:00 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int			ft_high_color(char *str)
{
	int		high;

	high = ft_getnbr(str);
	if (high < -6)
		return (0x8C0000);
	if (high >= -6 && high < -4)
		return (0xFE0303);
	if (high >= -4 && high < -2)
		return (0xF60062);
	if (high < 0 && high >= -2)
		return (0xED00FE);
	if (high <= 2)
		return (0x4400FE);
	if (high <= 4)
		return (0x00B2FE);
	if (high <= 6)
		return (0x04E5BF);
	if (high <= 8)
		return (0x04E556);
	if (high > 8)
		return (0xFFFFFF);
	return (-1);
}

int			ft_apply_color(char *str1, char *str2, double cursor, t_mlx *mlx)
{
	int		color1;
	int		color2;
	int		color_result;

	if (H == 1)
	{
		color1 = ft_high_color(str1);
		color2 = ft_high_color(str2);
		if (color1 == color2)
			return (color1);
	}
	else if ((color1 = ft_converter(str1)) ==
			(color2 = ft_converter(str2)))
		return (color1);
	color_result = get_rvb(color1, color2, cursor);
	return (color_result);
}

void		image_set_pixel(t_mlx *mlx)
{
	if (X1 < 0 || X1 >= W_WIDTH || Y1 < 0 || Y1 >= W_HEIGHT)
		return ;
	*(int *)(mlx->image->ptr + ((X1 + Y1 * W_WIDTH) * BPP)) = COLOR;
}

void		*delete_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image->image);
		ft_memdel((void **)&mlx->image);
	}
	return (NULL);
}

void		*new_image(t_mlx *mlx)
{
	if ((mlx->image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((mlx->image->image = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT))
			== NULL)
		return (delete_image(mlx));
	mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
			&mlx->image->stride, &mlx->image->endian);
	mlx->image->bpp /= 8;
	return (mlx->image);
}
