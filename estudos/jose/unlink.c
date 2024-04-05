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