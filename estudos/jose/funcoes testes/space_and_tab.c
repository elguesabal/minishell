#include <stdio.h>

char	*skip_char(char *str)
{
	while (*str && *str != ' ' && *str != '	')
		str++;
	return (str);
}

char	*skip_space(char *str)
{
	while (*str && (*str == ' ' || *str == '	'))
		str++;
	return (str);
}

int	main(void)
{
	char	*str = "cd ..";

	str = skip_char(str);
	printf("%s\n", str);

	str = skip_space(str);
	printf("%s\n", str);

	return (0);
}