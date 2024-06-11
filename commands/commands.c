#include "../minishell.h"

void	commands(char *str, char **args, char ***argenv, t_str **env_list)
{
	if (declaration_variable(args[0]))
		add_variable(args, *argenv, env_list);
	else if (compare("echo", args[0]))
		echo(args, env_list);
	else if (compare("cd", args[0]))
		cd(str, *argenv, env_list);
	else if (compare("pwd", args[0]))
		pwd(env_list);
	else if (compare("export", args[0]))
		export(args, argenv, env_list);
	else if (compare("unset", args[0]))
		unset(args, env_list, *argenv);
	else if (compare("env", args[0]))
		env(*argenv, env_list);
	else if (compare("exit", args[0]))
		exit_shell(args, str, *argenv, env_list);
	else
		exec_program(args, *argenv, str, env_list);
}
