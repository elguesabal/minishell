#include "../minishell.h"

/* > */
/* >> */
/* | */
/* < */
/* << */


// int	count_pipe(char **argv)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i][0] == '|')
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

int	len_args_operators(char	**args) // AKI EU AINDA NAO TENHO FINALIDADE ENTAO TO MEIO SEM RUMO SE VOU CONTAR QUANTAS STRINGS DEVERIAM TER AO TOTAL OU QUANTAS STRINGS POR PROCESSO
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '|' && args[0][i])
				count++;
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

void	redirection_operators(char **argv)
{
	int	process;

	process = 0;
	while (argv[process])
	{
		if (search_pipe(argv))
			command_pipe(argv);
		process++;
	}
}
