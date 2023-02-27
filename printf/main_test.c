#define couleur(param) printf("\033[%dm", param);
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf.h"

static char	*strdupm(char const *s, int start, int end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i++] = s[start++];
	}
	dest[i] = 0;
	return (dest);
}

static int	count_word(const char *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		start;
	int		i;
	int		j;

	tab = (char **) malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
				i++;
		start = i;
		while (s[i] != c && s[i])
				i++;
		if (start != i)
			tab[j++] = strdupm(s, start, i);
	}
	tab[j] = 0;
	return (tab);
}

void	testlen(int pf_len, int ft_len)
{
	if (pf_len != ft_len)
			{
				couleur(31);
				couleur(5);
			}
			printf("pf_len = %d\nft_len = %d\n",pf_len,ft_len);
			couleur(32);
}

int main()
{
	char	**tab;
	char	c;
	/*char 	*null = NULL;*/
	char	*s;
	int i;
	int	pf_len;
	int ft_len;

	s = malloc(sizeof(char) * 101);
	s = "0 -1 9 10 11 99 100 101 -9 -11 -99 -100 -101 2147483647 -2147483648 4294967295 9223372036854775807LL";
	tab = ft_split(s, ' ');
	i = 0;
	while (tab[i])
	{
		couleur(32); 
		pf_len = printf("%d\n",atoi(tab[i])) - 1;
		ft_len = ft_printf("%d\n",atoi(tab[i])) - 1;
		testlen(pf_len, ft_len);
		ft_printf("test %%d\n\n");
		i++;
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%s\n",tab[i]) - 1;
			ft_len = ft_printf("%s\n",tab[i]) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%s\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%p\n",tab[i]) - 1;
			ft_len = ft_printf("%p\n",tab[i]) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%p\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%i\n",atoi(tab[i])) - 1;
			ft_len = ft_printf("%i\n",atoi(tab[i])) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%i\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%u\n",atoi(tab[i])) - 1;
			ft_len = ft_printf("%u\n",atoi(tab[i])) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%u\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%x\n",atoi(tab[i])) - 1;
			ft_len = ft_printf("%x\n",atoi(tab[i])) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%x\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		i = 0;
		while (tab[i])
		{
			couleur(32);
			pf_len = printf("%X\n",atoi(tab[i])) - 1;
			ft_len = ft_printf("%X\n",atoi(tab[i])) - 1;
			testlen(pf_len, ft_len);
			ft_printf("test %%X\n\n");
			i++;
		}
	}
	couleur(0);
	printf("\t\t\ttest suivant press enter:\n");
	scanf("%c", &c);
	if (c == '\n')
	{
		couleur(32);
		pf_len = printf("%c\n",'0') -1;
		ft_len = printf("%c\n",'0') -1;
		testlen(pf_len, ft_len);
		ft_printf("test %%c\n\n");
		pf_len = printf("%c\n",0);
		ft_len = printf("%c\n",0);
		testlen(pf_len, ft_len);
		ft_printf("test %%c\n\n");
		pf_len = printf("%c%c%c\n",0, '1', '2');
		ft_len = printf("%c%c%c\n",0, '1', '2');
		testlen(pf_len, ft_len);
		ft_printf("test %%c\n\n");
		pf_len = printf("%c%c%c\n",'0', 0, '2');
		ft_len = printf("%c%c%c\n",'0', 0, '2');
		testlen(pf_len, ft_len);
		ft_printf("test %%c\n\n");
		pf_len = printf("%c%c%c\n",'0', '1', 0);
		ft_len = printf("%c%c%c\n",'0', '1', 0);
		testlen(pf_len, ft_len);
		ft_printf("test %%c\n\n");
	}
	return(0) ;
}