/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:07:41 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:46:47 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_c_2(t_block_prntf *b, unsigned char c)
{
	char			ws;

	ws = ' ';
	if (b->fl.z)
		ws = '0';
	if (!b->toch)
		while (b->wdth > 1)
		{
			ft_putchar(ws);
			b->wdth--;
			b->r++;
		}
	ft_putchar(c);
	b->r++;
}

void				ft_print_c(t_block_prntf *b)
{
	char			c;

	c = (char)va_arg(b->ap, int);
	if (b->fl.m)
	{
		ft_putchar(c);
		b->r++;
		b->wdth--;
		while (b->wdth > 0)
		{
			ft_putchar(' ');
			b->wdth--;
			b->r++;
		}
	}
	else
		ft_print_c_2(b, c);
}

void				ft_work_c(t_block_prntf *b, const char *format)
{
	int				i;

	i = b->i;
	while (format[i] != '%')
	{
		if (format[i] == '-')
			b->fl.m = 1;
		if (format[i] == '.')
			b->toch = 1;
		i--;
	}
	while (!(format[i] >= '1' && format[i] <= '9') && format[i] != b->mod)
	{
		if (format[i] == '0')
			b->fl.z = 1;
		i++;
	}
	b->wdth = ft_atoi(&format[i]);
	ft_print_c(b);
}
