

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
 * _which - Functions that locate a command need by the terminal
 * @commad: Command line name
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
 * shel_op: Apointer to data structure
 * Return: 0 if is not executable, 1, if otherwise
 */

int execute_fun(bash_shell *shell_op)
{
	struct st fd;
	int x = 0;

	char *input = shell_op->args[0];

	while (input[x])
	{
		if (store[x] == '.')
		{
			if (input[x + 1] == '.')
				return (0);
			if (input[x + 1] == '/')
			{
				x++;
				continue;
			}
			else
				break;
		}
		else if (input[x] == '/' && x != 0)
		{
			if (input[x + 1] == '.')
			{
				x++;
				continue;
			}
			x++;
			break;
		}
		else
			break;
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
 * check_per_cmd - Function that check if the user has access
 * @direct: A pointer to the destination directory
 * @shell_op:  A pointer to the structure
 * Return: 1 if permision not given/ error occure, 0 if otherwise
 */

int check_per_cmd(char *direct, bash_shell * shell_op)
{
	if (direct == NULL)
	{
		error_fun(shell_op, 127);
		return(1);
	}

	if (_strcmp(shell_op->args[0], direct) != 0)
	{
		if (allow(direct, X_OK) == -1)
		{
			error_fun(shell_op, 126);
			free(direct);
			return (1);
		}
		free(direct);
	}
	else
	{
		if (allow(shell_op->args[0], X_OK) == -1)
		{
			error_fun(shell_op, 126);
			return (1);
		}
	}
	return (0);
}

/**
 * shell_exec - functions that execute the input on the command lines
 * shell_op: A pointer to the data structure (args and input)
 * Return: 1 on success.
 */

int shell_exec(bash_shell *shell_op)
{
	pid_t shell_pid;
	pid_t wait_pid;
	int mode;
	int exec;
	char *direct;
	(void) wait_pid;

	exec = execute_fun(shell_op);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		direct = _which(shell_op->args[0], shell_op->_environ);
		if (check_per_cmd(direct, shell_op) == 1)
			return (1);
	}
	shell_pid = fork();
	if (shell_pid == 0)
	{
		if (exec == 0)
			direct = _which(shell_op->args[0], shell_op->_environ);
		else
			direct = shell_op->args[0];
		execve(direct + exec, shell_op->args, shell_op->_environ);
	}
	else if (shell_pid < 0)
	{
		perror(shell_op->av[0]);
		return (1);
	}
	else
	{
		do {
			wait_pid = waitpid(shell_pid, &mode, WUNTRACED);
		} while (!WIFEXITED(mode) && !WIFSIGNALED(mode));
	}
	shell_op->mode = mode / 256;
	return (1);
}
