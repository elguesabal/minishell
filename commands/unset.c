#include "../minishell.h"

// char	*search_and_return_previous(t_str **no, char *str) // SEMELHANTE A search_variable_list() MAS RETORNA O NO ANTERIOR
// {
// 	t_str	*assist;
//     t_str   *previous;

// 	assist = *no;
// 	while (assist)
// 	{
// 		if (compare_variable(assist->str, str))
// 			return (assist->str);
// 		assist = assist->next;
// 	}
// 	return (NULL);
// }

// char    **remove(char **env, char *str)
// {

//     if ()
//     {

//     }
// }

char	**unset(char **argv, t_str **env_list, char **env)
{
    (void)argv;
    (void)env_list;
    (void)env;

    int i;
    // t_str   *assist;
    // t_str   *previous_assist;

    i = 1;
	while (argv[i])
    {
        // printf("testando unset: %s\n", argv[i]);


        i++;
    }
    return (NULL);
}
