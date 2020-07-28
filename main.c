/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:00:40 by antbarbi          #+#    #+#             */
/*   Updated: 2020/07/28 15:26:53 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	ft_printf("%c\n", 'c');
	ft_printf("%s\n", "abc");
	ft_printf("%p\n", 50);
	ft_printf("%d\n", 39);
	ft_printf("%i\n", 38);
	ft_printf("%u\n", 10);
	ft_printf("%x\n", 16);
	ft_printf("%X\n", 16);
	ft_printf("%%\n");
	return (0);
}
