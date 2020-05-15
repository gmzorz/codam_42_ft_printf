/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:54:33 by goosterl      #+#    #+#                 */
/*   Updated: 2020/03/02 19:07:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*str;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (i < (int)(ft_strlen(s) + 1))
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}
