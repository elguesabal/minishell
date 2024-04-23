#include "../minishell.h"

char	**unset(char **argv, t_str **env_list, char **env)
{
    (void)argv;
    (void)env_list;
    (void)env;
    printf("testando unset");
    return (NULL);

    // int i;
    // t_str   *assist;
    // t_str   *previous_assist;

    // i = 1;
	// while (argv[i])
    // {
    //     assist = *env_list;
    //     while (assist)
    //     {
    //         previous_assist = assist;
    //         assist = assist->next;
    //     }


    //     assist = *env_list;
    //     while (assist)
    //     {
    //         if (assist->next && assist->next->str)
    //         {
                
    //         }
    //     }




    //     i++;
    // }
}


// char **array = { "teste", "123", NULL, NULL };