/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:04:34 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:14:47 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_f5(t_block_prntf *b)
{
	char					ws;

	ws = b->fl.z ? '0' : ' ';
	if (b->fl.z)
	{
		ft_printf("-");
	}
}

void		ft_parse_f4(t_block_prntf *b, unsigned long long int dec,
										unsigned long long int ost)
{
	char					ws;

	ws = b->fl.z ? '0' : ' ';
	b->wdth = b->wdth - ft_ulllen(dec) - ft_ulllen(ost);
	ost ? b->wdth-- : 0;
	if (!b->mod && !b->fl.z)
		b->wdth--;
	if (b->fl.p && !b->fl.z)
		b->wdth--;
	else if (b->fl.w && !b->fl.z)
		b->wdth--;
	while (b->wdth > 0)
	{
		b->r = b->r + (int)write(1, &ws, 1);
		b->wdth--;
	}
	if (!b->mod && !b->fl.z)
		b->r = b->r + ft_printf("-");
	if (b->fl.p && !b->fl.z)
		b->r = b->r + ft_printf("+");
	else if (b->fl.w && !b->fl.z)
		b->r = b->r + ft_printf(" ");
	b->r = b->r + ft_printf("%lld", dec);
	if (ost)
		b->r = b->r + ft_printf(".%lld", ost);
}

void		ft_parse_f3(t_block_prntf *b, unsigned long long int dec,
										unsigned long long int ost)
{
	if (!b->mod)
	{
		b->wdth--;
		b->r = b->r + ft_printf("-");
	}
	else if (b->fl.p)
	{
		b->wdth--;
		b->r = b->r + ft_printf("+");
	}
	else if (b->fl.w)
	{
		b->wdth--;
		b->r = b->r + ft_printf(" ");
	}
	b->r = b->r + ft_printf("%lld", dec);
	if (ost)
	{
		b->r = b->r + ft_printf(".%lld", ost);
		b->wdth--;
	}
	b->wdth = b->wdth - ft_ulllen(dec) - ft_ulllen(ost);
	while (b->wdth-- > 0)
		b->r = b->r + (int)write(1, " ", 1);
}

void		ft_parse_f2(t_block_prntf *b, unsigned long long int dec,
										unsigned long long int ost)
{
	if (!b->mod && b->fl.z)
	{
		b->wdth--;
		b->r = b->r + ft_printf("-");
	}
	else if (b->fl.p && b->fl.z)
	{
		b->wdth--;
		b->r = b->r + ft_printf("+");
	}
	else if (b->fl.w && b->fl.z)
	{
		b->wdth--;
		b->r = b->r + ft_printf(" ");
	}
	if (b->fl.m)
		ft_parse_f3(b, dec, ost);
	else
		ft_parse_f4(b, dec, ost);
}

void		ft_parse_f(long double d, t_block_prntf *b)
{
	unsigned long long int	arr[2];

	if (d < 0)
	{
		d = d * -1;
		b->fl.w = 0;
		b->fl.p = 0;
		b->mod = 0;
	}
	arr[0] = (unsigned long long int)d;
	arr[1] = (unsigned long long int)((d - arr[0])
			* (ft_pow(10, (b->toch + 1))));
	ft_okgug(arr, b, d);
	ft_parse_f2(b, arr[0], arr[1]);
}
