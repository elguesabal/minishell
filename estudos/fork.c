#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// 1. pid_t	fork(void):
//	- Cria um novo processo, chamado processo filho, que é uma cópia exata do processo pai.
//	- Retorna o PID do processo filho para o processo pai e 0 para o processo filho.
//	- É usada para criar processos paralelos ou concorrentes em sistemas Unix.

// 2. pid_t	wait(int *status):
//	- Aguarda até que um processo filho termine a execução.
//	- Retorna o PID do processo filho que terminou e armazena informações sobre o status de término do processo filho.
//	- É usada para sincronizar processos pai e filho, permitindo que o processo pai aguarde o término do processo filho.

// 3. pid_t	waitpid(pid_t pid, int *status, int options):
//	- É uma versão mais flexível de wait(), permitindo que o processo pai aguarde um processo filho específico ou qualquer processo filho.
//	- Permite a espera não-bloqueante por processos filhos usando a opção WNOHANG.
//	- Retorna o PID do processo filho que terminou e armazena informações sobre o status de término do processo filho.
//	- É usada para sincronizar processos pai e filho em cenários onde a espera de processos específicos é necessária ou quando é necessário verificar se um processo filho terminou sem bloquear a execução do processo pai.

// 4. pid_t	wait3(int *status, int options, struct rusage *rusage) e pid_t	wait4(pid_t pid, int *status, int options, struct rusage *rusage):
//	- São variantes mais antigas de wait(), específicas para sistemas Unix mais antigos.
//	- Permitem esperar por processos filhos e obter informações sobre o uso de recursos do processo filho, como tempo de CPU e uso de memória.
//	- São menos utilizadas em sistemas modernos, pois waitpid() fornece funcionalidades semelhantes com mais flexibilidade.



// int	main(void)
// {
// 	pid_t	pid;

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 		printf("teste 1 Processo filho: %d\n", getpid());
// 	else if (pid > 0)
// 	{
// 		// sleep(3);
// 		// while (1)
// 		// {}
// 		printf("teste 2 Processo pai: %d\n", getpid());
// 		printf("teste 3 Processo filho: %d\n", pid);
// 	}

// 	return (0);
// }





// int	main(void)
// {
// 	pid_t	pid, child_pid;
// 	int		status;

// 	printf("processo pai %d\n\n", getpid());

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 	{
// 		sleep(3);
// 		printf("1 Processo filho: %d\n", getpid());
// 	}
// 	else if (pid > 0)
// 	{
// 		child_pid = wait(&status);
// 		printf("2 Processo pai: %d\n", getpid());
// 		printf("3 Processo filho: %d\n", pid);
// 		printf("4 return wait: %d\tstatus: %d\n", child_pid, status);
// 	}

// 	return (0);
// }





// int	main(void)
// {
// 	pid_t	pid, child_pid;
// 	int		status;

// 	printf("processo pai %d\n\n", getpid());

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 	{
// 		sleep(3);
// 		printf("1 Processo filho: %d\n", getpid());
// 	}
// 	else if (pid > 0)
// 	{
// 		child_pid = waitpid(pid, &status, 0);
// 		printf("2 Processo pai: %d\n", getpid());
// 		printf("3 Processo filho: %d\n", pid);
// 		printf("4 return wait: %d\tstatus: %d\n", child_pid, status);
// 	}

// 	return (0);
// }





// int	main(void)
// {
// 	pid_t	pid, child_pid;
// 	int		status;

// 	printf("processo pai %d\n\n", getpid());

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 	{
// 		sleep(3);
// 		printf("1 Processo filho: %d\n", getpid());
// 	}
// 	else if (pid > 0)
// 	{
// 		child_pid = wait3(&status, 0, NULL);
// 		printf("2 Processo pai: %d\n", getpid());
// 		printf("3 Processo filho: %d\n", pid);
// 		printf("4 return wait: %d\tstatus: %d\n", child_pid, status);
// 	}

// 	return (0);
// }





// int	main(void)
// {
// 	pid_t	pid, child_pid;
// 	int		status;

// 	printf("processo pai %d\n\n", getpid());

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 	{
// 		sleep(3);
// 		printf("1 Processo filho: %d\n", getpid());
// 	}
// 	else if (pid > 0)
// 	{
// 		child_pid = wait4(pid, &status, 0, NULL);
// 		printf("2 Processo pai: %d\n", getpid());
// 		printf("3 Processo filho: %d\n", pid);
// 		printf("4 return wait: %d\tstatus: %d\n", child_pid, status);
// 	}

// 	return (0);
// }





int	main(void)
{
	pid_t	pid;
	int		pipefd[2];
	char	buffer[10];

	pipe(pipefd);

	pid = fork();

	if (pid == 0)
	{
		close(pipefd[1]);
		read(pipefd[0], buffer, sizeof(buffer));
		printf("processo filho leu: %s\n", buffer);
		close(pipefd[0]);
	}
	else if (pid > 0)
	{
		close(pipefd[0]);
		write(pipefd[1], "vampeta", 7);
		close(pipefd[1]);
	}

	return (0);
}