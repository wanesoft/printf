/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:08:45 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:47:50 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int				ft_convert_u(t_block_prntf *b)
{
	unsigned long long int	d;

	d = 0;
	if (b->sz.ll)
		d = va_arg(b->ap, unsigned long long int);
	else if (b->sz.hh)
		d = (unsigned char)va_arg(b->ap, unsigned int);
	else if (b->sz.l || b->mod == 'U')
		d = va_arg(b->ap, unsigned long int);
	else if (b->sz.h)
		d = (unsigned short int)va_arg(b->ap, unsigned int);
	else
		d = va_arg(b->ap, unsigned int);
	return (d);
}

void						ft_print_u(t_block_prntf *b)
{
	char					*str;
	int						len;

	str = ft_llutoa(ft_convert_u(b));
	len = (int)ft_strlen(str);
	if (b->fl.m)
		ft_print_u_2(b, str, len);
	else
	{
		if (str[0] == '-')
		{
			len--;
		}
		ft_print_u_3(b, str, len);
	}
	free(str);
}

void						ft_work_u_2(t_block_prntf *b,
										const char *format, int i)
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
	ft_print_u(b);
}

void						ft_work_u_0(t_block_prntf *b, const char *format)
{
	int						i;

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
	ft_work_u_2(b, format, i);
}

void						ft_work_u(t_block_prntf *b, const char *format)
{
	int						i;

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
	ft_work_u_0(b, format);
}
