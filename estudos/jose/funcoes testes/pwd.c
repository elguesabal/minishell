#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	pwd(void)
{
	char	*pwd;

	if (pwd = getcwd(NULL, 0))
    	printf("%s\n", pwd);
    else
    {
        printf("Error\npwd nao funcionou\n");
	    free(pwd);
        return (1);
    }
	free(pwd);
	return (0);
}

int	main(void)
{
	pwd();
	return (0);
}