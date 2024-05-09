#include "../minishell.h"

static int	ft_size(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i + sign);
}

static int	ft_sign(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		aux;

	aux = n;
	i = ft_size(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			str[i] = '-';
		else
		{
			str[i] = ft_sign(aux % 10) + 48;
			aux = aux / 10;
		}
		i--;
	}
	str[ft_size(n)] = '\0';
	return (str);
}
