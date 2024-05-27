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


void	redirection_operators(char **argv)
{
	int	process;

	process = 0;
	while (argv[process])
	{
		if (search_operator(argv, '|'))
			command_pipe(argv);
		// if (search_operator(argv, '>')) // ESSES AINDA VAO EXISTIR
		// 	command_bigger_then(argv);
		// if (search_operator(argv, '<'))
		// 	command_less_then(argv);

		process++;
	}
}
