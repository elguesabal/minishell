#include "../minishell.h"

void	pwd(t_str **env_list)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
		variable_status(0, env_list);
	}
	else
		printf("Error\na funcao getcwp() retornou NULL\n");
}
