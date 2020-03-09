/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:07:29 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/09 13:48:06 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_conv_c(t_modulo *mod, int c)
{
	ft_fill_buff_c(mod, c);
	return (0);
}

int		ft_conv_s(t_modulo *mod, char *str)
{
	ft_fill_buff_s(mod, ft_strlen(str), str);
	return (0);
}

int		ft_conv_perc(t_modulo *mod)
{
	ft_fill_buff_c(mod, '%');
	return (0);
}
