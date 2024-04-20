#include "../minishell.h"

// typedef struct s_env
// {
// 	char	*env;
// 	struct s_env	*next;
// }	t_env;

/// @brief INSERE UMA STRING NO FIM DA LISTA ENCADEADA
/// @param no ENDERECO DE MEMORIA DO PASSADO COMO PARAMETRO
/// @param str STRING QUE SERA COPIADA E ARMAZENADA NA LISTA ENCADEADA
void	insert_last(t_str **no, char *str)
{
	t_str	*new;
	t_str	*assist;

	new = malloc(sizeof(t_str));
	if (!new)
		return ;
	new->str = copy_str(str);
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

void	creat_list(t_env **no, char **array) // COPIAR CADA ELEMENTO DO ARRAY PARA A LISTA ENCADEADA
{

}