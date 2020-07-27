/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:00:40 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/27 15:34:37 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\nreal : [%d]", printf("real : [%.5p]", 0) - 9);
	printf("\nfake : [%d]\n", ft_printf("fake : [%.5p]\n", 0) - 10);
	return (0);
}
