#include "../minishell.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
	{
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
