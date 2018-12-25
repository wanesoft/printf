/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:07:15 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:20:13 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_sing_x_2(t_block_prntf *b, char *str)
{
	if (b->mod == 'x' && b->fl.h && str[0] != '0' && str[1] != '\0')
	{
		ft_putchar('0');
		ft_putchar('x');
		b->r = b->r + 2;
		return (0);
	}
	if (b->mod == 'X' && b->fl.h && str[0] != '0' && str[1] != '\0')
	{
		ft_putchar('0');
		ft_putchar('X');
		b->r = b->r + 2;
		return (0);
	}
	return (0);
}

void		ft_print_x_2_3(t_block_prntf *b, char *str, int len)
{
	if (b->fl.h)
	{
		ft_put_sing_x_2(b, str);
		b->wdth = b->wdth - 2;
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

void		ft_print_x_2_2(t_block_prntf *b, char *str, int len)
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
		ft_print_x_2_3(b, str, len);
}

void		ft_print_x_2(t_block_prntf *b, char *str, int len)
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
	ft_print_x_2_2(b, str, len);
}
