#include "../minishell.h"

void    cd(char *path)
{
	path += 2;
	while (*path == ' ' || *path == '	')
		path++;
	if (chdir(path) == -1)
        printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", path);
}
