#include "../minishell.h"

void	argument_management(char **argv, t_str **env_list)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		/* '' */
		/* "" */
		/* $ */ argv[i] = environment_variable(argv[i], env_list);
		/* > */
		/* >> */
		/* | */ // VC AGR FDP
		/* < */
		/* << */

		i++;
	}

	// if (search_pipe(argv))
	// 	command_pipe(argv);


}
