#include <stdio.h>
#include <stdlib.h>

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



int	main(int argc, char **argv)
{
	while (*argv)
	{
		printf("%s\n", *argv);
		*argv++;
	}
	return (0);
}