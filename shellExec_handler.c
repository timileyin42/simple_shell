#include "main.h"

/**
 * exec_cmd - Function that creates a child process to execute a cmd
 *
 * @program: command that will be executed
 * @command: arguments of command
 * @env: current environment
 * @bash_s: struct with shell information
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match
 *
 */
int exec_cmd(char *program, char *command[], char **env, bash *bash_s)
{
	pid_t process, mode;
	int execve_id = 0, wait_id = 0;

	process = fork();
	signal(SIGINT, signal_handler2);
	if (process == -1)
	{
		write(STDERR_FILENO, "Fork Error", 10);
		exit(-1);
	}
	if (process == 0)
	{

		execve_id = execve(program, command, env);
		if (execve_id == -1)
		{
			_exit(-1);
		}
	}
	else
	{
		wait_id = wait(&mode);
		signal(SIGINT, signal_handler);
		if (wait_id == -1)
			exit(-1);
		if (WEXITSTATUS(mode) == 0)
			bash_s->exitnum[0] = 0;
		else
			bash_s->exitnum[0] = 2;
	}

	bash_s->errnum[0] = bash_s->errnum[0] + 1;
	return (0);
}
