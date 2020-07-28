/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:29 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/28 15:06:23 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(t_modulo *mod, int c)
{
	if (mod->flags.minus == true)
	{
		ft_fill_buff_c(mod, c);
		ft_fill_padding(mod, mod->width.padding - 1, ' ');
	}
	else
	{
		ft_fill_padding(mod, mod->width.padding - 1, ' ');
		ft_fill_buff_c(mod, c);
	}
	return (0);
}

int		ft_conv_s(t_modulo *mod, char *str)
{
	int		len;
	char	*null;

	null = "(null)";
	if (!(str))
		str = null;
	if (mod->width.precision < (int)ft_strlen(str) && mod->width.precision >= 0)
		len = mod->width.precision;
	else
		len = ft_strlen(str);
	if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, len, str);
		ft_handle_str(mod, len);
	}
	else
	{
		ft_handle_str(mod, len);
		ft_fill_buff_s(mod, len, str);
	}
	return (0);
}

int		ft_conv_perc(t_modulo *mod)
{
	if (mod->flags.minus == false)
	{
		if (mod->flags.zero == true)
			ft_fill_padding(mod, mod->width.padding - 1, '0');
		else
			ft_fill_padding(mod, mod->width.padding - 1, ' ');
		ft_fill_buff_c(mod, '%');
	}
	else
	{
		ft_fill_buff_c(mod, '%');
		ft_fill_padding(mod, mod->width.padding - 1, ' ');
	}
	return (0);
}
