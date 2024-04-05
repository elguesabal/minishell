#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// stat lstat fstat



// int	main(void)
// {
// 	struct stat	info;

// 	stat("arquivo.txt", &info);

// 	printf("Tamanho do arquivo: %ld bytes\n", info.st_size);
// 	printf("Permissões do arquivo: %o\n", info.st_mode & 0777);

// 	return (0);
// }





// int	main(void)
// {
// 	struct stat	info;

// 	lstat("arquivo.txt", &info);

// 	printf("Tamanho do arquivo: %ld bytes\n", info.st_size);
// 	printf("Permissões do arquivo: %o\n", info.st_mode & 0777);

// 	return (0);
// }





// int	main(void)
// {
// 	struct stat	info;
// 	int			fd;

// 	fd = open("arquivo,txt", O_RDONLY);

// 	fstat(fd, &info);

//  	printf("Tamanho do arquivo: %ld bytes\n", info.st_size);
//  	printf("Permissões do arquivo: %o\n", info.st_mode & 0777);

// 	close(fd);
// 	return (0);
// }