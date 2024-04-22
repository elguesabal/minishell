#include "../minishell.h"

/// @brief LIBERA A MEMORIA DE UM PONTEIRO PARA PONTEIRO
/// @param ptr PONTEIRO PARA PONTEIRO A SER LIBERADO
void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_shell(char **argv, char *str, char **env, t_str **env_list)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (argv)
	{
		free_split(argv);
		argv = NULL;
	}
	// if (env)	// O ARRAY DE PONTEIRO **env E COMPOSTO APENAS POR STRINGS Q TEM O MESMO ENDERECO DE **env_list
	// {
	// 	free_split(env);
	// 	env = NULL;
	// }
	free(env); // ENTAO NESSE CASO EU SO USO free() NO PONTEIRO Q REUNE AS STRINGS
	free_list(env_list);
	exit(0);
}
