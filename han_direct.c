/**
 * getdir - Entry point
 *
 * Return: doble pointer to directories of the PATH
 */
char **getdir(void)
{
	int sp = 0, x = 0, z = 0, aux = 0, y = 0, flag = 1;
	int p = 0;
	char *path;
	char *var = "PATH";
	char **dir = NULL;

	path = _getenvvar(var);
	if (!path || path[0] == 0)
		return (NULL);
	sp = numdirectories(path);
	if (sp == 0)
		return (dir);
	dir = _calloc((sp + 1), sizeof(void *));
	dir[sp] = NULL;
	for (; x < sp; x++)
	{
		if (path[0] == ':' && flag)
		{
			dir[0] = currentpath();
			x++, y++;
			flag = 0; }
		aux = y;
		for (z = 0; path[y] && path[y] != ':'; y++, z++)
			;
		if (z == 0)
		{
			dir[x] = currentpath();
			y++;
			continue; }
		y++;
		dir[x] = _calloc(sizeof(char), (z + 2));
		for (p = 0; path[aux] && aux < 1024 && path[aux] != ':'; aux++, p++)
			*(dir[x] + p) = path[aux];
		*(dir[x] + p) = '/';
		p++;
		*(dir[x] + p) = 0;
		aux++;
		y = aux; }
	free(path);
	return (dir);
}

/**
 * current_dir - functions that help document of some functions.
 * @arg: node that has the builtin command
 *
 * Return: no return
 */
int current_dir(char **arg)
{
	char *py = NULL;
	int pos = 0, x = 0, fd = 0;

	py = currentpath();
	pos = aux_strlen(py);
	for (; arg[0][x]; x++)
		py[pos + x] = arg[0][x];
	fd = open(py, O_RDONLY);
	if (fd == -1)
	{
		free(py);
		return (-1);
	}
	free(arg[0]);
	arg[0] = py;
	close(fd);
	return (0);

}

/**
 * aux_strlen2 - Entry point
 *@s: pointer the string we want to now length
 *
 * Return: 0
 */
int aux_strlen2(char *s)
{
	int x;

	x = 0;
	while (*(s + x) != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * freedir - verfy operators.
 * @dir: array of arrays with directories
 * @arg:array with argumens
 *
 * Return: no returns
 */
void freedir(char **dir, char *arg)
{
	int x = 0;

	if (arg)
		free(arg);
	for (x = 0; dir[x]; x++)
		free(dir[x]);
	free(dir[x]);
	free(dir);
}


/**
 * clfun - sort out command.
 * @arg: command with arguments
 *
 * Return: 1 if is built in or 0 if its external function
 */
int  clfun(char **arg)
{
	char *com = NULL, *crtdir = NULL, *aux = NULL;
	char **dir = NULL;
	unsigned int x = 0, y = 0, la = 0;
	int res, fd = 0, found = 1;

	res = look(*arg);
	if (res == BUILT)
		return (BUILT);
	com = *arg;
	if (arg[0][0] == '.' && arg[0][1])
		return (current_dir(arg));
	if (*(*(arg + 0) + 0) == '/')
		return (0);
	dir = getdir();
	if (dir == NULL)
		return (-1);
	la = aux_strlen(com);
	la++;
	while (dir[x])
	{
		crtdir = dir[x];
		y = aux_strlen2(crtdir);
		aux = _calloc(sizeof(char), (la + y + 1));
		if (aux == NULL)
			return (0);
		aux = dirandcommand(crtdir, aux, com);
		fd = open(aux, O_RDONLY);
		if (fd != -1)
		{
			freedir(dir, *arg);
			*arg = aux;
			found = 0;
			close(fd);
			break; }
		x++;
		free(aux); }
	if (found)
	{
		freedir(dir, NULL);
		res = -1; }
	return (res); }
