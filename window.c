/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:56:41 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 16:26:45 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_mlx		*mlx_free(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image != NULL)
		delete_image(mlx);
	if (mlx->env != NULL)
		ft_memdel((void **)&mlx->env);
	if (mlx->algo != NULL)
		ft_memdel((void **)&mlx->algo);
	if (mlx->coord != NULL)
		ft_memdel((void **)&mlx->coord);
	ft_memdel((void **)&mlx);
	exit(-1);
}

t_mlx		*initialize(void)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL
		|| (mlx->env = ft_memalloc(sizeof(t_env))) == NULL
		|| (mlx->algo = ft_memalloc(sizeof(t_rosette))) == NULL
		|| (mlx->coord = ft_memalloc(sizeof(t_coords))) == NULL)
		return (mlx_free(mlx));
	return (mlx);
}
