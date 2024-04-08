#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// getcwd chdir



// int	main(void)
// {
// 	char	buffer[100];
// 	char	*str;

// 	str = getcwd(buffer, sizeof(buffer));

// 	printf("%s\n", buffer);
// 	printf("%s\n", str);

// 	return (0);
// }





int	main(void)
{
	char	buffer[100];

	getcwd(buffer, sizeof(buffer));
	printf("diretorio atual: %s\n", buffer);

	// chdir("/nfs/homes/joseanto");

	// chdir("/home/jose/programacao/42/42cursus/minishell/estudos/jose");
	chdir("/home/jose/programacao/42/42cursus/minishell/estudos/jose/mensagem");
	// chdir("../");
	// chdir("..");
	chdir("../minishell");

	getcwd(buffer, sizeof(buffer));
	printf("diretorio atual: %s\n", buffer);

	return (0);
}

