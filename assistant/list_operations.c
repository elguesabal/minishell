#include "../minishell.h"

/// @brief INSERE UMA STRING NO FIM DA LISTA ENCADEADA
/// @param no ENDERECO DE MEMORIA DA LISTA PASSADO COMO PARAMETRO
/// @param str STRING QUE SERA ARMAZENADA NA LISTA ENCADEADA
/// @param subprocesses VARIAVEL Q IDENTIFICA SE A VARIAVEL DE AMBIENTE FOI DISPONIBILIZADA PARA SUBPROCESSOS ATRAVEZ DO COMANDO EXPORT 0 NAO ESTA DISPONIVEL PARA SUBPROCESSOS E 1 ESTA DISPONIVEL
void	insert_last(t_str **no, char *str)
{
	t_str	*new;
	t_str	*assist;

	new = malloc(sizeof(t_str));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	if (!*no)
		*no = new;
	else
	{
		assist = *no;
		while (assist->next)
			assist = assist->next;
		assist->next = new;
	}
}

/// @brief COPIA UM ARREY DE STRING PARA A LISTA ENCADEADA
/// @param no ENDERECO DE MEMORIA DA LISTA PASSADO COMO PARAMETRO
/// @param array_str ARRAY DE STRING A SER COPIADA PARA A LISTA
void	creat_list(t_str **no, char **array_str)
{
	while (*array_str)
	{
		insert_last(no, copy_str(*array_str));
		array_str++;
	}
}

/// @brief CRIA UM E RETORNA UM ENDERECO DE UM ARRAY DE STRING REAPROVEITANDO OS INDERECOS DA LISTA ENCADEADA PASSADA COMO ARGUMENTO
/// @param no ENDERECO DE MEMORIA DO NO Q REAPROVEITARA AS STRINGS
/// @return RETORNA UM ARRAY DE STRINGS COM O MESMO INDERECO DE MEMORIA DE STRINGS DENTRO DA LISTA ENCADEADA
char	**array_to_list(t_str **no)
{
	char	**array;
	t_str	*assist;
	int		i;

	array = malloc((listlen(*no) + 1) * sizeof(char *));
	if (!array)
	{
		printf("Error\na funcao malloc() retornou NULL\n");
		return (NULL);
	}
	assist = *no;
	i = 0;
	while (assist)
	{
		array[i] = assist->str;
		i++;
		assist = assist->next;
	}
	array[i] = NULL;
	return (array);
}

/// @brief USA A FUNCAO free() EM TODOS OS NOS DE LISTA ENCADEADA QUE CONTENHA APENAS UMA STRING str
/// @param no ENDERECO DE MEMORIA DO PRIMEIRO NO DA LISTA
void	free_list(t_str **no)
{
	t_str	*assist;

	assist = *no;
	while (assist)
	{
		*no = (*no)->next;
		free(assist->str);
		free(assist);
		assist = *no;
	}
}
