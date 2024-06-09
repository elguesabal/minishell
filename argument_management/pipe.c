#include "../minishell.h"

// int	search_pipe(char **argv) // CAIU EM DESUSO POR CAUSA DA FUNCAO search_operator()
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == '|')
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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

// char	**args_pipe(char **argv, int process)
// {
// 	char	**args_pipe;
// 	int	i;

// 	i = 0;
// 	while ()
// 	{

// 	}

// 	args_pipe = malloc( * sizeof(char *));

// 	i = 0;
// 	while (args_pipe[i])
// 	{
// 		if (search_char(argv[i])) // VERIFICAR SE HA PIPE DENTRO DA STRING
// 		{
// 			if (i == 0)
// 			{

// 			}
// 			else if (i > 0)
// 			{

// 			}
// 		}
// 		else
// 		{
// 			args_pipe[i] = copy_str(argv[i]);
// 		}

// 		i++;
// 	}
// 	return (args_pipe);
// }

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] && args[i][0] != '|')
		i++;
	return (i);
}

char	**args_pipe(char **argv, int process) // ESSA FUNCAO DEVE RETORNAR OS ARGUMRNTOS CORRETAMENTE PARA O PROXIMO PROCESSO
{
(void)argv;
(void)process;
	char	**return_arg;
	int	current_process;
	int	i;
	int	j;
(void)return_arg;
(void)i;
(void)j;
(void)current_process;

	current_process = 0;
	i = 0;
	while (argv[i] && current_process != process)
	{
		if (argv[i] && argv[i][0] == '|')
		{
			current_process++;
		}
		i++; // ATE ENCONTRAR O PIPE RELATIVO AO process
	}

// printf("current_process: %d\tprocesso: %d\tcount_args(&argv[i]): %d\n", current_process, process, count_args(&argv[i]));
// while (argv[i])
// {
// 	printf("argv[%d]: %s\n", i, argv[i]);
// 	i++;
// }
// printf("fim dos args\n\n");

// printf("teste: %d\n", count_args(&argv[i]));
// printf("current_process: %d\n", current_process);
// printf("current_process: %d\tcount_args(&argv[%d]): %d\n", current_process, i, count_args(&argv[i]));
	return_arg = malloc((count_args(&argv[i]) + 1) * sizeof(char *));
	j = 0;
	while (argv[i] && argv[i][0] != '|')
	{
		return_arg[j] = copy_str(argv[i]);
		j++;
		i++;
	}
	return_arg[j] = NULL;
// printf("process: %d\n", process);
// i = 0;
// while (argv[i])
// {
// 	printf("argv[%d]: %s\n", i, argv[i]);
// 	i++;
// }
// i = 0;
// while (return_arg[i])
// {
// 	printf("return_arg[%d]: %s\n", i, return_arg[i]);
// 	i++;
// }
// printf("fim do return\n\n");
	return (return_arg);
// return (NULL);
}

void	command_pipe(char *str, char **argv, char ***argenv, t_str **env_list)
{
	pid_t	pid[20]; // ANTES EU SO TINHA ESPACO SO PRA 2 PROCESSOS
	// int	fd[2]; // NA VDD EU PRECISO DE UM PAR DE FD PARA CADA COMUNICACAO ENTRE PROCESSOS
	int	fd[20][2]; // AFF TENHO Q USAR malloc() NO fd E NO pid
	int	n_process;
	int	i;
	char	**args_process;
(void)str;
(void)argenv;
(void)env_list;
(void)args_process;


	n_process = count_pipe(argv);

	i = 0;
	while (i < n_process)
	{
		pipe(fd[i]);
		i++;
	}

	i = 0;
	while (i <= n_process)
	{
// printf("o processo foi iniciado: %d\n", i);
// printf("i: %d\tn_process: %d\n", i, n_process);
		pid[i] = fork();

		if (pid[i] == 0)
		{
			if (i > 0)
				dup2(fd[i - 1][0], STDIN_FILENO);
			if (i < n_process)
				dup2(fd[i][1], STDOUT_FILENO);

			int	j = 0; // ESSA BAGACA ME LASCA EM
			while (j <= i)
			{
				close(fd[j][0]);
				close(fd[j][1]);
				j++;
			}

			args_process = args_pipe(argv, i);
			if (search_operator(args_process, '>') || search_operator(args_process, '<'))
			{
				redirection_operators(str, args_process, argenv, env_list);
			}
			else
			{
				revert_caracter(args_process);
				commands(str, args_process, argenv, env_list);
			}
			free_split(args_process);
			exit_shell(argv, str, *argenv, env_list);
		}
		i++;
	}

// printf("i: %d\tn_process: %d\n", i, n_process);

	i = 0;
	while (i < n_process)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}

	i = 0;
	while(i <= n_process)
	{
// printf("esperando processo %d\n", i);
		waitpid(pid[i], NULL, 0);
// printf("processo respondido %d\n", i);
		i++;
	}
}


// pid_t	init_pipe(int last) // AINDA PENSANDO COMO IMPLEMENTAR O PIPE // ACHO Q NAO DA PRA SEGUIR ESSA LINHA DE RACIOCINIO PQ OS PROCESSOS FILHOS VAI CONTINUAR NO LOOP E SE MULTIPLICAREM COMO UMA ARVORE
// {
// 	pid_t	pid;
// 	int	fd[2];

// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0) // FAZER O waitpid() SO NA FUNCAO DE FINISH
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		if (last)
// 			dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 	}
// 	return (pid);
// }

// void	finish_pipe(int *fd, int *pid, t_str env_list)
// {
// 	int	status;

// 	close(fd[0]);
// 	close(fd[1]);
// 	while (*pid != 0)
// 	{
// 		waitpid(*pid, &status, 0);
// 		pid++;
// 	}
// 	if (WIFEXITED(status)) // AKI EU SO DEVO SALVAR O ULTIMO STATUS MESMO
// 	variable_status(WEXITSTATUS(status), env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
// }





// POSSIVEI ERROS:

// OS PROCESSOS SAO CRIADOS E VAO DIRETO EXECUTAR OS COMANDOS SEM ESPERAR O ANTERIO (NO CASO DE "ls | cat | cat" OS 3 INICIAM JUNTOS POREM O TERCEIRO CAT PODE COMECAR SEM ESPERAR O SEGUNDO ACABAR)

// EU ESTOU USANDO waitpid() NA ORDEM INVERSA EXEMPLO:
// PRIMEIRO waitpid() ENCERRA O ULTIMO PROCESSO
// SEGUNDO waitpid() ENCERRA O PENULTIMO PROCESSO
// ULTIMO waitpid() ENCERRA O PRIMEIRO PROCESSO




// caminishell: ls | cat
// a
// argument_management
// assistant
// b
// commands
// en.subject.pdf
// estudos
// Makefile
// minishell
// minishell.c
// minishell.h
// pt.subject .pdf
// ==14604==
// ==14604== HEAP SUMMARY:
// ==14604==     in use at exit: 208,214 bytes in 225 blocks
// ==14604==   total heap usage: 509 allocs, 284 frees, 231,441 bytes allocated
// ==14604==
// ==14604== LEAK SUMMARY:
// ==14604==    definitely lost: 0 bytes in 0 blocks
// ==14604==    indirectly lost: 0 bytes in 0 blocks
// ==14604==      possibly lost: 0 bytes in 0 blocks
// ==14604==    still reachable: 208,214 bytes in 225 blocks
// ==14604==         suppressed: 0 bytes in 0 blocks
// ==14604== Rerun with --leak-check=full to see details of leaked memory
// ==14604==
// ==14604== For lists of detected and suppressed errors, rerun with: -s
// ==14604== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// ==14605==
// ==14605== HEAP SUMMARY:
// ==14605==     in use at exit: 208,214 bytes in 225 blocks
// ==14605==   total heap usage: 509 allocs, 284 frees, 231,442 bytes allocated
// ==14605==
// ==14605== LEAK SUMMARY:
// ==14605==    definitely lost: 0 bytes in 0 blocks
// ==14605==    indirectly lost: 0 bytes in 0 blocks
// ==14605==      possibly lost: 0 bytes in 0 blocks
// ==14605==    still reachable: 208,214 bytes in 225 blocks
// ==14605==         suppressed: 0 bytes in 0 blocks
// ==14605== Rerun with --leak-check=full to see details of leaked memory
// ==14605==
// ==14605== For lists of detected and suppressed errors, rerun with: -s
// ==14605== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

// minishell: ==14603== Syscall param pselect6(sig) points to unaddressable byte(s)
// ==14603==    at 0x49D9744: pselect64_syscall (pselect.c:34)
// ==14603==    by 0x49D9744: pselect (pselect.c:56)
// ==14603==    by 0x489EB4A: rl_getc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
// ==14603==    by 0x489E460: rl_read_key (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
// ==14603==    by 0x4882C86: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
// ==14603==    by 0x488BD14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
// ==14603==    by 0x109B1C: main (in /home/jose/programacao/minishell/minishell)
// ==14603==  Address 0x10023a6820 is 0 bytes inside a block of size 32 in arena "core"
// ==14603==
// minishell:
// ==14603== Invalid read of size 1
// ==14603==    at 0x10B9A6: quotes (in /home/jose/programacao/minishell/minishell)
// ==14603==    by 0x109B38: main (in /home/jose/programacao/minishell/minishell)
// ==14603==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
// ==14603==
// ==14603==
// ==14603== Process terminating with default action of signal 11 (SIGSEGV)
// ==14603==  Access not within mapped region at address 0x0
// ==14603==    at 0x10B9A6: quotes (in /home/jose/programacao/minishell/minishell)
// ==14603==    by 0x109B38: main (in /home/jose/programacao/minishell/minishell)
// ==14603==  If you believe this happened as a result of a stack
// ==14603==  overflow in your program's main thread (unlikely but
// ==14603==  possible), you can try to increase the size of the
// ==14603==  main thread stack using the --main-stacksize= flag.
// ==14603==  The main thread stack size used in this run was 8388608.
// ==14603==
// ==14603== HEAP SUMMARY:
// ==14603==     in use at exit: 217,390 bytes in 319 blocks
// ==14603==   total heap usage: 525 allocs, 206 frees, 231,757 bytes allocated
// ==14603==
// ==14603== LEAK SUMMARY:
// ==14603==    definitely lost: 0 bytes in 0 blocks
// ==14603==    indirectly lost: 0 bytes in 0 blocks
// ==14603==      possibly lost: 0 bytes in 0 blocks
// ==14603==    still reachable: 217,390 bytes in 319 blocks
// ==14603==         suppressed: 0 bytes in 0 blocks
// ==14603== Rerun with --leak-check=full to see details of leaked memory
// ==14603==
// ==14603== For lists of detected and suppressed errors, rerun with: -s
// ==14603== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
// Falha de segmentação (imagem do núcleo gravada)