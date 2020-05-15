/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 18:01:20 by goosterl      #+#    #+#                 */
/*   Updated: 2020/05/12 11:38:30 by gijsoosterl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIFIER "cspdiuxX%"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_data
{
	va_list		args;
	char		*ptr;
	int			len;
	int			width;
	int			prec;
	int			spec;
	int			isptr;
	int			isdash;
	int			iszero;
	int			isprec;
	int			iscase;
}				t_data;

typedef void	t_parse(t_data *data);

typedef struct	s_table
{
	t_parse		*table[9];
}				t_table;

int				ft_printf(const char *types, ...);

/*
**		specifiers
*/

void			parse_flags(t_data *data);
void			parse_char(t_data *data);
void			parse_str(t_data *data);
void			parse_ptr(t_data *data);
void			parse_int(t_data *data);
void			parse_uint(t_data *data);
void			parse_addr(t_data *data);
void			parse_hexc(t_data *data);
void			parse_perc(t_data *data);

/*
**		everything else
*/

void			pf_putcstr(int i, char c);
void			pf_init(t_data *data);
void			init_table(t_table *init);
void			parse_width_str(t_data *data, char *str);
void			dash_percentage(t_data *data, char per);
void			widthonly_percentage(t_data *data, char per);
void			zeroes_percentage(t_data *data, char per);
void			parse_dash_char(t_data *data, char c);
void			parse_dash_str(t_data *data, char *arg);
void			parse_dash_prec_str(t_data *data, char *arg);
int				pf_nullterm(char *str);
int				pf_ptrprefix(t_data *data);

#endif
