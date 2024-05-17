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



int	main(void) // SERA Q O PROCESSO PAI NAO PODE PARTICIPAR DESSA BRINCADEIRA DE PIPE?
{
	pid_t	pid;
	int	pipe_fd[2];
	char	buffer[100];
	// int	i;

	if (pipe(pipe_fd) == -1)
		return (printf("Error: pipe\n"));

	pid = fork();

	if (pid == -1)
		return (printf("Error: pid\n"));

	if (pid > 0) // PROCESSO PAI
	{
// printf("pipe_fd[0] -> %d\n", pipe_fd[0]);
dup2(STDIN_FILENO, 10);
		dup2(pipe_fd[0], STDOUT_FILENO);
		printf("vampeta");
dup2(10, STDIN_FILENO);
// printf("return -> %ld\n", write(pipe_fd[0], "vampeta", 7));
if (write(pipe_fd[0], "vampeta", 7) < 1)
	write(10, "Error\n", 6);
// write(10, "teste\n", 6);
// read(pipe_fd[0], buffer, 7);
// printf("buffer: %s\n", buffer);
		// close(pipe_fd[0]);
		// close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		return (0);
		// return (printf("pai: pipe_fd[0] -> %d\tpipe_fd[1] -> %d\n", pipe_fd[0], pipe_fd[1]));
	}
	else if (pid == 0) // PROCESSO FILHO
	{
		// i = 0;
		// while (read(pipe_fd[0], &buffer[i], 1) != -1)
		// 	i++;
		// buffer[i] = '\0';
// printf("pipe_fd[0] -> %d\n", pipe_fd[0]);
		// read(pipe_fd[0], buffer, 99);
		// printf("buffer: %s\n", buffer);
		// close(pipe_fd[0]);
		// close(pipe_fd[1]);
		return (0);
		// return (printf("filho: pipe_fd[0] -> %d\tpipe_fd[1] -> %d\n", pipe_fd[0], pipe_fd[1]));
	}

	return (0);
}



// int	main(void)
// {
// 	dup2(STDOUT_FILENO, STDIN_FILENO);
// 	while(1)
// 	{}
// }