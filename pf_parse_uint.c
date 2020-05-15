/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_parse_uint.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 17:10:31 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:39:42 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			int_numlen(long long num)
{
	int		ret;

	ret = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

static void			pf_putnbr(long long n)
{
	if (n > 9)
		pf_putnbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

static void			int_print(t_data *data, long long nbr, int fix, int isneg)
{
	if (isneg == 1 && data->iszero)
		ft_putchar('-');
	if (!data->isdash && data->width > fix)
	{
		if (!data->iszero)
			pf_putcstr(data->width - fix, ' ');
		else
			pf_putcstr(data->width - fix, '0');
	}
	if (isneg == 1 && !data->iszero)
		ft_putchar('-');
	if (data->isprec == 1 && data->prec > int_numlen(nbr))
		pf_putcstr(data->prec - int_numlen(nbr), '0');
	if (!(!data->prec && data->isprec && !nbr))
		pf_putnbr(nbr);
	if (data->isdash && data->width > fix)
		pf_putcstr(data->width - fix, ' ');
}

static long long	get_arg_type(t_data *data)
{
	if (data->spec == 3 || data->spec == 4)
		return (va_arg(data->args, int));
	else
		return (va_arg(data->args, unsigned int));
}

void				parse_uint(t_data *data)
{
	long long		nbr;
	int				fix;
	int				isneg;

	fix = 0;
	isneg = 0;
	nbr = get_arg_type(data);
	if (nbr < 0)
	{
		nbr *= -1;
		isneg = 1;
		fix = 1;
	}
	if (data->prec > int_numlen(nbr))
		fix += data->prec;
	else
		fix += int_numlen(nbr);
	if (!data->prec && data->isprec && !nbr)
		fix = 0;
	int_print(data, nbr, fix, isneg);
	data->ptr++;
	if (data->width > fix)
		data->len += data->width;
	else
		data->len += fix;
}
