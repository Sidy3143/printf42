#include "ft_printf.h"

int main(void)
{
    int taille;

    taille = ft_printf("i'm just printing %%.\n");
    ft_printf("Taille: %i\n", taille);
    return (0);
}