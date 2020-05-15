/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 17:56:47 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:38:31 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_parser(t_data *data)
{
	t_table	parser;

	init_table(&parser);
	while (*data->ptr)
	{
		if (*data->ptr == '%' && pf_nullterm(data->ptr))
		{
			pf_init(data);
			data->ptr++;
			parse_flags(data);
			data->spec = ft_strnchr(SPECIFIER, *data->ptr);
			if (data->spec != -1)
				parser.table[data->spec](data);
		}
		else if (*data->ptr != '%')
		{
			ft_putchar(*data->ptr);
			data->ptr++;
			data->len++;
		}
		else
			data->ptr++;
	}
}

int			ft_printf(const char *input, ...)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->ptr = (char *)input;
	data->len = 0;
	pf_init(data);
	va_start(data->args, input);
	pf_parser(data);
	va_end(data->args);
	free(data);
	return (data->len);
}
