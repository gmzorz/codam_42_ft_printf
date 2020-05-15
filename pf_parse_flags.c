/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:02 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:38:58 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_data *data)
{
	if (*data->ptr == '*')
	{
		data->width = va_arg(data->args, int);
		data->ptr++;
		if (data->width < 0)
		{
			data->isdash = 1;
			data->width *= -1;
		}
	}
	else
	{
		while (ft_isdigit(*data->ptr))
		{
			if (data->width == -1)
				data->width++;
			data->width = data->width * 10 + (*data->ptr - '0');
			data->ptr++;
		}
	}
}

void	parse_prec(t_data *data)
{
	data->isprec = 1;
	if (*data->ptr == '*')
	{
		data->prec = va_arg(data->args, int);
		data->ptr++;
		if (data->prec < 0)
		{
			data->isprec = 0;
			data->prec = -1;
		}
		else
			data->iszero = 0;
	}
	else
	{
		data->iszero = 0;
		while (ft_isdigit(*data->ptr))
		{
			data->prec = data->prec * 10 + (*data->ptr - '0');
			data->ptr++;
		}
	}
}

void	parse_flags(t_data *data)
{
	if (!ft_strchr(SPECIFIER, *data->ptr) && pf_nullterm(data->ptr))
	{
		while (*data->ptr == '-' || *data->ptr == '0')
		{
			if (*data->ptr == '-')
				data->isdash = 1;
			if (*data->ptr == '0')
				data->iszero = 1;
			data->ptr++;
		}
		parse_width(data);
		if (*data->ptr == '.')
		{
			data->ptr++;
			data->prec++;
			parse_prec(data);
		}
	}
}
