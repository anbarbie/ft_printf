/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:27 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/11 02:13:02 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

#include <stdio.h>

int		ft_conv_int(t_modulo *mod, int n)
{
	char	*str;

	if (!(str = ft_itoa(n)))
		return (-1);
	if (mod->width.precision == 0 && n == 0)
		return (0);
	if (mod->width.precision > (int)ft_strlen(str))
	{
		ft_fill_padding(mod, mod->width.precision - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);	
	}
	else if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, ft_strlen(str), str);
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
	}
	else if (mod->flags.zero == true)
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	else
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	return (0);
}

int		ft_conv_x(t_modulo *mod, unsigned int n, int hex)
{
	char	*str;

	if (hex == 0)
		str = ft_itoa_base_unsigned(n, "0123456789abcdef");
	else
		str = ft_itoa_base_unsigned(n, "0123456789ABCEDF");
	if (!(str))
		return (-1);
	if (mod->width.precision == 0 && n == 0)
		return (0);
	if (mod->width.precision > (int)ft_strlen(str))
	{
		ft_fill_padding(mod, mod->width.precision - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);	
	}
	else if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, ft_strlen(str), str);
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
	}
	else if (mod->flags.zero == true)
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	else
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	return (0);
}

int		ft_conv_u(t_modulo *mod, unsigned int n)
{
	char	*str;

	if (!(str = ft_itoa_base_unsigned(n, "0123456789")))
		return (-1);
	if (mod->width.precision == 0 && n == 0)
		return (0);
	if (mod->width.precision > (int)ft_strlen(str))
	{
		ft_fill_padding(mod, mod->width.precision - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);	
	}
	else if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, ft_strlen(str), str);
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
	}
	else if (mod->flags.zero == true)
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	else
	{
		ft_fill_padding(mod, mod->width.padding - (int)ft_strlen(str), ' ');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	return (0);
}

int		ft_conv_p(t_modulo *mod, uintptr_t *p)
{
	char	*str;
	int		len;

	if (!(str = ft_itoa_base_addr((uintptr_t)p, "0123456789abcdef")))
		return (-1);
	len = ft_strlen(str) + 2;
	if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, 2, "0x");
		ft_fill_buff_s(mod, ft_strlen(str), str);
		ft_fill_padding(mod, mod->width.padding - len, ' ');
	}
	else if (mod->flags.zero == true)
	{
		ft_fill_buff_s(mod, 2, "0x");
		ft_fill_padding(mod, mod->width.padding - len, '0');
		ft_fill_buff_s(mod, ft_strlen(str), str);
	}
	else
	{		
		ft_fill_padding(mod, mod->width.padding - len, ' ');
		ft_fill_buff_s(mod, 2, "0x");
		ft_fill_buff_s(mod, ft_strlen(str), str);			
	}
	return (0);
}
