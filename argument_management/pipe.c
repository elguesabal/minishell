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

int	count_pipe(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

// void	command_pipe(char **argv)
// {
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	// pid_t	pid;
// 	int	pipe_fd[2];

// 	pipe(pipe_fd);

// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(pipe_fd[1]);
// 		char *teste1[] = {argv[0], argv[1], NULL};
// 		execve("/bin/ls", teste1, NULL);
// 		exit(0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		close(pipe_fd[1]);
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		char	*teste2[] = {argv[3], argv[4], NULL};
// 		execve("/bin/wc", teste2, NULL);
// 		exit(0);
// 	}


// // 	pid_t	*pid = malloc(count_pipe(argv) * sizeof(int));


// // 	int	i = 0;
// // 	while (i != 6)
// // 	{
// // 		if (i == 0)
// // 			pid[0] = fork();
// // 		else if (i == 3)
// // 			pid[1] = fork();


// // 		if (pid[0] == 0 || pid[1] == 0)
// // 		{
// // 			dup2(pipe_fd[0], STDIN_FILENO);
// // 			close(pipe_fd[0]);
// // 			dup2(pipe_fd[1], STDOUT_FILENO);
// // printf("oi\n");
// // 			close(pipe_fd[1]);

// // 			char	*teste[] = {argv[i], argv[i + 1], NULL};
// // 			char	path[8] = "/bin/";
// // 			path[5] = argv[i][0];
// // 			path[6] = argv[i][1];
// // 			path[7] = '\0';

// // printf("teste: %s\n", path);

// // 			execve(path, teste, NULL);
// // 			exit(0);
// // 		}

// // 		i += 3;
// // 	}


// 	// int	i = 0;
// 	// while ()
// 	// {
// 	// 	pid_t	pid = fork();

// 	// 	if (pid == 0)
// 	// 	{

// 	// 	}
// 	// 	else if (pid > 0)
// 	// 	{
// 	// 		if (i == 0)
// 	// 		{
// 	// 			close(pipe_fd[0]);
// 	// 			close(pipe_fd[1]);
// 	// 		}
// 	// 		waitpid(pid, NULL, 0);
// 	// 	}
// 	// 	i++;
// 	// }



// 	// // i = 0;
// 	// // while (i != count_pipe(argv))
// 	// // {
// 	// // 	waitpid(pid[i], NULL, 0);
// 	// // 	i++;
// 	// // }


// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// }



void	command_pipe(char **argv)
{
	pid_t	pid[2];
	int	fd[2];
	int	n_pipe;
	int	i;
	// int	index;

	pipe(fd);

	n_pipe = count_pipe(argv);
	i = 0;
	while (i <= n_pipe)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			if (i != n_pipe)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);


			if (i == 0)
			{
				char	*teste[] = {"ls", "-all", NULL};
				execve("/bin/ls", teste, NULL);
			}
			else if (i == 1)
			{
				char	*teste[] = {"wc", "-l", NULL};
				execve("/bin/wc", teste, NULL);
			}
								// PROCESSAMENTO DE DADOS
// char	*teste[] = {argv[index], argv[index + 1], NULL};
// char	path[8] = "/bin/";
// path[5] = argv[index][0];
// path[6] = argv[index][1];
// path[7] = '\0';

// // printf("teste: %s\n", path);

// execve(path, teste, NULL);
								// PROCESSAMENTO DE DADOS
		}
		i++;
	}

	close(fd[0]);
	close(fd[1]);
	while (i)
	{
		waitpid(pid[i], NULL, 0);
		i--;
	}
}