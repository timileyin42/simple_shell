#include "main.h"

/**
 * directory_check - checks ":" if it's present int the working directory.
 * @path: A pointer to the type char.
 * @x: Pointer pointing to the type of index.
 * Return: 1 if path is reachable in the wd, 0 if otherwise.
 */

int directory_check(char *path, int *x)
{
	if (path[*x] == ':')
		return (1);

	while (path[*x] != ':' && path[*x])
	{
		(*x)++;
	}

	if (path[*x])
		(*x)++;

	return (0);
}

/**
 * _which - Functions pointer that locate a command need by the terminal
 * @command: Command line name
 * @_environ: Environmnet variable
 * Return: Location of the command.
 */

char *_which(char *command, char **_environ)
{
	char *path, *pathptr, *tokenPath, *direct;
	int dir_len, cmd_len, x;
	struct stat fd;

	path = _getenv("PATH", _environ);
	if (path)
	{
		pathptr = _strdup(path);
		cmd_len = _strlen(cmd);
		tokenPath = _strtok(pathptr, ":");
		x = 0;
		for (; tokenPath != NULL; tokenPath = _strtok(NULL, ":"))
		{
			if (directory_check(path, &x))
			{
				if (stat(command, &fd) == 0)
					return (command);
			}
			dir_len = _strlen(tokenPath);
			direct = malloc(dir_len + cmd_len + 2);
			_strcpy(direct, tokenPath);
			_strcat(direct, "/");
			_strcat(direct, command);
			_strcat(dir, "\0");
			if (stat(direct, &fd) == 0)
			{
				free(pathptr);
				return (direct);
			}
			free(direct);
		} free(pathptr);
		if (stat(command, &fd) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
	{
		if (stat(command, &fd) == 0)
			return (command);
	} return (NULL);
}

/**
 * execute_fun - Functons that check if it's executable
 * @shell_op: A pointer to the data structure
 * Return: 0 if is not an executable, other number if otherwise
 */

int execute_fun(bash_shell *shell_op)
{
	struct stat fd;
	int x;
	char *input;

	input = shell_op->args[0];

	while (input[x])
	{
		if (input[x] == '.')
		{
			if (input[x + 1] == '.')
				return (0);
			if (input[x + 1] == '/')
				continue;
			else
				break;
		}
		else
			break;
		x++;
	}
	if (x == 0)
		return (0);
	if (stat(input + x, &st) == 0)
	{
		return (x);
	}
	error_fun(shell_op, 127);
	return (-1);
}

/**
 * error_command - functions that check if user is allowed to access
 * @direct: A pointer to the designated directory
 * @shell_op: A pointer to the type of data struture
 * Return: 1 if thier is an erro, 0 if not
 */

int error_command(char *direct, bash_shell *shell_op)
{
	if (direct == NULL)
	{
		error_fun(shell_op, 127);
		return (1);
	}

	if (_strcmp(shell_op->args[0], direct) != 0)
	{
		if (access(direct, X_OK) == -1)
		{
			error_fun(shell_op, 126);
			free(direct);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(shell_op->args[0], X_OK) == -1)
		{
			erro_fun(shell_op, 126);
			return (1);
		}
	}
	return (0);
}

/**
 * shell_exec - Function that executes the command lines
 * @shell_op: A pointer to the  data relevant (args and input)
 * Return: 1 on success.
 */

int shell_exec(bash_shell *shell_op)
{
	pid_t is_pid;
	pid_t w_pid;
	int mode, exec;
	char *direct;
	(void) w_pid;

	exec = execute_fun(shell_op);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		direct = _which(shell_op->args[0], shell_op->_environ);
		return (1);
	}
	is_pid = fork();
	if (is_pid == 0)
	{
		if (exec == 0)
			direct = _which(is_pid->args[0], shell_op->_environ);
		else
			direct = shell_op->args[0];
		execve(direct + exec, shell_op->, shell_op->_environ);
	}
	else if (is_pid < 0)
	{
		perror(shell_op->av[0]);
		return (1);
	}
	else
	{
		do {
			w_pid = waitpid(shell_pid, &mode, WUNTRACED);
		} while (!WIFEXITED(mode) && !WIFSIGNALED(node));
	}
	shell_op->mode = mode / 256;
	return (1);
}
