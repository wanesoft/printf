/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:59:25 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 16:03:33 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_putstr(char *str)
{
	unsigned long long int	ii;

	ii = (unsigned long long int)str;
	if (ii < 10)
		return ;
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void						ft_putchar(char c)
{
	write(1, &c, 1);
}

char						*ft_strchr(const char *s, int c)
{
	char					*tmp;

	while (*s)
	{
		if (*s == c)
		{
			tmp = (char*)s;
			return (tmp);
		}
		s++;
	}
	if (c == '\0')
	{
		tmp = (char*)s;
		return (tmp);
	}
	return (NULL);
}

int							ft_atoi(const char *s)
{
	int						res;
	int						np;

	np = 1;
	res = 0;
	while (*s == '\t' || *s == '\v' || *s == '\f' ||
			*s == '\r' || *s == '\n' || *s == ' ')
		s++;
	if (*s == '-')
	{
		np = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	return (res *= np);
}

size_t						ft_strlen(const char *s)
{
	size_t					i;
	unsigned long long int	ii;

	ii = (unsigned long long int)s;
	i = 0;
	if (!s || ii < 10)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
