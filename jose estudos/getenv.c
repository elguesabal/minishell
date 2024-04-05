#include <stdio.h>
#include <stdlib.h>

// getenv



int	main(void)
{
	char	*str;

	// str = getenv("USER");
	str = getenv("TERM");

	printf("variavel: %s\n", str);

	return (0);
}