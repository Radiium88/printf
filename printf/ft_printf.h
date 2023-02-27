
#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	condition(char c, va_list arg);

int is_condition(char c);

int mem_add(unsigned long int *num, char *base);

int ft_nbrbase(int num, char *base);

int ft_putstr(char *s);

int ft_putchar(char c);

int	strlenbase(char *base);

int u_nbr(unsigned int nbr, char *base);

#endif
