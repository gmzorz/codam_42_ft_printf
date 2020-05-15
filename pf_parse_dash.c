/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_dash.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 18:38:47 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:38:53 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_dash_str(t_data *data, char *str)
{
	int		spaces;

	if (data->isprec == 1)
	{
		if (data->prec == -1 || data->prec == 0)
			str[0] = '\0';
		if (data->prec <= (int)ft_strlen(str))
			str[data->prec] = '\0';
		if (data->width == -1)
			return ;
	}
	if (data->width <= (int)ft_strlen(str))
	{
		ft_putstr(str);
		return ;
	}
	spaces = data->width - (int)ft_strlen(str);
	ft_putstr(str);
	while (spaces)
	{
		spaces--;
		ft_putchar(' ');
		data->len++;
	}
}

void	parse_dash_prec_str(t_data *data, char *str)
{
	if (data->prec == -1 || data->prec == 0)
	{
		str[0] = '\0';
		return ;
	}
	if (data->prec <= (int)ft_strlen(str))
	{
		str[data->prec] = '\0';
		ft_putstr(str);
		return ;
	}
	if (data->prec > 0 && data->prec > (int)ft_strlen(str))
		ft_putstr(str);
}

void	parse_dash_char(t_data *data, char c)
{
	int	spaces;

	ft_putchar(c);
	if (data->width == -1)
		return ;
	spaces = data->width - 1;
	while (spaces)
	{
		spaces--;
		ft_putchar(' ');
		data->len++;
	}
}
