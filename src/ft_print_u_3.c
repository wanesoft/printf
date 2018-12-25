/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:36 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:19:27 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_sing_u(t_block_prntf *b, char *str)
{
	if (*str == '-')
	{
		ft_putchar('-');
		b->r++;
		return (1);
	}
	return (0);
}

void		ft_print_u_3_2(t_block_prntf *b)
{
	while (b->toch > 0)
	{
		ft_putchar('0');
		b->wdth--;
		b->r++;
		b->toch--;
	}
}

void		ft_print_u_3_4(t_block_prntf *b, char *str, int len)
{
	b->wdth = b->wdth - len;
	if (str[0] == '-')
		b->wdth--;
	while (b->wdth > 0)
	{
		b->r = b->r + write(1, " ", 1);
		b->wdth--;
	}
	if (ft_put_sing_u(b, str))
		str++;
	if (str[0] != '0')
	{
		ft_putstr(str);
		b->r = b->r + len;
	}
	else if (!b->toch2 && str[0] == '0')
	{
		ft_putstr(str);
		b->r = b->r + len;
	}
	else if (b->toch2 && str[0] == '0' && b->wdth >= 0)
	{
		ft_putchar(' ');
		b->r++;
	}
}

void		ft_print_u_3_3(t_block_prntf *b, char *str, int len)
{
	if (b->fl.z)
	{
		if (ft_put_sing_u(b, str))
		{
			b->wdth--;
			str++;
		}
		b->wdth = b->wdth - len;
		while (b->wdth > 0)
		{
			ft_putchar('0');
			b->wdth--;
			b->r++;
		}
		ft_putstr(str);
		b->r = b->r + len;
	}
	else
		ft_print_u_3_4(b, str, len);
}

void		ft_print_u_3(t_block_prntf *b, char *str, int len)
{
	if (b->toch)
	{
		if (b->toch >= len)
			b->toch = b->toch - len;
		else
			b->toch = 0;
		b->wdth = b->wdth - len - b->toch;
		if (b->fl.w || b->fl.p || str[0] == '-')
			b->wdth--;
		while (b->wdth > 0)
		{
			ft_putchar(' ');
			b->wdth--;
			b->r++;
		}
		if (ft_put_sing_u(b, str))
			str++;
		ft_print_u_3_2(b);
		ft_putstr(str);
		b->r = b->r + len;
	}
	else
		ft_print_u_3_3(b, str, len);
}
