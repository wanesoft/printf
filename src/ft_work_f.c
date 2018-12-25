/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:05:31 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 16:17:31 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			ft_convert_f(t_block_prntf *b)
{
	long double		d;

	d = 0;
	if (b->sz.b)
		d = (long double)va_arg(b->ap, long double);
	else if (b->sz.l)
		d = (long double)va_arg(b->ap, double);
	else
		d = (long double)va_arg(b->ap, double);
	return (d);
}

void				ft_print_f(t_block_prntf *b)
{
	if (!b->toch && !b->toch2)
		b->toch = 6;
	ft_parse_f(ft_convert_f(b), b);
}

void				ft_work_f_2(t_block_prntf *b, const char *format, int i)
{
	while (!(format[i] >= '1' && format[i] <= '9')
			&& format[i] != b->mod && format[i] != '.')
	{
		if (format[i] == '0')
			b->fl.z = 1;
		i++;
	}
	if (format[i] == '.')
	{
		i++;
		b->toch = ft_atoi(&format[i]);
	}
	else if (format[i] >= '1' && format[i] <= '9')
	{
		b->wdth = ft_atoi(&format[i]);
		if (b->toch)
		{
			while (format[i] != '.')
				i++;
			i++;
			b->toch = ft_atoi(&format[i]);
		}
	}
	ft_print_f(b);
}

void				ft_work_f_0(t_block_prntf *b, const char *format)
{
	int				i;

	i = b->i - 1;
	while (format[i] != '%')
	{
		if (format[i] == 'l' && format[i - 1] != 'l' && format[i + 1] != 'l')
			b->sz.l = 1;
		if (format[i] == 'L' && format[i - 1] != 'L' && format[i + 1] != 'L')
			b->sz.b = 1;
		i--;
	}
	ft_work_f_2(b, format, i);
}

void				ft_work_f(t_block_prntf *b, const char *format)
{
	int				i;

	i = b->i - 1;
	while (format[i] != '%')
	{
		if (format[i] == '-')
			b->fl.m = 1;
		if (format[i] == ' ')
			b->fl.w = 1;
		if (format[i] == '+')
			b->fl.p = 1;
		if (format[i] == '#')
			b->fl.h = 1;
		if (format[i] == '.')
			b->toch = 1;
		if (format[i] == '.')
			b->toch2 = 1;
		i--;
	}
	ft_work_f_0(b, format);
}
