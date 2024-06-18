#include "../minishell.h"

void	handle_signal(int sign)
{
	(void)sign;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}
