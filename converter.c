/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:55:11 by ofranco           #+#    #+#             */
/*   Updated: 2017/09/30 16:27:17 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int			gradiant_color(int color1, int color2, double cursor)
{
	int		color3;

	color3 = (int)((double)color1 + (color2 - color1) * cursor);
	return (color3);
}

int			get_rvb(int color1, int color2, double cursor)
{
	int		red;
	int		green;
	int		blue;

	if (color1 == color2)
		return (color1);
	red = gradiant_color((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, cursor);
	green = gradiant_color((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, cursor);
	blue = gradiant_color(color1 & 0xFF, color2 & 0xFF, cursor);
	return (red << 16 | green << 8 | blue);
}

double		ft_get_cursor(double here, double start, double end)
{
	double	cursor;

	if (here == start)
	{
		cursor = 0.0;
		return (cursor);
	}
	if (here == end)
	{
		cursor = 1.0;
		return (cursor);
	}
	cursor = (here - start) / (end - start);
	return (cursor);
}

int			ft_get_val(char c)
{
	int		value;

	value = -1;
	if (c >= '0' && c <= '9')
		value = c - '0';
	if ((c >= 'a' && c <= 'f'))
		value = 10 + ((c - 49) - '0');
	if (c >= 'A' && c <= 'Z')
		value = 10 + ((c - 17) - '0');
	return (value);
}

int			ft_converter(char *str)
{
	char	*trim;
	int		i;
	int		len;
	int		result;
	int		int_val;

	result = 0;
	if (ft_strchr(str, ',') != NULL)
		trim = ft_strchr(str, ',') + 1;
	else
		return (0xFFFFFF);
	len = ft_strlen(trim) - 1;
	i = 0;
	while (trim[len] != 'x')
	{
		int_val = ft_get_val(trim[len]);
		result = result + (int_val * (int)pow(16, (double)i));
		len--;
		i++;
	}
	return (result);
}
