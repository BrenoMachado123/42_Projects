/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:14:11 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:42:31 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ALLSYM "cspdiuxX%"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			star;
	int			prec;
	int			pos;
	int			len;
	int			neg;
	int			error;
	int			precerror;
	const char	*theformat;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_allcount(char input, va_list args, t_flags flags);
int		ft_pointer(unsigned long p, t_flags flag);
int		ft_str(char *str, t_flags flags);
int		ft_char(int c, t_flags flags);
void	ft_uputnbr_fd(unsigned int n, int fd);;
t_flags	ft_init_flags(const char *format);
t_flags	is_flag(int input, t_flags *flags, va_list args, int pos);
t_flags	ft_flag_minus(t_flags *flags);
t_flags	ft_flag_star(va_list args, t_flags *flags);
t_flags	ft_flag_digit(int c, t_flags *flags);
int		ft_int(int n, t_flags flag);
int		ft_unint_hexa(int input, unsigned int n, t_flags flags);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd, t_flags flag);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char const *str);
char	*ft_itoa(int nb);
char	*ft_u_itoa(unsigned int n);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_width(int width, int minus, int has_zero);
int		ft_flag_dot(const char *format, t_flags *flags, va_list args, int pos);
char	*ft_substr(char const *s, unsigned int start, size_t n);
int		ft_dot_str(char *str, t_flags *flag);
char	*ft_strdup(char const *s1);
int		ft_treat_dot_int(int n, t_flags flag);
char	*convert_nbr_chr(int n, t_flags *flag);
int		deal_negative(int n, t_flags *flags);
int		ft_dotpreczero(t_flags flag);
int		pointer_len(unsigned long p, t_flags *flags);
char	*ft_str_tolower(char *str);
int		ft_tolower(int c);
int		ft_isalpha(int c);
char	*ft_ul_base(unsigned long ull, int base);
int		ft_hexa(int input, unsigned int n, t_flags flags);
int		ft_unsigned(unsigned int n, t_flags flag);
int		deal_unsigned(unsigned int n, t_flags *flags);
int		ft_treat_dot_uint(unsigned int n, t_flags flag);
char	*convert_unbr_chr(int n, t_flags *flags);
int		deal_unsigned(unsigned int n, t_flags *flags);
int		ft_udotpreczero(t_flags flag);
int		ft_percent(t_flags flags);

#endif
