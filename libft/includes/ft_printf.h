/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:54:10 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/19 23:25:28 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <locale.h>
# include <inttypes.h>
# include "./libft.h"
# define HEXA_MIN "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define BASE_8 "01234567"
# define BASE_2 "01"

# define MOD modi->mod
# define FLAG modi->flag
# define PLUS modi->plus
# define MINUS modi->minus
# define SHARP modi->sharp
# define SPACE modi->space
# define ZERO modi->zero
# define PRECI modi->preci
# define DIGIT modi->digit
# define PERIOD modi->period
# define CAP modi->cap
# define NEG modi->neg

typedef struct	s_modifiers
{
	int			mod;
	int			flag;
	int			plus;
	int			minus;
	int			sharp;
	int			space;
	int			zero;
	int			preci;
	int			digit;
	int			period;
	int			cap;
	int			percent;
	int			hexa;
	int			neg;
}				t_modif;

int				ft_printf(const char *format, ...);
int				parse(va_list argl, const char *format);
void			search_mod(const char *format, int i, t_modif *modi);
void			search_flag(const char *format, int i, t_modif *modi);
int				search_digit(va_list argl, const char *format,
					int i, t_modif *modi);
int				search_period(va_list argl, const char *format,
					int i, t_modif *modi);
int				search_percent(const char *format, int i, t_modif *modi);
char			*itoa_base(uintmax_t n, char *base);
char			*ft_strchr(const char *str, int c);
int				ft_putwchar(wchar_t value);
char			*ft_strdup(const char *s1);
void			ft_putnbr_base(uintmax_t nb, char *base);
int				get_intlen(intmax_t nb);
int				get_uintlen(uintmax_t nb, char *base);
int				get_intlen(intmax_t nb);
int				get_charlen(char c);
int				get_strlen(char *str);
int				get_wstrlen(wchar_t *wstr);
int				get_preciw(wchar_t *wstr, int n);
int				get_octlen(uintmax_t nb);
void			ft_putnstr(const char *s, size_t n);
int				ft_putwstr(wchar_t *wstr);
int				ft_putwnstr(wchar_t *wstr, int n);
int				ft_countbits(wchar_t value);
intmax_t		lenght_mod(va_list argl, t_modif *modi);
uintmax_t		ulenght_mod(va_list argl, t_modif *modi);
size_t			handle_s(va_list argl, t_modif *modi);
int				handle_d(va_list argl, t_modif *modi);
int				handle_x(va_list argl, t_modif *modi);
int				handle_p(va_list argl, t_modif *modi);
int				handle_o(va_list argl, t_modif *modi);
int				handle_u(va_list argl, t_modif *modi);
int				handle_c(va_list argl, t_modif *modi);
int				handle_bd(t_modif *modi, char c);
void			width_errors(t_modif *modi, int nblen);
void			width_errs(t_modif *modi, int sblen);
int				apply_flags(t_modif *modi);
int				apply_digits(t_modif *modi);
int				apply_preci(t_modif *modi);
int				minus_spec(t_modif *modi, uintmax_t nb);
int				padding(int dig, char p);
size_t			paddingchar(size_t dig, char p);
void			init_all();
void			free_all(t_modif *modi);
uintmax_t		to_unsigned_char_modulo(uintmax_t nbr);
size_t			handle_b(va_list argl, t_modif *modi);
int				period_zero(uintmax_t nb, t_modif *modi);
int				char_before_next_percent(const char *str, int index);

#endif
