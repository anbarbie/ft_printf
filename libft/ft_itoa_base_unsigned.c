/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:21:10 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/11 02:23:23 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static void		ft_fill_string(unsigned int n, int index, char *str, char *base)
{
	unsigned int base_len;

	base_len = (unsigned int)ft_strlen(base);
	if (n >= base_len)
		ft_fill_string(n / base_len, index - 1, str, base);
	str[index] = base[n % base_len];
}

char			*ft_itoa_base_unsigned(unsigned int n, char *base)
{
	char			*str;
	unsigned int	nbr;
	int				size;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	size = 1;
	nbr = n;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		size++;
	}
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	ft_fill_string(n, size - 1, str, base);
	return (str);
}
