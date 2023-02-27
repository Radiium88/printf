#include "ft_printf.h"
#define FLAG "cspdiuxX%"

int mem_add(unsigned long int *num, char *base)
{
	int					i;
	int					cpt;
	char				tab[16];
	unsigned long int	nbr;

	if (!num)
		return (ft_putstr("(nil)"));
	i = 0;
	cpt = 0;
	nbr = (size_t) num;
	cpt += ft_putstr("0x");
	while (nbr > 0)
	{
		tab[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i)
		cpt += ft_putchar(tab[--i]);
	return (cpt);
}

int is_condition(char c)
{
	int	i;

	i = -1;
	while (FLAG[++i])
		if (FLAG[i] == c)
			return (1);
	return (0);
}

int	condition(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (mem_add(va_arg(arg, void *), "0123456789abcdef"));
	if (c == 'd')
		return (ft_nbrbase(va_arg(arg, int), "0123456789"));
	if (c == 'i')
		return (ft_nbrbase(va_arg(arg, int), "0123456789"));
	if (c == 'u')
		return (u_nbr(va_arg(arg, unsigned int), "0123456789"));
	if (c == 'x')
		return (u_nbr(va_arg(arg, int), "0123456789abcdef"));
	if (c == 'X')
		return (u_nbr(va_arg(arg, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}
/*on parcours et imprime la chaine a la recherche de % suivie d'un argument.
si l'argument correspond a l'une des conditions on applique celle ci
puis on continue d'imprimer la chaine.
on enregistre aussi le nombre de charactere passé et on le retourne*/
int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int	i;
	int	cpt;

	va_start(arg, str);
	i = -1;
	cpt = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] && is_condition(str[i + 1]))
			cpt += condition(str[i++ + 1], arg);
		else
			cpt += ft_putchar(str[i]);
	}
	return (cpt);
}
