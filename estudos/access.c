#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("R: %d\n", access("arquivo.txt", R_OK));
	printf("W: %d\n", access("arquivo.txt", W_OK));
	printf("X: %d\n", access("arquivo.txt", X_OK));
	printf("F: %d\n", access("arquivo.txt", F_OK));
	return (0);
}

// c2r6s1% ls -all arquivo.txt
// -r--r--r-- 1 joseanto 2023_rio-de-janeiro 0 Mar 26 15:55 arquivo.txt
// c2r6s1% ./a.out             
// R: 0
// W: -1
// X: -1
// F: 0
// c2r6s1% chmod +w arquivo.txt 
// c2r6s1% ls -all arquivo.txt
// -rw-r--r-- 1 joseanto 2023_rio-de-janeiro 0 Mar 26 15:55 arquivo.txt
// c2r6s1% ./a.out             
// R: 0
// W: 0
// X: -1
// F: 0