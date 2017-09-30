/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 20:02:22 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 16:26:27 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	main_assign2(t_mlx *mlx, char **argv)
{
	X = 0;
	Y = 0;
	SHIFT_Y = 0;
	SHIFT_X = 0;
	H = 0;
	ZOOM = 5;
	SPIN = 2;
	LAYER = 2;
	O = 0;
	if ((mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT,
					ft_strjoin("FdF -", argv[1]))) == NULL)
		mlx_free(mlx);
	if ((mlx->image = new_image(mlx)) == NULL)
		mlx_free(mlx);
	if ((two_per_two(ARGV1, mlx)) < 0)
	{
		printf("something went wrong in here\n");
		exit(-1);
	}
	return ;
}

void	main_assign(t_mlx *mlx, int argc, char **argv)
{
	if (argc >= 3)
		T_WIDTH = ft_getnbr(argv[2]);
	else
		T_WIDTH = (int)((500 / Y_NB_VAL) - ((500 / Y_NB_VAL) % 1));
	T_HEIGHT = ((T_WIDTH * 4) / 5);
	if (T_HEIGHT == T_WIDTH || (T_WIDTH - 10) == T_HEIGHT
			|| (T_WIDTH - 1) == T_HEIGHT || (T_HEIGHT - 1) == T_WIDTH)
		T_HEIGHT = ((T_HEIGHT -= 3) < 0) ? 1 : T_HEIGHT;
	if (argc == 4)
		Z_SIZE = ft_getnbr(argv[3]);
	else
		Z_SIZE = 5;
	if (argc == 6)
	{
		W_WIDTH = ((ft_atoi(argv[4]) < 1280 * 2)) ? ft_atoi(argv[4]) : 1280 * 2;
		W_HEIGHT = ((ft_atoi(argv[5]) < 724 * 2)) ? ft_atoi(argv[5]) : 724 * 2;
	}
	else
	{
		W_WIDTH = ((Y_NB_VAL * 50) < 1280 * 2) ? Y_NB_VAL * Y_NB_VAL
			: 1280 * 2;
		W_WIDTH = (W_WIDTH < 1280 / 2) ? 1280 / 2 : W_WIDTH;
		W_HEIGHT = ((W_WIDTH * 4) / 5);
	}
	return ;
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 1 || argc > 6)
		ft_putstr("Usage : ./fdf <file> [c_size z_size w_width w_height]\n");
	if ((mlx = initialize()) == NULL)
		return (-1);
	if (!(mlx->env->ret = (int*)malloc(sizeof(int) * 2)))
		return (-1);
	ARGV1 = argv[1];
	if ((Y_NB_VAL = ft_get_y_nbrvalue(ARGV1)) < 1)
	{
		ft_putstr("No data found. \n");
		return (0);
	}
	X_NB_VAL = 2;
	main_assign(mlx, argc, argv);
	main_assign2(mlx, argv);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
