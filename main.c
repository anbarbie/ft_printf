/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:00:40 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/24 15:53:19 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\nreal : [%d]", printf("real : [%.6i]", -3) - 9);
	printf("\nfake : [%d]\n", ft_printf("fake : [%.6i]\n", -3) - 10);
	return (0);
}
