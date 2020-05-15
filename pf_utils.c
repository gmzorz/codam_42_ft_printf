/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:52:35 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:39:56 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_init(t_data *data)
{
	data->prec = -1;
	data->width = -1;
	data->spec = -1;
	data->isdash = 0;
	data->iszero = 0;
	data->isprec = 0;
	data->iscase = 0;
	data->isptr = 0;
}

void	init_table(t_table *init)
{
	init->table[0] = parse_char;
	init->table[1] = parse_str;
	init->table[2] = parse_addr;
	init->table[3] = parse_uint;
	init->table[4] = parse_uint;
	init->table[5] = parse_uint;
	init->table[6] = parse_addr;
	init->table[7] = parse_addr;
	init->table[8] = parse_perc;
}

void	pf_putcstr(int i, char c)
{
	while (i)
	{
		ft_putchar(c);
		i--;
	}
}

int		pf_nullterm(char *str)
{
	if (str[1] == '\0')
		return (0);
	return (1);
}

int		pf_ptrprefix(t_data *data)
{
	int		lenfix;

	lenfix = 0;
	if (data->spec == 2)
		lenfix = 2;
	return (lenfix);
}
