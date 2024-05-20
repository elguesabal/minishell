#include "../minishell.h"

int	search_pipe(char **argv)
{
	while (*argv)
	{
		if (*argv[0] == '|')
			return (1);
		argv++;
	}
	return (0);
}

void	command_pipe(char **argv)
{
	pid_t	pid1;
	pid_t	pid2;
	int	pipe_fd[2];

	pipe(pipe_fd);

	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		char *teste1[] = {argv[0], argv[1], NULL};
		execve("/bin/ls", teste1, NULL);
		exit(0);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		char	*teste2[] = {argv[3], argv[4], NULL};
		execve("/bin/wc", teste2, NULL);
		exit(0);
	}

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
