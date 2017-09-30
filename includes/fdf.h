/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:30:01 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 15:55:33 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H_
# define FDF_H_

#include "./../libft/libft.h"
#include "./../minilibx_macos/mlx.h"
#include <stdio.h>
#include <math.h>
#define W_WIDTH mlx->env->wWidth
#define W_HEIGHT mlx->env->wHeight
#define Y mlx->coord->y
#define Y_TMP mlx->coord->yTMP
#define X mlx->coord->x
#define X_TMP mlx->coord->xTMP
#define I mlx->coord->i
#define J mlx->coord->j
#define T_WIDTH mlx->env->tWidth
#define T_HEIGHT mlx->env->tHeight
#define ZOOM mlx->coord->zoom
#define SHIFT_X mlx->coord->shiftX
#define SHIFT_Y mlx->coord->shiftY
#define Z mlx->tab[mlx->coord->xTMP + mlx->coord->i][mlx->coord->yTMP + mlx->coord->j]
#define Z_SIZE mlx->env->z_size
#define X_NB_VAL mlx->env->ret[0]
#define Y_NB_VAL mlx->env->ret[1]
#define X1 mlx->algo->x1
#define Y1 mlx->algo->y1
#define X2 mlx->algo->x2
#define Y2 mlx->algo->y2
#define EY mlx->algo->ey
#define EX mlx->algo->ex
#define DX mlx->algo->dx
#define DY mlx->algo->dy
#define X_INCR mlx->algo->Xincr
#define Y_INCR mlx->algo->Yincr
#define RX mlx->algo->Rx
#define RY mlx->algo->Ry
#define COLOR mlx->algo->color
#define BPP mlx->image->bpp
#define A mlx->coord->a
#define B mlx->coord->b
#define COLORXY1 mlx->coord->colorxy1
#define COLORXY2 mlx->coord->colorxy2
#define SPIN mlx->coord->spin
#define H mlx->coord->high
#define LAYER mlx->coord->layer
#define ARGV1 mlx->env->argv
#define O mlx->coord->o_mode

typedef struct			s_rosette {

	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		Xincr;
	int		Yincr;
	int		Rx;
	int		Ry;
	int		i;
	int		color;

}						t_rosette;

typedef struct			s_env {

	int		*winS;
	int		tWidth;
	int		tHeight;
	int		wWidth;
	int		wHeight;
	int		*ret;
	int		z_size;
	char	*argv;
}						t_env;

typedef struct			s_coords {

	int		x;
	int		xTMP;
	int		y;
	int		yTMP;
	int		i;
	int		j;
	int		shiftY;
	int		shiftX;
	int		zoom;
	int		a;
	int		b;
	char	*colorxy1;
	char	*colorxy2;
	int		spin;
	int 	high;
	int		layer;
	int		o_mode;

}						t_coords;

typedef struct			s_image {

	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;

}						t_image;

typedef struct			s_mlx {

	int			*mlx;
	int			*win;
	char		***tab;
	t_image		*image;
	t_coords	*coord;
	t_env		*env;
	t_rosette	*algo;
}						t_mlx;


void		ft_line_tracer(t_mlx *mlx);
void		ft_calc_coords(t_mlx *mlx, int j);
void		ft_window(char ***tab, t_mlx *mlx);
char		***ft_creatparse(char *av, int *x, int *y);
t_mlx		*initialize(void);
void		*new_image(t_mlx *mlx);
void		*delete_image(t_mlx *mlx);
void		image_set_pixel(t_mlx *mlx);
void		ft_tab_coord_sending(t_mlx *mlx);
void		test_func(t_mlx *mlx, int test_id);
int			ft_apply_color(char *str1, char *str2, double cursor, t_mlx *mlx);
double		ft_get_cursor(double here, double start, double end);
int			ft_converter(char *str);
int			get_rvb(int color1, int color2, double cursor);
t_mlx		*mlx_free(t_mlx *mlx);
int			two_per_two(char *av, t_mlx *mlx);
int			ft_get_y_nbrvalue(char *av);
int			key_func(int keycode, t_mlx *mlx);

#endif
