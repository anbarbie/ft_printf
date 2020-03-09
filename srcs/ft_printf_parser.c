/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:03:06 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/09 14:35:19 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char	*ft_parse_flags(char *str, t_modulo *mod)
{
	while (*str)
	{
		if (*str == '0' || *str == '-')
		{
			if (*str == '-')
				mod->flags.minus = 1;
			if (*str == '0')
				mod->flags.zero = 1;
		}
		str++;
	}
	return (str);
}

char	*ft_parse_width(char *str, t_modulo *mod, va_list args)
{
	char	tmp[11];
	int		i;

	i = 0;
	if (*str == '*')
	{
		mod->width.padding = va_arg(args, int);
		if (mod->width.padding < 0)
		{
			mod->width.padding *= -1;
			mod->flags.minus = 1;
		}
		str++;
	}
	else if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
		{
			tmp[i] = *str;
			i++;
			str++;
		}
		tmp[i] = '\0';
		mod->width.padding = ft_atoi(tmp);
	}
	if (*str == '.')
	{
		i = 0;
		str++;
		if (*str == '*')
		{
			mod->width.precision = va_arg(args, int);
			return (str + 1);
		}
		while (ft_isdigit(*str))
		{
			tmp[i] = *str;
			str++;
			i++;
		}
		tmp[i] = '\0';
		mod->width.precision = ft_atoi(tmp);
	}
	return (str);
}

char	*ft_parse_length(char *str, t_modulo *mod)
{
	if (*str == 'h')
	{
		if (*str + 1 == 'h')
		{
			mod->length.hh = 1;
			str++;
		}
		else
			mod->length.h = 1;
		str++;
	}
	else if (*str == 'l')
	{
		if (*str + 1 == 'l')
		{
			mod->length.ll = 1;
			str++;
		}
		else
			mod->length.l = 1;
		str++;
	}
	return (str);
}

char	*ft_parse_type(char *str, t_modulo *mod)
{
	static char *tmp = "cspdiuxX%";

	if (ft_strchr(tmp, *str))
		mod->type.c = *str;
	return (str);
}
