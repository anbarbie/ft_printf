#include "./includes/ft_printf.h"
#include "./libft/libft.h"

int	main()
{
	printf("real [%05p]\n", 50);
	ft_printf("fake [%05p]\n", 50);
	return (0);
}
