#include "../minishell.h"

void	handle_sigint(int sign)
{
	(void)sign;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	handle_sigquit(int sign)
{
	(void)sign;
	printf("recebi sigquit");
}

void	check_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
