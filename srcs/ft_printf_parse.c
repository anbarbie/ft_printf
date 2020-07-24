/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:37:05 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/24 16:09:32 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_parse_flags(char *str, t_modulo *mod)
{
	int		priority;

	priority = false;
	while (*str == '0' || *str == '-')
	{
		if (*str == '0' && priority == false)
			mod->flags.zero = true;
		if (*str == '-')
		{
			mod->flags.zero = false;
			mod->flags.minus = true;
			priority = true;
		}
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
		str++;
	}
	else if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
		{
			stock[i] = *str;
			i++;
			str++;
		}
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
