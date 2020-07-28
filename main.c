/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:00:40 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/28 14:51:38 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\nreal : [%d]", printf("real : [%d]", 50) - 9);
	printf("\nfake : [%d]\n", ft_printf("fake : [%d]\n", 50) - 10);
	return (0);
}
