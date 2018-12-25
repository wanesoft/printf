/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:08:36 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 16:15:38 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_convert_d_i(t_block_prntf *b)
{
	long long int	d;

	d = 0;
	if (b->sz.ll)
		d = va_arg(b->ap, long long int);
	else if (b->sz.hh)
		d = (char)va_arg(b->ap, int);
	else if (b->sz.l)
		d = va_arg(b->ap, long int);
	else if (b->sz.h)
		d = (short int)va_arg(b->ap, int);
	else
		d = va_arg(b->ap, int);
	return (d);
}

void				ft_print_d_i(t_block_prntf *b)
{
	char			*str;
	int				len;

	str = ft_lltoa(ft_convert_d_i(b));
	len = (int)ft_strlen(str);
	if (b->fl.m)
		ft_print_d_i_2(b, str, len);
	else
	{
		if (str[0] == '-')
		{
			len--;
		}
		ft_print_d_i_3(b, str, len);
	}
	free(str);
}

void				ft_work_d_i_2(t_block_prntf *b, const char *format, int i)
{
	while (!(format[i] >= '1' && format[i] <= '9') &&
			format[i] != b->mod && format[i] != '.')
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
	ft_print_d_i(b);
}

void				ft_work_d_i_0(t_block_prntf *b, const char *format)
{
	int				i;

	i = b->i - 1;
	while (format[i] != '%')
	{
		if (format[i] == 'h' && format[i - 1] == 'h')
			b->sz.hh = 1;
		if (format[i] == 'h' && format[i - 1] != 'h' && format[i + 1] != 'h')
			b->sz.h = 1;
		if (format[i] == 'l' && format[i - 1] == 'l')
			b->sz.ll = 1;
		if (format[i] == 'l' && format[i - 1] != 'l' && format[i + 1] != 'l')
			b->sz.l = 1;
		if (format[i] == 'j' && format[i - 1] != 'j' && format[i + 1] != 'j')
			b->sz.l = 1;
		if (format[i] == 'z' && format[i - 1] != 'z' && format[i + 1] != 'z')
			b->sz.ll = 1;
		i--;
	}
	ft_work_d_i_2(b, format, i);
}

void				ft_work_d_i(t_block_prntf *b, const char *format)
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
		if (format[i] == '.')
			b->toch = 1;
		if (format[i] == '.')
			b->toch2 = 1;
		i--;
	}
	ft_work_d_i_0(b, format);
}
