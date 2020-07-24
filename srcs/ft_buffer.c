/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:52:38 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/24 16:10:04 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_write_full_buff(t_modulo *mod)
{
	if (mod->buff_index == BUFFER_SIZE)
	{
		if ((write(mod->fd, &mod->buff, mod->buff_index)) == -1)
			return (-1);
		mod->buff_index = 0;
	}
	return (1);
}

int		ft_fill_buff_c(t_modulo *mod, char c)
{
	if (ft_write_full_buff(mod) == -1)
		return (-1);
	mod->buff[mod->buff_index] = c;
	mod->buff_index++;
	mod->rt++;
	return (0);
}

int		ft_fill_padding(t_modulo *mod, int n, char c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_fill_buff_c(mod, c);
		i++;
	}
	return (0);
}

void	ft_fill_buff_s(t_modulo *mod, int n, char *str)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
	{
		if (mod->buff_index == BUFFER_SIZE)
			ft_write_full_buff(mod);
		mod->buff[mod->buff_index] = str[i];
		mod->buff_index++;
		mod->rt++;
		i++;
	}
}
