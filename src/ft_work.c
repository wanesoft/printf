/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:45 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:06:47 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_work_3(t_block_prntf *b, const char *format)
{
	int		i;

	b->i++;
	i = b->i;
	while ((format[i] >= '0' && format[i] <= '9') && format[i] != '\0')
		i++;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		b->r++;
		b->i++;
		i++;
	}
	b->i++;
}

void		ft_work_2(t_block_prntf *b, const char *format, int i)
{
	while ((format[i] >= '1' && format[i] <= '9') && format[i] != '\0')
		i++;
	ft_putchar(format[i]);
	b->r++;
	b->i = i + 1;
	b->wdth--;
	while (b->wdth > 0)
	{
		ft_putchar(' ');
		b->r++;
		b->wdth--;
	}
	i++;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		b->r++;
		b->i++;
		i++;
	}
}

void		ft_work_4(t_block_prntf *b, const char *format)
{
	while (format[b->i] == ' ')
		b->i++;
	while (format[b->i] != '\0')
	{
		ft_putchar(format[b->i]);
		b->r++;
		b->i++;
	}
}

void		ft_work_5(t_block_prntf *b, const char *format)
{
	b->wdth--;
	while (b->wdth > 0)
	{
		ft_putchar(' ');
		b->r++;
		b->wdth--;
	}
	b->i++;
	ft_putchar(format[b->i]);
	b->r++;
	b->i++;
}

void		ft_work(t_block_prntf *b, const char *format)
{
	int		i;

	i = b->i;
	while (!(format[i] >= '1' && format[i] <= '9') && format[i] != '\0')
		i++;
	b->wdth = ft_atoi(&format[i]);
	if (format[b->i] == '-')
		ft_work_2(b, format, i);
	else if (format[b->i] == '.')
		ft_work_3(b, format);
	else if (format[b->i] == ' ')
		ft_work_4(b, format);
	else
		ft_work_5(b, format);
}
