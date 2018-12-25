/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:05:15 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 16:18:52 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_initia(t_block_prntf *b, int fl)
{
	b->fl.h = 0;
	b->fl.z = 0;
	b->fl.w = 0;
	b->fl.m = 0;
	b->fl.p = 0;
	b->sz.h = 0;
	b->sz.hh = 0;
	b->sz.l = 0;
	b->sz.ll = 0;
	b->sz.b = 0;
	b->wdth = 0;
	b->toch = 0;
	b->toch2 = 0;
	b->mod = 0;
	b->i = fl ? b->i : 0;
	b->r = fl ? b->r : 0;
}

char				ft_find_mod(const char *d_mods,
		const char *format, t_block_prntf *b)
{
	int				i;
	int				j;

	i = b->i;
	j = 0;
	while (format[i] != '\0')
	{
		while (d_mods[j] != '\0')
		{
			if (format[i] == d_mods[j])
			{
				b->i = i + 1;
				return (format[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void				ft_conver(t_block_prntf *b, const char *format)
{
	b->i++;
	ft_initia(b, 1);
	b->mod = ft_find_mod(D_MODS, format, b);
	if (b->mod == 'c' || b->mod == 'C')
		ft_work_c(b, format);
	if (b->mod == 's' || b->mod == 'S')
		ft_work_s(b, format);
	if (b->mod == 'p' || b->mod == 'P')
		ft_work_p(b, format);
	if (b->mod == 'd' || b->mod == 'i' || b->mod == 'D' || b->mod == 'I')
		ft_work_d_i(b, format);
	if (!b->mod)
		ft_work(b, format);
	if (b->mod == 'u' || b->mod == 'U')
		ft_work_u(b, format);
	if (b->mod == 'x' || b->mod == 'X')
		ft_work_x(b, format);
	if (b->mod == 'o' || b->mod == 'O')
		ft_work_o(b, format);
	if (b->mod == 'f' || b->mod == 'F')
		ft_work_f(b, format);
}

int					ft_printf(const char *format, ...)
{
	t_block_prntf	b;

	ft_initia(&b, 0);
	va_start(b.ap, format);
	while (format[b.i])
	{
		if (format[b.i] == '%' && format[b.i + 1] == '%')
		{
			b.r = b.r + (int)write(1, "%", 1);
			b.i = b.i + 2;
		}
		else if (format[b.i] == '%' && format[b.i + 1] != '%')
			ft_conver(&b, format);
		else
			b.r = b.r + (int)write(1, &(format[b.i++]), 1);
	}
	va_end(b.ap);
	return (b.r);
}
