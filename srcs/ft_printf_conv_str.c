/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:29 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/07 15:02:45 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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
	int len;

	if (mod->width.precision < (int)ft_strlen(str) && mod->width.precision >= 0)
		len = mod->width.precision;
	else
		len = ft_strlen(str);
	ft_fill_buff_s(mod, len, str);
	return (0);
}

int		ft_conv_perc(t_modulo *mod)
{
	ft_fill_buff_c(mod, '%');
	return (0);
}
