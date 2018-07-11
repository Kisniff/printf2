#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"

int	main(int argc, char **av)
{
	int v;

	v = 5;
	printf("%13.15p salut\n", &v);
	ft_printf("%18.15p salut", &v);
	(void)av;
	return (argc);
}