#include "ft_printf.h"
#include <limits.h>


int	main(void)
{
	int taille;
	char *str;

	str = NULL;
	ft_printf("%x\n", 0);

	taille = ft_printf("%x\n", -1);
	ft_printf("Taille: %d\n", taille);

	taille = ft_printf("%s\n", str);
	ft_printf("Taille: %d\n", taille);
	// ft_printf("INT max: %x\n", INT_MAX);
	// ft_printf("INT Min %x\n", INT_MIN);

	return (0);
}