/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:27 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/09 14:39:50 by antbarbi         ###   ########.fr       */
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
	ft_fill_buff_s(mod, ft_strlen(str), str);
	return (0);
}

int		ft_conv_x(t_modulo *mod, unsigned int n, int hex)
{
	char	*str;

	if (hex == 0)
	{
		str = ft_itoa_base_unsigned(n, "0123456789abcdef");
	}
	else
	{
		str = ft_itoa_base_unsigned(n, "0123456789ABCEDF");
	}
	ft_fill_buff_s(mod, ft_strlen(str), str);
	return (0);
}

int		ft_conv_u(t_modulo *mod, unsigned int n)
{
	char	*str;

	str = ft_itoa_base_unsigned(n, "0123456789");
	ft_fill_buff_s(mod, ft_strlen(str), str);
	return (0);
}

int		ft_conv_p(t_modulo *mod, uintptr_t *p)
{
	char	*str;

	if (!(str = ft_itoa_base_addr((uintptr_t)p, "0123456789abcdef")))
		return (-1);
	ft_fill_buff_s(mod, ft_strlen(str), str);
	return (0);
}
