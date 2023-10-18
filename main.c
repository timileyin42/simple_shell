#include "main.h"
/**
 * main - Shell Program
 * @ac: count of input parameters to program
 * @av: parameters as input to program
 * @env: unix environment
 *
 * Return: Should only exit through shell inputs
 */
int main(int ac, char **av, char **env)
{
	size_t bufsize = 0;
	char **command, *pathCmd, *buffer = NULL;
	bash *bash_s;
	int errn = 0, exnum = 0, relation = 0, run_able = 0, sizeEnv, enul = 0;
	ssize_t isBuiltIn;

	if (ac > 1 || av == NULL)
		write(2, "Please run with no arguments\n", 29), exit(127);
	signal(SIGINT, signal_handler);
	sizeEnv = _strlendp(env);
	env = double_cp(env, sizeEnv, sizeEnv);
	bash_s = loop_struct(av[0], &errn, &exnum, &relation, &run_able, &env, &enul);
	while (1)
	{
		command = NULL;
		command = shell_cmd(ac, av, &bufsize, &buffer, bash_s);
		if (command == NULL)
			continue;
		write_cmd(bash_s, buffer, command[0], command);
		isBuiltIn = built_ints(bash_s);
		if (isBuiltIn == -1 || isBuiltIn == 1)
			continue;
		pathCmd = path_fun(command[0], env, bash_s);
		shellPath_cmd(bash_s, pathCmd);
		if (pathCmd == NULL)
		{
			free(command);
			bash_s->errnum[0] += 1, error_fun(0, bash_s, 127);
			continue;
		}
		else if (access(pathCmd, X_OK) == -1)
			error_fun(1, bash_s, 126);
		else
			exec_cmd(pathCmd, command, env, bash_s);
		free(command);
		free(pathCmd);

	}
	free_doubpoint(*(bash_s->envCpy)), free(bash_s);
	return (0);
}
/**
 * loop_struct - initializes shell struct
 * @argv0: name of executable
 * @errn: number of error message
 * @exnum: exit number of shell
 * @relation: relation for logical operators
 * @run_able: if cmd should be run
 * @env: current environment
 * @unsetnull: check for setting environment to NULL
 *
 * Return: Pointer to struct
 *
 */
bash *loop_struct(char *argv0, int *errn, int *exnum,
		    int *relation, int *run_able, char ***env, int *unsetnull)
{
	bash *shell_run;

	shell_run = malloc(sizeof(struct bash));
	if (shell_run == 0)
		return (write(STDERR_FILENO, "Memory Error", 22), NULL);
	shell_run->hshname = argv0;
	shell_run->buffer = NULL;
	shell_run->cmd = NULL;
	shell_run->options = NULL;
	shell_run->path = NULL;
	shell_run->errnum = errn;
	shell_run->exitnum = exnum;
	shell_run->relation = relation;
	shell_run->run_able = run_able;
	shell_run->envCpy = env;
	shell_run->unsetnull = unsetnull;

	return (shell_run);
}
/**
 * write_cmd - adds values to shell struct
 * @bash_s: shell struct
 * @buffer: string written after prompt
 * @command: command written after prompt
 * @parameters: parameters of command
 *
 * Return: No return
 */
void write_cmd(bash *bash_s, char *buffer, char *command, char **parameters)
{
	bash_s->buffer = buffer;
	bash_s->cmd = command;
	bash_s->options = parameters;
}

/**
 * shellPath_cmd - initializes path value of struct
 * @bash_s: shell struct
 * @pathCmd: path of cmd written after propmpt
 *
 * Return: No Return
 */
void shellPath_cmd(bash *bash_s, char *pathCmd)
{
	bash_s->path = pathCmd;
}
