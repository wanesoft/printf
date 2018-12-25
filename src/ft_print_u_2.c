/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:05:56 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:16:41 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_u_2_3(t_block_prntf *b, char *str, int len)
{
	ft_putstr(str);
	b->r = b->r + len;
	b->wdth = b->wdth - len;
	while (b->wdth > 0)
	{
		ft_putchar(' ');
		b->r++;
		b->wdth--;
	}
}

void		ft_print_u_2_2(t_block_prntf *b, char *str, int len)
{
	if (b->toch)
	{
		b->toch = b->toch - len;
		while (b->toch > 0)
		{
			ft_putchar('0');
			b->r++;
			b->wdth--;
			b->toch--;
		}
		ft_putstr(str);
		b->r = b->r + len;
		b->wdth = b->wdth - len;
		while (b->wdth > 0)
		{
			ft_putchar(' ');
			b->r++;
			b->wdth--;
		}
	}
	else
		ft_print_u_2_3(b, str, len);
}

void		ft_print_u_2(t_block_prntf *b, char *str, int len)
{
	if (*str == '-')
	{
		ft_putchar('-');
		str++;
		b->toch++;
	}
	else if (b->fl.p)
	{
		ft_putchar('+');
		b->r++;
		b->wdth--;
	}
	else if (b->fl.w)
	{
		ft_putchar(' ');
		b->r++;
		b->wdth--;
	}
	ft_print_u_2_2(b, str, len);
}
