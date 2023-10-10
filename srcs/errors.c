#include "../include/so_long.h"

void	ft_error_init(int n)
{
	if (n == 38)
		ft_printf("%s Error %n Check library compatibility! %n", COLOR_RED);
	if (n == 1)
		ft_printf("%s Error %n Operation not permitted ! %n", COLOR_RED);
	if (n == 2)
		ft_printf("%s Error %n No such file or directory ! %n", COLOR_RED);
	exit(n);
}

void ft_error_map(int n)
{
	if (n == 21)
		ft_printf("%s Error %n This is a directory. %n", COLOR_RED);
	else if (n == 22 || n == 59 || n == 24 || n == 5)
		ft_printf("%s Error %n Usage : ./so_long <filename>.ber %n", COLOR_RED);
	else if (n == 61)
		ft_printf("%s Error %n Try creating a valid map ! %n", COLOR_RED);
	exit(n);
}