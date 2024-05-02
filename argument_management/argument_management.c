#include "../minishell.h"

void	argument_management(char **argv, t_str **env_list)
{
	int	i;

	i = 1; // TEM Q COMECAR A VERIFICAR APARTIR DO SEGUNDO ARGUMENTO PQ O PRIMEIRO E O COMANDO
	while (argv[i])
	{
		/* '' */
		/* "" */
		/* $ */ argv[i] = environment_variable(argv[i], env_list);
		/* > */
		/* >> */
		/* | */
		/* < */
		/* << */

		i++;
	}
}
