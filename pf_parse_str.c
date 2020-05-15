/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:04:17 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:39:08 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width_str(t_data *data, char *str)
{
	int		spaces;

	if (data->isprec == 1)
	{
		if (data->prec == -1 || data->prec == 0)
			str[0] = '\0';
		if (data->prec <= (int)ft_strlen(str))
			str[data->prec] = '\0';
	}
	if (data->width <= (int)ft_strlen(str))
	{
		ft_putstr(str);
		return ;
	}
	spaces = data->width - (int)ft_strlen(str);
	while (spaces)
	{
		spaces--;
		ft_putchar(' ');
		data->len++;
	}
	ft_putstr(str);
}

void	parse_str(t_data *data)
{
	char	*arg;

	arg = va_arg(data->args, char *);
	if (!arg)
		arg = ft_strdup("(null)");
	else
		arg = ft_strdup(arg);
	if (data->isprec == 1 && data->width == -1)
		parse_dash_prec_str(data, arg);
	if (data->isdash == 1)
		parse_dash_str(data, arg);
	if (!data->isdash && data->width > 0)
		parse_width_str(data, arg);
	if (!data->isdash && data->width == -1 && data->prec == -1)
		ft_putstr(arg);
	data->len += ft_strlen(arg);
	data->ptr++;
	free(arg);
}
