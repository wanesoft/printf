/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:10 by draynor           #+#    #+#             */
/*   Updated: 2018/12/25 15:25:13 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <inttypes.h>
# include <wchar.h>
# include <wctype.h>

# define D_MODS "cCsSpPdDiIuUxXoOfF"

typedef struct			s_flag
{
	char				h;
	char				z;
	char				w;
	char				m;
	char				p;
}						t_flag;

typedef struct			s_size
{
	char				h;
	char				hh;
	char				l;
	char				ll;
	char				b;
	char				j;
}						t_size;

typedef struct			s_block_prntf
{
	va_list				ap;
	t_flag				fl;
	int					wdth;
	int					toch;
	int					toch2;
	t_size				sz;
	char				mod;
	int					i;
	int					r;
}						t_block_prntf;

int						ft_printf(const char *format, ...);

void					ft_work_c(t_block_prntf *b, const char *format);
void					ft_print_s_4(t_block_prntf *b, char *str,
		size_t len, int i);
void					ft_print_s_5(t_block_prntf *b, char *str);
void					ft_work_s(t_block_prntf *b, const char *format);
void					ft_work_p(t_block_prntf *b, const char *format);
void					ft_work_d_i(t_block_prntf *b, const char *format);
void					ft_print_d_i_2(t_block_prntf *b, char *str, int len);
void					ft_print_d_i_3(t_block_prntf *b, char *str, int len);
void					ft_work(t_block_prntf *b, const char *format);
void					ft_work_u(t_block_prntf *b, const char *format);
void					ft_print_u_2(t_block_prntf *b, char *str, int len);
void					ft_print_u_3(t_block_prntf *b, char *str, int len);
void					ft_work_x(t_block_prntf *b, const char *format);
void					ft_print_x_2(t_block_prntf *b, char *str, int len);
void					ft_print_x_3(t_block_prntf *b, char *str, int len);
void					ft_work_o(t_block_prntf *b, const char *format);
void					ft_print_o_2(t_block_prntf *b, char *str, int len);
void					ft_print_o_3(t_block_prntf *b, char *str, int len);
void					ft_work_f(t_block_prntf *b, const char *format);
void					ft_parse_f(long double d, t_block_prntf *b);

void					ft_putstr(char *str);
void					ft_putnbr(int i);
void					ft_putchar(char c);
char					*ft_strchr(const char *s, int c);
int						ft_atoi(const char *s);
size_t					ft_strlen(const char *s);
char					*ft_lltoa_base(long long int n, int base);
char					*ft_lltoa(long long int n);
char					*ft_llutoa(unsigned long long int n);
char					*ft_ultoa_base(unsigned long n, int base);
char					*ft_strupper(char *str);
void					ft_okgug(unsigned long long int arr[2],
		t_block_prntf *b, long double d);
int						ft_ulllen(unsigned long long int nb);
unsigned long long int	ft_pow(int a, int b);

#endif
