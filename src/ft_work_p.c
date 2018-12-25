/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:56 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:06:59 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_p_4(t_block_prntf *b)
{
	write(1, "0x", 2);
	b->r = b->r + 2;
	while (b->toch > 0)
	{
		ft_putchar('0');
		b->r++;
		b->toch--;
	}
}

void			ft_print_p_3(t_block_prntf *b, char *str, size_t len)
{
	write(1, "0x", 2);
	b->r = b->r + 2;
	b->wdth = b->wdth - (int)len - 2;
	while (b->wdth > 0)
	{
		ft_putchar('0');
		b->wdth--;
		b->r++;
	}
	if (*str != '0')
	{
		ft_putstr(str);
		b->r = b->r + (int)len;
	}
	free(str);
}

void			ft_print_p_2(t_block_prntf *b, char *str, size_t len)
{
	if (b->fl.z)
		ft_print_p_3(b, str, len);
	else
	{
		if (str[0] == '0' && len == 1)
			ft_print_p_4(b);
		else
		{
			b->wdth = b->wdth - (int)len - 2;
			while (b->wdth > 0)
			{
				ft_putchar(' ');
				b->wdth--;
				b->r++;
			}
			write(1, "0x", 2);
			b->r = b->r + (int)len + 1;
			if (*str != '0')
			{
				ft_putstr(str);
				b->r = b->r + (int)len;
			}
			free(str);
		}
	}
}

void			ft_print_p(t_block_prntf *b)
{
	size_t		len;
	char		*str;

	str = ft_lltoa_base(va_arg(b->ap, long long int), 16);
	len = ft_strlen(str);
	if (b->fl.m)
	{
		write(1, "0x", 2);
		ft_putstr(str);
		b->wdth = b->wdth - (int)len - 2;
		b->r = b->r + (int)len + 2;
		while (b->wdth > 0)
		{
			ft_putchar(' ');
			b->wdth--;
			b->r++;
		}
		free(str);
	}
	else
		ft_print_p_2(b, str, len);
}

void			ft_work_p(t_block_prntf *b, const char *format)
{
	int			i;

	i = b->i;
	while (format[i] != '%')
	{
		if (format[i] == '-')
			b->fl.m = 1;
		i--;
	}
	while (!(format[i] >= '1' && format[i] <= '9') && format[i] != b->mod)
	{
		if (format[i] == '0')
			b->fl.z = 1;
		i++;
	}
	b->wdth = ft_atoi(&format[i]);
	b->toch = ft_atoi(&format[i]);
	ft_print_p(b);
}
