#include "../minishell.h"

void	argument_management(char **argv, t_str **env_list)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		/* '' */
		/* "" */
		/* $ */ argv[i] = new_environment_variable(argv[i], env_list);
		/* > */
		/* >> */
		/* | */
		/* < */
		/* << */

		i++;
	}
}
