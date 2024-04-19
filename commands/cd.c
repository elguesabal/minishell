#include "../minishell.h"

void    cd(char *command) // DESSE MODO O COMANDO FUNCIONA MESMO Q EU ESTEJA ENTRANDO EM UMA PASTA Q CONTENHA ESPACO NO NOME
{
	command = skip_char(command);
	command = skip_space(command);
	if (chdir(command) == -1)
		printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", command);

	// while (*env) // AKI EU ATUALIZO A VARIAVEL PWD
	// {
	// 	if (env[i] == "PWD=")
	// 		env[i] = "PWD=" + getcwd(NULL, 0);
	// }
}

// void	cd(char **argv) // E NECESSARIO ATUALIZAR A VARIAVEL DE AMBIENTE PWD APOS SAIR DO DIRETORIO?
// {
// 	if (chdir(argv[1]) == -1)
// 		printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", argv[1]);
// }
