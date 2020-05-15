/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:00:36 by goosterl      #+#    #+#                 */
/*   Updated: 2019/12/02 20:23:19 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long	res;
	unsigned long	lim;
	int				neg;

	neg = 1;
	res = 0;
	lim = LONG_MAX / 10;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((res > lim || (res == lim && (*str - '0') > 7)) && neg == 1)
			return (-1);
		else if ((res > lim || (res == lim && (*str - '0') > 8)) && neg == -1)
			return (0);
		res = res * 10 + (*str - '0');
		++str;
	}
	return ((int)res * neg);
}
