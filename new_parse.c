/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:43:01 by ofranco           #+#    #+#             */
/*   Updated: 2017/09/30 16:26:52 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int			count_y(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_get_y_nbrvalue(char *av)
{
	int		fd;
	char	*line;
	char	**split;
	int		res;

	fd = open(av, O_RDONLY, S_IREAD);
	if (get_next_line(fd, &line) >= 0)
		split = ft_split(line, " ");
	else
		return (-1);
	close(fd);
	res = count_y(split);
	free(line);
	free(split);
	return (res);
}

char		**copy_split(char **split, t_mlx *mlx)
{
	int		i;
	char	**cpy;

	if ((cpy = (char**)malloc(sizeof(char*) * Y_NB_VAL)) == NULL)
		return (NULL);
	i = 0;
	while (i < Y_NB_VAL)
	{
		cpy[i] = ft_strdup(split[i]);
		i++;
	}
	return (cpy);
}

int			two_per_two_got_split(t_mlx *mlx, char *s2, int val, int fd)
{
	free(s2);
	ft_tab_coord_sending(mlx);
	while (1)
	{
		free(mlx->tab[0]);
		mlx->tab[0] = copy_split(mlx->tab[1], mlx);
		X--;
		free(mlx->tab[1]);
		if ((val = get_next_line(fd, &s2)) < 0)
			return (-1);
		if (val == 0)
			break ;
		mlx->tab[1] = ft_split(s2, " ");
		if (count_y(mlx->tab[1]) < Y_NB_VAL)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (-1);
		}
		X_TMP = 0;
		ft_tab_coord_sending(mlx);
	}
	free(mlx->tab);
	if (s2 != 0)
		free(s2);
	return (val);
}

int			two_per_two(char *av, t_mlx *mlx)
{
	int		fd;
	int		gnl_val;
	char	*s1;
	char	*s2;

	X = 0;
	fd = open(av, O_RDONLY, S_IREAD);
	if ((mlx->tab = (char ***)malloc(sizeof(char **) * 2)) == NULL)
		return (0);
	if ((gnl_val = get_next_line(fd, &s1)) < 0)
		return (-1);
	if ((gnl_val = get_next_line(fd, &s2)) < 0)
		return (-1);
	mlx->tab[0] = ft_split(s1, " ");
	mlx->tab[1] = ft_split(s2, " ");
	if (count_y(mlx->tab[1]) < Y_NB_VAL)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		return (-1);
	}
	free(s1);
	gnl_val = two_per_two_got_split(mlx, s2, gnl_val, fd);
	return (gnl_val);
}
