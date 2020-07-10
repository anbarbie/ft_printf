/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:20:21 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/11 01:43:39 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_str(uintptr_t nb, int index, char *str, char *base)
{
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	if (nb >= len_base)
		ft_fill_str(nb / len_base, index - 1, str, base);
	str[index] = base[nb % len_base];
}

char			*ft_itoa_base_addr(uintptr_t n, char *base)
{
	uintptr_t		nb;
	char			*str;
	unsigned int	size;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	size = 1;
	nb = n;
	while (n >= len_base)
	{
		n /= len_base;
		size++;
	}
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	ft_fill_str(nb, size - 1, str, base);
	return (str);
}
