/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:08:00 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 16:05:29 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_s_3(t_block_prntf *b, char *str, size_t len, int i)
{
	if (b->toch)
		while (i < b->toch && str[i] != '\0')
		{
			ft_putchar(str[i]);
			b->r++;
			i++;
		}
	else if (!b->toch && b->toch2)
		ft_print_s_5(b, str);
	else
		while (i < (int)len && str[i] != '\0')
		{
			ft_putchar(str[i]);
			b->r++;
			i++;
		}
	if (!len)
	{
		len = ft_strlen(str);
		ft_putstr(str);
		b->r = b->r + (int)len;
	}
}

void		ft_print_s_2(t_block_prntf *b, char *str, size_t len)
{
	char	ws;
	int		i;

	i = 0;
	ws = ' ';
	if (b->fl.z)
		ws = '0';
	if ((int)len > b->toch)
		if (b->toch)
			len = b->toch;
	b->wdth = b->wdth - (int)len;
	while (b->wdth > 0)
	{
		ft_putchar(ws);
		b->wdth--;
		b->r++;
	}
	ft_print_s_3(b, str, len, i);
}

void		ft_print_s(t_block_prntf *b, char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (b->fl.m)
	{
		ft_print_s_4(b, str, len, i);
		while (b->wdth > 0)
		{
			ft_putchar(' ');
			b->wdth--;
			b->r++;
		}
	}
	else
		ft_print_s_2(b, str, len);
}

void		ft_work_s_2(t_block_prntf *b, const char *format, int i)
{
	char	*str;

	str = va_arg(b->ap, char *);
	if (!str)
		str = "(null)";
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
	ft_print_s(b, str);
}

void		ft_work_s(t_block_prntf *b, const char *format)
{
	int		i;

	i = b->i;
	while (format[i] != '%')
	{
		if (format[i] == '-')
			b->fl.m = 1;
		if (format[i] == '.')
			b->toch = 1;
		if (format[i] == '.')
			b->toch2 = 1;
		i--;
	}
	while (!(format[i] >= '1' && format[i] <= '9')
			&& format[i] != b->mod && format[i] != '.')
	{
		if (format[i] == '0')
			b->fl.z = 1;
		i++;
	}
	ft_work_s_2(b, format, i);
}
