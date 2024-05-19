#include "../minishell.h"

void	command_pipe(char **argv)
{
	pid_t	pid1;
	// pid_t	pid2;
	int	pipe_fd[2];
	// char	buffer[1024];

(void)argv;

	pipe(pipe_fd);

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		char *teste[] = {"ls", "-all", NULL};
		execve("/bin/ls", teste, NULL);
		exit(0);
	}

	// pid2 = fork();
	// if (pid2 > 0)
	// {

	// }

	waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
}
