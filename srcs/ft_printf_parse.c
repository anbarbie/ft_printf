/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:37:05 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/28 15:06:11 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_flags(char *str, t_modulo *mod)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0')
			mod->flags.zero = true;
		if (*str == '-')
			mod->flags.minus = true;
		str++;
	}
	return (str);
}

char	*ft_parse_width_2(char *str, t_modulo *mod, va_list args)
{
	char	stock[11];
	int		i;

	i = 0;
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			mod->width.precision = va_arg(args, int);
			return (str + 1);
		}
		while (ft_isdigit(*str))
		{
			stock[i] = *str;
			i++;
			str++;
		}
		stock[i] = '\0';
		mod->width.precision = ft_atoi(stock);
	}
	return (str);
}

char	*ft_parse_width(char *str, t_modulo *mod, va_list args)
{
	char	stock[11];
	int		i;

	i = 0;
	if (*str == '*')
	{
		mod->width.padding = va_arg(args, int);
		if (mod->width.padding < 0)
		{
			mod->width.padding *= -1;
			mod->flags.minus = true;
		}
		str++;
	}
	else if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
			stock[i++] = *str++;
		stock[i] = '\0';
		mod->width.padding = ft_atoi(stock);
	}
	return (ft_parse_width_2(str, mod, args));
}

char	*ft_parse_type(char *str, t_modulo *mod)
{
	if (ft_strchr("cspdiuxX%%", *str))
		mod->type.c = *str;
	return (str);
}
