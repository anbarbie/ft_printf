/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:53:36 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/28 14:54:35 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_handle_padding2(t_modulo *mod, int len)
{
	if (mod->width.precision > len)
		len = mod->width.precision;
	if (mod->flags.zero == true)
	{
		if (mod->width.precision >= 0 || mod->flags.minus == true)
			ft_fill_padding(mod, mod->width.padding - len, ' ');
		else
			ft_fill_padding(mod, mod->width.padding - len, '0');
	}
	else
		ft_fill_padding(mod, mod->width.padding - len, ' ');
}

void	ft_handle_padding(t_modulo *mod, char *str, int len)
{
	if (mod->flags.minus == true)
	{
		ft_fill_padding(mod, mod->width.precision - len, '0');
		ft_fill_buff_s(mod, len, str);
		ft_handle_padding2(mod, len);
	}
	else
	{
		ft_handle_padding2(mod, len);
		ft_fill_padding(mod, mod->width.precision - len, '0');
		ft_fill_buff_s(mod, len, str);
	}
}

void	ft_handle_str(t_modulo *mod, int len)
{
	if (mod->flags.zero == true)
	{
		if (mod->flags.minus == true)
			ft_fill_padding(mod, mod->width.padding - len, ' ');
		else
			ft_fill_padding(mod, mod->width.padding - len, '0');
	}
	else
		ft_fill_padding(mod, mod->width.padding - len, ' ');
}

void	ft_handle_buff_padding_int(t_modulo *mod, int len, int negative)
{
	if (mod->width.precision > len)
		len = mod->width.precision;
	if (negative == 1)
		len += 1;
	if (mod->flags.zero == true)
	{
		if (mod->width.precision >= 0 || mod->flags.minus == true)
			ft_fill_padding(mod, mod->width.padding - len, ' ');
		else
			ft_fill_padding(mod, mod->width.padding - len, '0');
	}
	else
		ft_fill_padding(mod, mod->width.padding - len, ' ');
}

void	ft_handle_int(t_modulo *mod, char *str, int len, int neg)
{
	if (mod->flags.minus == false)
	{
		if (neg == 1 && mod->width.precision < 0
				&& mod->flags.zero == true)
			ft_fill_buff_c(mod, '-');
		ft_handle_buff_padding_int(mod, len, neg);
		if ((neg == 1 && mod->width.precision >= 0)
				|| (neg == 1 && mod->flags.zero == false))
			ft_fill_buff_c(mod, '-');
		ft_fill_padding(mod, mod->width.precision - len, '0');
		ft_fill_buff_s(mod, len, str);
	}
	else
	{
		if (neg == 1)
			ft_fill_buff_c(mod, '-');
		ft_fill_padding(mod, mod->width.precision - len, '0');
		ft_fill_buff_s(mod, len, str);
		ft_handle_buff_padding_int(mod, len, neg);
	}
}
