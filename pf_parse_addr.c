/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_addr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 19:37:25 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:38:44 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	addr_len(unsigned long long nbr)
{
	int		ret;

	ret = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		ret++;
	}
	return (ret);
}

static char	hex_set(int nbr)
{
	if (nbr >= 10)
		return ('a' - 10 + nbr);
	else if (nbr < 0)
		return (-nbr + '0');
	else
		return (nbr + '0');
}

void		pf_putaddr(t_data *data, unsigned long long nbr)
{
	unsigned long long	stand;
	char				str[23];
	int					i;
	int					len;

	len = addr_len(nbr);
	i = len;
	if (!nbr)
		str[0] = '0';
	stand = nbr;
	while (i)
	{
		i--;
		str[i] = hex_set(stand % 16);
		stand /= 16;
	}
	while (str[i] && data->spec == 7)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	write(1, str, len);
}

void		addr_print(t_data *data, unsigned long long nbr, int fix)
{
	if (!data->isdash && data->width > fix)
	{
		if (!data->iszero)
			pf_putcstr(data->width - fix, ' ');
		else
			pf_putcstr(data->width - fix, '0');
	}
	if (data->isprec && data->prec > addr_len(nbr))
		pf_putcstr(data->prec - addr_len(nbr), '0');
	if (data->spec == 2)
		write(1, "0x", 2);
	if (!(!data->prec && data->isprec && !nbr))
		pf_putaddr(data, nbr);
	if (data->isdash && data->width > fix)
		pf_putcstr(data->width - fix, ' ');
}

void		parse_addr(t_data *data)
{
	unsigned long long	nbr;
	int					fix;
	int					lenfix;

	lenfix = pf_ptrprefix(data);
	fix = 0;
	if (data->spec == 6 || data->spec == 7)
		nbr = va_arg(data->args, unsigned int);
	else
		nbr = va_arg(data->args, unsigned long long);
	if (data->prec > (addr_len(nbr) + lenfix))
		fix += data->prec;
	else
		fix += addr_len(nbr) + lenfix;
	if (!data->prec && data->isprec && !nbr)
		fix = 0;
	addr_print(data, nbr, fix);
	data->ptr++;
	if (data->width > fix)
		data->len += data->width;
	else
		data->len += fix;
}
