#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// unlink execve dup dup2



// int	main(int argc, char **argv)
// {
// 	if (unlink(argv[1]) == 0)
// 		printf("arquivo %s excluido\n", argv[1]);
// 	else
// 		printf("arquivo nao encontrado\n");
// 	return (0);
// }





// int	main(void)
// {
// 	char	*args[] = {"./programa.out", "abc", "123", NULL};

// 	execve("./mensagem/programa.out", args, NULL);

// 	printf("Esta linha nunca sera alcancada\n");

// 	return (0);
// }





// int	main(void)
// {
// 	int	fd;
// 	int	new_fd;

// 	fd = open("arquivo.txt", O_RDWR);

// 	new_fd = dup(fd);

// 	write(new_fd, "teste\n", 6);

// 	close(fd);
// 	close(new_fd);

// 	return (0);
// }





// int	main(void)
// {
// 	int	fd;

// 	fd = open("arquivo.txt", O_RDWR);

// 	dup2(fd, 1);

// 	printf("aaaaaaaaaaaaaaa\n");

// 	close(fd);

// 	return (0);
// }

















// int	main(void)
// {
// 	int	fd;
// 	int	new_fd;

// 	write(STDOUT_FILENO, "teste\n", 6);
// 	fd = open("a.txt", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);

// 	new_fd = dup(STDOUT_FILENO);
// 	dup2(fd, STDOUT_FILENO);

// 	write(STDOUT_FILENO, "teste a\n", 8);
// 	write(new_fd, "teste b\n", 8);

// printf("aaaaaaaaaaaaaaaaaaaaaa: %d\n", STDOUT_FILENO);
// 	int teste = dup2(new_fd, STDOUT_FILENO);
// printf("bbbbbbbbbbbbbbbbbbbbbb: %d\n", STDOUT_FILENO);
// 	// teste += 48;
// 	// write(1, &teste, 1);
// 	// write(1, "aaa\n", 4);
// 	// printf("aaa: %d\n", teste);

// 	return (0);
// }


// int	main(void)
// {
// 	char	*str = getcwd(NULL, 0);
// 	printf("%s\n", str);
// 	chdir("/bin");
// 	str = getcwd(NULL, 0);
// 	printf("%s\n", str);


// 	char	*args[] = {"./ls", "-all", NULL};

// 	execve("./ls", args, NULL);

// 	printf("Esta linha nunca sera alcancada\n");

// 	return (0);
// }
