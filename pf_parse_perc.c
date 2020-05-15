/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_perc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 18:20:53 by goosterl      #+#    #+#                 */
/*   Updated: 2020/03/04 18:20:54 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_perc(t_data *data)
{
	if (data->isdash)
		dash_percentage(data, '%');
	if (!data->isdash && data->width > 0 && !data->iszero)
		widthonly_percentage(data, '%');
	if (data->iszero && !data->isdash)
		zeroes_percentage(data, '%');
	if (!data->isdash && data->width == -1 && data->prec == -1)
		ft_putchar('%');
	data->len++;
	data->ptr++;
}

void	dash_percentage(t_data *data, char per)
{
	int		spaces;

	if (data->width <= 1)
	{
		ft_putchar(per);
		return ;
	}
	spaces = data->width - 1;
	ft_putchar(per);
	while (spaces)
	{
		spaces--;
		ft_putchar(' ');
		data->len++;
	}
}

void	widthonly_percentage(t_data *data, char per)
{
	int		spaces;

	if (data->width <= 1)
	{
		ft_putchar(per);
		return ;
	}
	spaces = data->width - 1;
	while (spaces)
	{
		spaces--;
		ft_putchar(' ');
		data->len++;
	}
	ft_putchar(per);
}

void	zeroes_percentage(t_data *data, char per)
{
	int		spaces;

	if (data->width <= 1)
	{
		ft_putchar(per);
		return ;
	}
	spaces = data->width - 1;
	while (spaces)
	{
		spaces--;
		ft_putchar('0');
		data->len++;
	}
	ft_putchar(per);
}
