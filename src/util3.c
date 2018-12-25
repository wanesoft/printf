/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:56:57 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:59:06 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char							*ft_strupper(char *str)
{
	char						*new;
	int							i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		if (new[i] >= 97 && new[i] <= 122)
			new[i] = new[i] - 32;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

void							ft_okgug(unsigned long long int arr[2],
							t_block_prntf *b, long double d)
{
	if (arr[1] % 10 >= 5)
	{
		arr[1] = arr[1] / 10;
		arr[1]++;
	}
	else
		arr[1] = arr[1] / 10;
	if (b->toch == 0 && b->toch2)
	{
		arr[1] = (unsigned long long int)((d - arr[0]) * 10);
		if (arr[1] % 10 >= 5)
			arr[0]++;
		arr[1] = 0;
	}
}

int								ft_ulllen(unsigned long long int nb)
{
	int							i;

	i = 1;
	if (nb == 0)
		return (0);
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

unsigned long long int			ft_pow(int a, int b)
{
	unsigned long long int		a2;
	unsigned long long int		a3;

	if (b == 0)
		return (1);
	a2 = a;
	a3 = (unsigned long long int)a;
	while (b > 1)
	{
		a3 = a3 * a2;
		b--;
	}
	return (a3);
}
