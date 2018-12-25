/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:08:12 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:18:30 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_sing_o(t_block_prntf *b, int len)
{
	if (b->fl.h && (len + 1 != b->toch))
	{
		ft_putchar('0');
		b->r = b->r + 1;
		return (0);
	}
	return (0);
}

void		ft_print_o_3_2(t_block_prntf *b)
{
	while (b->toch > 0)
	{
		ft_putchar('0');
		b->wdth--;
		b->r++;
		b->toch--;
	}
}

void		ft_print_o_3_4(t_block_prntf *b, char *str, int len)
{
	if (str[0] == '-')
		b->wdth--;
	while (b->wdth > 0)
	{
		b->r = b->r + (int)write(1, " ", 1);
		b->wdth--;
	}
	ft_put_sing_o(b, len);
	if (str[0] != '0')
	{
		ft_putstr(str);
		b->r = b->r + len;
	}
	else if (!b->toch2 && str[0] == '0')
	{
		if (b->fl.h)
		{
			b->r--;
			str++;
		}
		ft_putstr(str);
		b->r = b->r + len;
	}
	else if (b->toch2 && str[0] == '0' && b->wdth >= 0)
		b->r = b->r + (int)write(1, " ", 1);
}

void		ft_print_o_3_3(t_block_prntf *b, char *str, int len)
{
	if (b->fl.z)
	{
		if (ft_put_sing_o(b, len))
		{
			b->wdth--;
			str++;
		}
		if (b->fl.h)
			b->wdth = b->wdth - 1;
		b->wdth = b->wdth - len;
		while (b->wdth > 0)
		{
			b->r = b->r + (int)write(1, "0", 1);
			b->wdth--;
		}
		ft_putstr(str);
		b->r = b->r + len;
	}
	else
	{
		if (b->fl.h)
			b->wdth = b->wdth - 1;
		b->wdth = b->wdth - len;
		ft_print_o_3_4(b, str, len);
	}
}

void		ft_print_o_3(t_block_prntf *b, char *str, int len)
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
		if (ft_put_sing_o(b, len))
			str++;
		ft_print_o_3_2(b);
		ft_putstr(str);
		b->r = b->r + len;
	}
	else
		ft_print_o_3_3(b, str, len);
}
