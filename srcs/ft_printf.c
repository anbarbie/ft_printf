/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:51:15 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/12 13:31:40 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_init_struct(t_modulo *mod)
{
	mod->flags.minus = false;
	mod->flags.zero = false;
	mod->width.padding = 0;
	mod->width.precision = -1;
	mod->length.hh = false;
	mod->length.h = false;
	mod->length.ll = false;
	mod->length.l = false;
	mod->fd = 1;
}

int		ft_read_conv(char *str, t_modulo *mod, va_list args)
{
	if (mod->type.c == 'c')
		ft_conv_c(mod, va_arg(args, int));
	if (mod->type.c == 's')
		ft_conv_s(mod, va_arg(args, char*));
	if (mod->type.c == '%')
		ft_conv_perc(mod);
	if (mod->type.c == 'p')
		ft_conv_p(mod, va_arg(args, void*));
	if (mod->type.c == 'i' || mod->type.c == 'd')
		ft_conv_int(mod, va_arg(args, int));
	if (mod->type.c == 'u')
		ft_conv_u(mod, va_arg(args, unsigned int));
	if (mod->type.c == 'x')
		ft_conv_x(mod, va_arg(args, unsigned int), 0);
	if (mod->type.c == 'X')
		ft_conv_x(mod, va_arg(args, unsigned int), 1);
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list		args;
	t_modulo	mod;

	mod.buff_index = 0;
	va_start(args, format);
	while (*format)
	{
		ft_init_struct(&mod);
		if (*format == '%')
		{
			format++;
			format = ft_parse_flags(format, &mod);
			format = ft_parse_width(format, &mod, args);
			format = ft_parse_length(format, &mod);
			format = ft_parse_type((char *)format, &mod);
			ft_read_conv((char *)format, &mod, args);
		}
		else
			ft_fill_buff_c(&mod, *format);
		format++;
	}
	va_end(args);
	write(mod.fd, mod.buff, mod.buff_index);
	return (0);
}
