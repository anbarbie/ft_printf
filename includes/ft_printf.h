/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:53:36 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/12 16:53:09 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct		s_flags
{
	bool		minus;
	bool		zero;
}					t_flags;

typedef struct		s_width
{
	int			padding;
	int			precision;
}					t_width;

typedef	struct		s_length
{
	bool		hh;
	bool		h;
	bool		ll;
	bool		l;
}					t_length;

typedef struct		s_type
{
	char		c;
}					t_type;

typedef struct		s_modulo
{
	char		buff[BUFFER_SIZE];
	int			fd;
	int			rt;
	size_t 		buff_index;
	t_flags		flags;
	t_width		width;
	t_length	length;
	t_type		type;
}					t_modulo;

void	ft_init_struct(t_modulo *mod);
int		ft_printf(char *format, ...);
int		ft_read_conv(char *str, t_modulo *mod, va_list args);
int		ft_write_full_buff(t_modulo *mod);
int		ft_fill_buff_c(t_modulo *mod, char c);
int		ft_fill_padding(t_modulo *mod, int n, char c);
void	ft_fill_buff_s(t_modulo *mod, int n, char *str);
int		ft_conv_c(t_modulo *mod, int c);
int		ft_conv_s(t_modulo *mod, char *str);
int		ft_conv_perc(t_modulo *mod);
int		ft_conv_int(t_modulo *mod, int n);
int		ft_conv_x(t_modulo *mod, unsigned int n, int hex);
int		ft_conv_u(t_modulo *mod, unsigned int n);
int		ft_conv_p(t_modulo *mod, uintptr_t *p);
char	*ft_parse_flags(char *str, t_modulo *mod);
char	*ft_parse_width(char *str, t_modulo *mod, va_list args);
char	*ft_parse_width_pad(char *str, t_modulo *mod, va_list args);
char	*ft_parse_length(char *str, t_modulo *mod);
char	*ft_parse_type(char *str, t_modulo *mod);

#endif