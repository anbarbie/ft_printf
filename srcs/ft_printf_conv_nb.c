/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:27 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/27 15:09:04 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_conv_int(t_modulo *mod, int n)
{
	char			*str;
	int				len;
	int				neg;
	unsigned int	nbr;

	neg = 0;
	if (n < 0)
	{
		nbr = -n;
		neg = 1;
	}
	else
		nbr = n;
	if (!(str = ft_itoa((long)nbr)))
		return (-1);
	if (mod->width.precision == 0 && str[0] == '0')
		len = 0;
	else
		len = ft_strlen(str);
	ft_handle_int(mod, str, len, neg);
	free(str);
	return (0);
}

int		ft_conv_x(t_modulo *mod, unsigned int n, int hex)
{
	char	*str;
	int		len;

	if (hex == 0)
		str = ft_itoa_base_unsigned(n, "0123456789abcdef");
	else
		str = ft_itoa_base_unsigned(n, "0123456789ABCDEF");
	if (!(str))
		return (-1);
	if (mod->width.precision == 0 && n == 0)
		len = 0;
	else
		len = ft_strlen(str);
	ft_handle_padding(mod, str, len);
	free(str);
	return (0);
}

int		ft_conv_u(t_modulo *mod, unsigned int n)
{
	char	*str;
	int		len;

	if (!(str = ft_itoa_base_unsigned(n, "0123456789")))
		return (-1);
	if (mod->width.precision == 0 && n == 0)
		len  = 0;
	else
		len = ft_strlen(str);
	ft_handle_padding(mod, str, len);
	free(str);
	return (0);
}

int		ft_conv_p(t_modulo *mod, uintptr_t *p)
{
	char	*str;
	int		len;

	if (!(str = ft_itoa_base_addr((uintptr_t)p, "0123456789abcdef")))
		return (-1);
	len = ft_strlen(str) + 2;
	if (!p && mod->width.precision == 0)
		len -= 1;
	if (mod->flags.minus == true)
	{
		ft_fill_buff_s(mod, 2, "0x");
		if (!(!p && mod->width.precision == 0))
			ft_fill_buff_s(mod, len, str);
		ft_handle_padding2(mod, len);
	}
	else
	{
		ft_handle_padding2(mod, len);
		ft_fill_buff_s(mod, 2, "0x");
		if (!(!p && mod->width.precision == 0))
			ft_fill_buff_s(mod, len, str);
	}
	return (0);
}
