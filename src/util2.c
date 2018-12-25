/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:52:14 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:53:29 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_lltoa_base(long long int n, int base)
{
	char					*s;
	long long int			nb;
	int						len;

	len = 1;
	nb = n < 0 ? -(long long int)n : n;
	nb < 0 ? ++len : 0;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long long int)n : n;
	while (nb >= base)
	{
		s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 87;
		nb /= base;
	}
	s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 87;
	return (s);
}

char						*ft_ultoa_base(unsigned long n, int base)
{
	char					*s;
	unsigned long			nb;
	int						len;

	len = 1;
	nb = n;
	while (nb >= (unsigned)base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n >= (unsigned)base)
	{
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 87;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 87;
	return (s);
}

char						*ft_strdup(const char *s1)
{
	char					*s2;
	int						i;

	i = -1;
	while (s1[++i])
		;
	if (!(s2 = (char*)malloc(sizeof(*s2) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char						*ft_lltoa(long long int n)
{
	char					*s;
	long long int			nb;
	int						len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -(long long int)n : n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long long int)n : n;
	while (nb > 9)
	{
		s[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	s[--len] = nb + 48;
	return (s);
}

char						*ft_llutoa(unsigned long long int n)
{
	char					*s;
	unsigned long long int	nb;
	int						len;

	nb = n;
	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	nb = n;
	while (nb > 9)
	{
		s[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	s[--len] = nb + 48;
	return (s);
}
