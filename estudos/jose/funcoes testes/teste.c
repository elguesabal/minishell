#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*replace_string(char *free_str, char *new_str)
// {
// 	int	i;
// 	char	*copy_new;

// 	free(free_str);
// 	copy_new = malloc((ft_strlen(new_str) + 1) * sizeof(char));
// 	if (copy_new == NULL)
// 	{
// 		printf("Error: a funcao malloc() retornou NULL\n");
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (new_str[i])
// 	{
// 		copy_new[i] = new_str[i];
// 		i++;
// 	}
// 	copy_new[i] = '\0';
// 	return (copy_new);
// }

// int	main(int argc, char **argv, char **env)
// {
// 	// int	i = 0;

// 	// while (argv[i])
// 	// {
// 	// 	printf("%s\n", argv[i]);
// 	// 	i++;
// 	// }

// 	// i++;

// 	// while (argv[i])
// 	// {
// 	// 	printf("%s\n", argv[i]);
// 	// 	i++;
// 	// }

// 	// i = 0;
// 	// while (env[i])
// 	// {
// 	// 	printf("%s\n", env[i]);
// 	// 	i++;
// 	// }


// 	// printf("%s\n", getenv("PATH"));


// // 	char	*teste;


// // 	teste = malloc(5 * sizeof(char));
// // printf("%p\n", teste);
// // printf("%s\n", teste);
// // 	free(teste);

// // printf("%p\n", teste);
// // printf("%s\n", teste);
// // 	return (0);



// 	char	*teste;
// 	int		i = 0;

// 	teste = malloc(5 * sizeof(char));
// 	while (i < 4)
// 	{
// 		teste[i] = 'a';
// 		i++;
// 	}
// 	teste[i] = '\0';

// 	printf("%s\n", teste);

// 	teste = replace_string(teste, "teste");

// 	printf("%s\n", teste);

// 	free(teste);

// 	return (0);
// }



// int	main(void)
// {
// 	char	*teste = "'";
// 	printf("teste: %c\n", *teste);
// 	return (0);
// }



// int	main(void)
// {
// 	printf("teste: %c\n", 1000000);
// 	return (0);
// }



// int main() {
//     // Definindo o valor decimal do caractere desejado além de 127
//     int codigo_ascii = 169; // Por exemplo, vamos usar o símbolo de direitos autorais
    
//     // Usando printf para imprimir o caractere
//     printf("Caractere além de 127: %c\n", codigo_ascii);
    
//     return 0;
// }



// int	main(void)
// {
// 	int i = 0;
// 	char c;

// 	while (i < 1000)
// 	{
// 		c = i;
// 		printf("i: %d -> %c\n", i, i);
// 		i++;
// 	}
// 	return (0);
// }



// int	main(void)
// {
// 	char c1;
// 	char c2;

// 	c1 = 97;
// 	printf("c1: %c\n", c1);

// 	int	i = 353;
// 	c2 = i;
// 	printf("c2: %c\n", c2);

// 	if (c1 == c2)
// 		printf("true\n");

// 	return (0);
// }



// int	main(void)
// {
// 	char	c = -2;
// 	printf("%c\n", c);
// 	return (0);
// }



// int	main(int argc, char **argv)
// {
// 	while (*argv)
// 	{
// 		printf("%s\n", *argv);
// 		*argv++;
// 	}
// 	return (0);
// }



// int main() {
//     char buffer[1024];

//     // Lê a entrada padrão (stdin) linha por linha
//     while (fgets(buffer, sizeof(buffer), stdin)) {
//         printf("Read from pipe: %s", buffer);
//     }

//     return 0;
// }



// int	main(void)
// {
// 	char	buffer[100];

// 	while (read(STDIN_FILENO, &buffer, 1) > 0)
// 		printf("%s", buffer);
// 	return (0);
// }



// int	main(int argc, char **argv)
// {
// 	int	new_fd;

// 	// if (argv[1])
// 		// new_fd = dup2(0, 1);

// 	new_fd = dup2(1, 0);

// 	// write(0 ,"teste\n", 6);

// 	// printf("coonsegui redirecionar o fluxo\n");

// 	// printf("STDIN_FILENO: %d\nSTDOUT_FILENO: %d\nnew_fd: %d\n", STDIN_FILENO, STDOUT_FILENO, new_fd);
// 	return (0);
// }



// int	main(void) // SERA Q O PROCESSO PAI NAO PODE PARTICIPAR DESSA BRINCADEIRA DE PIPE?
// {
// 	pid_t	pid;
// 	int	pipe_fd[2];
// 	char	buffer[100];
// 	// int	i;

// 	if (pipe(pipe_fd) == -1)
// 		return (printf("Error: pipe\n"));

// 	pid = fork();

// 	if (pid == -1)
// 		return (printf("Error: pid\n"));

// 	if (pid > 0) // PROCESSO PAI
// 	{
// // printf("pipe_fd[0] -> %d\n", pipe_fd[0]);
// dup2(STDIN_FILENO, 10);
// 		dup2(pipe_fd[0], STDOUT_FILENO);
// 		printf("vampeta");
// dup2(10, STDIN_FILENO);
// // printf("return -> %ld\n", write(pipe_fd[0], "vampeta", 7));
// if (write(pipe_fd[0], "vampeta", 7) < 1)
// 	write(10, "Error\n", 6);
// // write(10, "teste\n", 6);
// // read(pipe_fd[0], buffer, 7);
// // printf("buffer: %s\n", buffer);
// 		// close(pipe_fd[0]);
// 		// close(pipe_fd[1]);
// 		waitpid(pid, NULL, 0);
// 		return (0);
// 		// return (printf("pai: pipe_fd[0] -> %d\tpipe_fd[1] -> %d\n", pipe_fd[0], pipe_fd[1]));
// 	}
// 	else if (pid == 0) // PROCESSO FILHO
// 	{
// 		// i = 0;
// 		// while (read(pipe_fd[0], &buffer[i], 1) != -1)
// 		// 	i++;
// 		// buffer[i] = '\0';
// // printf("pipe_fd[0] -> %d\n", pipe_fd[0]);
// 		// read(pipe_fd[0], buffer, 99);
// 		// printf("buffer: %s\n", buffer);
// 		// close(pipe_fd[0]);
// 		// close(pipe_fd[1]);
// 		return (0);
// 		// return (printf("filho: pipe_fd[0] -> %d\tpipe_fd[1] -> %d\n", pipe_fd[0], pipe_fd[1]));
// 	}

// 	return (0);
// }



// int	main(void)
// {
// 	pid_t	pid1, pid2;
// 	int	pipe_fd[2];

// 	pipe(pipe_fd);

// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		printf("vampeta\n");
// 		close(pipe_fd[1]);
// 		return (0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		char	buffer[10];
// 		int	n_read;

// 		n_read = read(pipe_fd[0], buffer, 9);
// 		buffer[n_read] = '\0';
// 		printf("n_read: %d -> %s", n_read, buffer);

// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		return (0);
// 	}

// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }



// int	main(void)
// {
// 	pid_t	pid;
// 	int	pipe_fd[2];

// 	pipe(pipe_fd);

// 	pid = fork();

// 	if (pid > 0)
// 	{
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);

// 		// printf("vampeta\n"); // ESSA DISGRACA DE printf() TODA BUGADA // O PROBLEMA ERA EU Q ACHEI Q NAO PRECISAVA USAR A FUNCAO close()
// 		// fflush(stdout);
// 		write(STDOUT_FILENO, "vampeta\n", 8);
// 		close(pipe_fd[1]);
// 	}
// 	else if (pid == 0)
// 	{
// 		char	buffer[10];
// 		int	n_read;

// 		n_read = read(pipe_fd[0], buffer, 10);
// 		buffer[n_read] = '\0';
// 		printf("n_read: %d -> %s", n_read, buffer);

// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		return (0);
// 	}

// 	waitpid(pid, NULL, 0);

// 	return (0);
// }



// int	main(void)
// {
// 	int	fd;

// 	fd = open("texto.txt", O_WRONLY);
// 	dup2(fd, STDOUT_FILENO);

// 	printf("foi?\n");

// 	return (0);
// }



// int main(void) {
//     int pipe_fd[2];
//     pid_t pid1, pid2;

//     // Cria o pipe
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     // Cria o primeiro processo filho
//     pid1 = fork();
//     if (pid1 == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid1 == 0) {
//         // Primeiro processo filho executa 'ls'
        
//         // Fecha o descritor de leitura do pipe
//         close(pipe_fd[0]);
        
//         // Redireciona stdout para o descritor de escrita do pipe
//         dup2(pipe_fd[1], STDOUT_FILENO);
        
//         // Fecha o descritor de escrita original do pipe
//         close(pipe_fd[1]);

//         // Executa 'ls'
//         execlp("ls", "ls", NULL);

//         // Se execlp falhar
//         perror("execlp");
//         exit(EXIT_FAILURE);
//     }

//     // Cria o segundo processo filho
//     pid2 = fork();
//     if (pid2 == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid2 == 0) {
//         // Segundo processo filho executa 'wc'
        
//         // Fecha o descritor de escrita do pipe
//         close(pipe_fd[1]);
        
//         // Redireciona stdin para o descritor de leitura do pipe
//         dup2(pipe_fd[0], STDIN_FILENO);
        
//         // Fecha o descritor de leitura original do pipe
//         close(pipe_fd[0]);

//         // Executa 'wc'
//         execlp("wc", "wc", "-l", NULL);

//         // Se execlp falhar
//         perror("execlp");
//         exit(EXIT_FAILURE);
//     }

//     // Processo pai fecha ambos os descritores do pipe
//     close(pipe_fd[0]);
//     close(pipe_fd[1]);

//     // Espera ambos os processos filhos terminarem
//     waitpid(pid1, NULL, 0);
//     waitpid(pid2, NULL, 0);

//     return 0;
// }



// int	main(int argc, char **argv)
// {
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	pid_t	pid3;
// 	int	pipe_fd[2];

// 	pipe(pipe_fd);

// 	pid1 = fork();	// PROGRAMA 1
// 	if (pid1 == 0)
// 	{
// // printf("pid1\n");
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(pipe_fd[1]);

// 												// PROCESSAMENTO DE DADOS
// 		write(STDOUT_FILENO, "teste\n", 6);
// 												// PROCESSAMENTO DE DADOS

// 		exit(0);
// 	}

// sleep(1);

// 	pid2 = fork();	// PROGRAMA 2
// 	if (pid2 == 0)
// 	{
// // printf("pid2\n");
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(pipe_fd[1]);

// 												// PROCESSAMENTO DE DADOS
// 		char	buffer[20];
// 		int	len = read(STDIN_FILENO, buffer, 20);
// 		write(STDOUT_FILENO, buffer, len);
// 												// PROCESSAMENTO DE DADOS

// 		exit(0);
// 	}

// sleep(1);

// 	pid3 = fork();	// PROGRAMA 3
// 	if (pid3 == 0)
// 	{
// // printf("pid3\n");
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		// dup2(pipe_fd[1], STDOUT_FILENO);	// TENHO Q IDENTIFCAR SE NAO E O ULTIMO PROGRAMA CASO SEJA ELE DEVE USAR STDOUT SEM AUTERACOES
// 		close(pipe_fd[1]);

// 												// PROCESSAMENTO DE DADOS
// 		char	buffer[20];
// 		int	len = read(STDIN_FILENO, buffer, 20);
// 		write(STDOUT_FILENO, buffer, len);
// 												// PROCESSAMENTO DE DADOS

// 		exit(0);
// 	}


// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	waitpid(pid3, NULL, 0);
// 	return (0);
// }



// int	main(void) // 1.out
// {
// 	printf("teste");
// 	return (0);
// }

int	main(void) // 2.out
{
	char	buffer[20];
	int	len;

	len = read(STDIN_FILENO, buffer, 20);
	buffer[len] = '\0';
	printf("lido: %s\n", buffer);
	return (0);
}

// int	main(void) // 3.out
// {
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int	fd[2];


// 	pipe(fd);

// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);

// 		// printf("teste");

// 		// char	*argv[] = {"ls", "-all", NULL};
// 		// execve("/bin/ls", argv, NULL);

// 		char	*argv[] = {"1", NULL};
// 		execve("./1", argv, NULL);

// 		exit(0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);

// 		// char	buffer[20];
// 		// int	len = read(STDIN_FILENO, buffer, 20);
// 		// printf("lido: \"%s\"\n", buffer);

// 		// char	*argv[] = {"wc", "-l", NULL};
// 		// execve("/bin/wc", argv, NULL);

// 		char	*argv[] = {"2", NULL};
// 		execve("./2", argv, NULL);

// 		exit(0);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }


























// int main(int argc, char **argv) // bash
// {
// 	// STDIN_FILENO  == 0
// 	// STDOUT_FILENO == 1

// 	int	fd[2];
// 	pipe(fd);

// 	// fd[0] -> STDIN_FILENO
// 	// fd[1] -> STDOUT_FILENO

// 	dup2(fd[1], STDOUT_FILENO);

// 	int main(void) // 1.out
// 	{
// 		printf("teste");
// 		return (0);
// 	}

// 	dup2(fd[0], STDIN_FILENO);

// 	int main(void) // 2.out
// 	{
// 		char	buffer;
// 		int	i = 0;

// 		while(read(STDIN_FILENO, &buffer, 1) != 0)
// 		{
// 			if (buffer == '\n')
// 				i++;
// 		}

// 		printf("%d\n", i);
// 		return (0);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid();
// 	waitpid();

//     return (0);
// }






