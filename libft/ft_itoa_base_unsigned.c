/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:21:10 by antbarbi          #+#    #+#             */
/*   Updated: 2020/03/09 12:48:18 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_str(unsigned int nb, int index, char *str, char *base)
{
	int		len_base;

	len_base = (unsigned int)ft_strlen(base);
	if (nb >= len_base)
		ft_fill_str(nb / len_base, index - 1, str, base);
	str[index] = base[nb % len_base];
}

char			*ft_itoa_base_unsigned(unsigned int n, char *base)
{
	unsigned int	nb;
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
	ft_fill_str(n < 0 ? -nb : nb, size - 1, str, base);
	if (n < 0)
		str[0] = '-';
	return (str);
}
