#include "../minishell.h"

char	*copy_str(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	while (str[i])
		i++;
	str2 = malloc((i + 1) * sizeof(char));
	if (str2)
	{
		str2[i] = '\0';
		while (i)
		{
			i--;
			str2[i] = str[i];
		}
	}
	return (str2);
}

char	**copy_str_str(char	**env)
{
	char	**copy;
	int	i;

	copy = malloc((strstrlen(env) + 1) * sizeof(char *));
	if (copy == NULL)
	{
		printf("Error: a funcao malloc() retornou NULL\n");
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		copy[i] = copy_str(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
