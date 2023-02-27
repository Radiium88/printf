#include "ft_printf.h"

int	strlenbase(char *base)
{
	int	i;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
		i++;
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int	cpt;

	if (!s)
		return (ft_putstr("(null)"));
	if (!strlenbase(s))
		return (0);
	cpt = 0;
	while (*s)
		cpt += ft_putchar(*s++);
	return (cpt);
}

int ft_nbrbase(int num, char *base)
{
	int		i;
	int		cpt;
	char	tab[16];

	i = 0;
	cpt = 0;
	if (num < 0)
	{
		cpt += ft_putchar('-');
		if (num == -2147483648)
		{
			tab[i++] = base[2147483648 % strlenbase(base)];
			num /= strlenbase(base);
		}
		num = -num;
	}
	while (num > 0 || i == 0)
	{
		tab[i++] = base[num % strlenbase(base)];
		num /= strlenbase(base);
	}
	while (i)
		cpt += ft_putchar(tab[--i]);
	return (cpt);
}

int u_nbr(unsigned int nbr, char *base)
{
	char	tab[16];
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while(nbr > 0 || i == 0)
	{
		tab[i++] = base[nbr % strlenbase(base)];
		nbr /= strlenbase(base);
	}
	while (i)
		cpt += ft_putchar(tab[--i]);
	return(cpt);
}