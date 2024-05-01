#include "../minishell.h"

char	*new_pwd(char *pwd)
{
	char	*variable;
	int	i;

	variable = malloc((ft_strlen(pwd) + 5) * sizeof(char));
	if (variable == NULL)
		return NULL;
	variable[0] = 'P';
	variable[1] = 'W';
	variable[2] = 'D';
	variable[3] = '=';
	i = 4;
	while (*pwd)
	{
		variable[i] = *pwd;
		pwd++;
		i++;
	}
	variable[i] = '\0';
	return (variable);
}

void    cd(char *command, char **env, t_str **env_list) // DESSE MODO O COMANDO FUNCIONA MESMO Q EU ESTEJA ENTRANDO EM UMA PASTA Q CONTENHA ESPACO NO NOME
{
	struct stat	info;
	char	*argv[2];

	command = skip_char(command);
	command = skip_space(command);
	if (stat(command, &info) == 0 && S_ISDIR(info.st_mode) && access(command, X_OK) == -1) // A MACRO S_ISDIR() ESTA APRESENTANDO PROBLEMA NO VALGRIND: Conditional jump or move depends on uninitialised value(s)
		printf("-minishel: cd: %s: Permissão negada\n", command);
	else if (stat(command, &info) == 0 && !S_ISDIR(info.st_mode)) // A MACRO S_ISDIR() ESTA APRESENTANDO PROBLEMA NO VALGRIND: Conditional jump or move depends on uninitialised value(s)
		printf("-minishell: cd: %s: Não é um diretório\n", command);
	else if (chdir(command) == -1)
		printf("-minishell: cd: %s: Arquivo ou diretório inexistente\n", command);
	argv[0] = new_pwd(getcwd(NULL, 0));
	argv[1] = NULL;
	add_variable(argv, env, env_list);
	free(argv[0]);
}

// void	cd(char **argv) // E NECESSARIO ATUALIZAR A VARIAVEL DE AMBIENTE PWD APOS SAIR DO DIRETORIO?
// {
// 	if (chdir(argv[1]) == -1)
// 		printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", argv[1]);
// }
