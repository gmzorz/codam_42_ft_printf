/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 16:04:38 by goosterl      #+#    #+#                 */
/*   Updated: 2020/03/03 16:22:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_char(t_data *data)
{
	char	c;
	int		w_len;

	c = va_arg(data->args, int);
	if (!data->isdash && data->width > 0)
	{
		w_len = data->width - 1;
		while (w_len)
		{
			w_len--;
			data->len++;
			ft_putchar(' ');
		}
	}
	if (data->isdash)
		parse_dash_char(data, c);
	else
		ft_putchar(c);
	data->len++;
	data->ptr++;
}
